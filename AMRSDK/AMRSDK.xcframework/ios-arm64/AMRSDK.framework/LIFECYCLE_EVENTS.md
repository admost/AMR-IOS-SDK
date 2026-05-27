# AMRSDK Lifecycle Events — Cross-Platform Spec

Bu dosya, AMRSDK lifecycle event'lerinin iOS implementation'ını ve Android'de paritesinin nasıl sağlanması gerektiğini anlatır. iOS referans implementasyonu: `AMRLifecycleEventsManager.m`.

## Genel mimari

- Tüm lifecycle event'leri `type: "lifecycle"` ile event queue'ya submit edilir.
- Event schema: `{ name, type, time_stamp (unix seconds), properties }`.
- **`session_index`** her event'in `properties`'ine otomatik inject edilir (1-based, monotonic, kullanıcı ömrü boyunca artar, persist).
- Tüm state mutasyonu **single serial executor** üzerinde (Android: `HandlerThread` veya `Executors.newSingleThreadExecutor()`).
- **Hiç swizzling / reflection yok**, sadece sistem callback'leri.
- Tüm SharedPreferences / UserDefaults okumaları defansif (type check + null check).
- Lifecycle manager `start` çağrısı **idempotent** — birden çok kez güvenle çağrılabilir.
- Gate: hem `EventsActive` hem (Android'de varsa equivalent flag) true olmalı.

## Persistent state (SharedPreferences / UserDefaults, namespaced)

| Key | Type | Açıklama |
|---|---|---|
| `AMRLifecycle.installVersion` | String | İlk install'daki app version (marker olarak da kullanılır) |
| `AMRLifecycle.installTimestamp` | long (unix sec) | Install zamanı |
| `AMRLifecycle.installTimestampSource` | String | `"package_first_install_time"` veya `"first_launch"` |
| `AMRLifecycle.lastSeenVersion` | String | En son görülen app version (update detection için) |
| `AMRLifecycle.sessionStartedAt` | long | Aktif session'ın başlangıcı, 0 = session yok |
| `AMRLifecycle.lastForegroundAt` | long | Son fg/bg transition timestamp'i |
| `AMRLifecycle.sessionIndex` | int | Toplam session sayısı, monotonic |
| `AMRLifecycle.installToFirstSessionDelayReported` | bool | Idempotency flag |

## Event listesi

### 1. `app_install`
- **Trigger:** Gerçek ilk-ever launch (SharedPreferences container boş + lifecycle marker yok).
- **Önemli:** Bu SDK'yı zaten kullanan kullanıcılar bu kodu ilk kez çalıştırırsa **emit ETMEMELI** (migration case). Android'de detect: SDK'nın daha önce kullanıldığını gösteren başka SharedPreferences key'leri varsa, bu user mevcut user demektir. iOS'ta `AMRUserDefaultsManager.startAndCheckIsNewInstall` ile yapıldı (initial defaults snapshot'ı boş muydu).
- **Properties:** `version`, `timestamp_source`
- **iOS API:** `NSBundle.bundleURL` file creation date.
- **Android:** `PackageManager.getPackageInfo(packageName, 0).firstInstallTime` — gerçek install anını döner (iOS yaklaşımından daha doğru). Source: `"package_first_install_time"`.

### 2. `app_update`
- **Trigger:** `lastSeenVersion ≠ currentVersion` (cold start'ta). Install ile **mutually exclusive** — install branch'ı çalışırsa update kontrolü yapılmaz.
- **Properties:** `from`, `to`
- **Android:** `BuildConfig.VERSION_NAME` veya `PackageInfo.versionName`.

### 3. `app_launch`
- **Trigger:** Her cold start (process başlatıldığında, `start` çağrısında).
- **Properties:** `version`

### 4. `session_start`
- **Trigger:** İlk cold launch'ta veya `now - lastForegroundAt > 30dk` ise foreground'da.
- **Önemli:** `session_index` cold launch'ta veya yeni session başlangıcında increment edilir ve persist.
- **Properties:** yok (session_index otomatik gelir)

### 5. `session_end`
- **Trigger:** **Lazy emit** — background'da DEĞİL. Sadece next foreground'da veya next cold launch'ta `now - lastForegroundAt > 30dk` tespit edildiğinde.
- **timestamp:** retroactive — `lastForegroundAt` kullanılır (event creation time DEĞİL).
- **Properties:** `duration_seconds`, `expired: true`
- **Sebep:** 5sn arka plana atıp dönen kullanıcı yeni session açmasın.

### 6. `app_foreground` / `app_background`
- **Trigger:** Her foreground/background transition. Session boundary mantığından bağımsız, ham event.
- **iOS:** `UIApplicationWillEnterForegroundNotification` / `UIApplicationDidEnterBackgroundNotification`
- **Android:** `ProcessLifecycleOwner.get().lifecycle` ile `ON_START` / `ON_STOP`. **`Activity.onPause` KULLANMA** — tekil activity transitions'ı yakalar, process-level değil.
- **Properties:** yok

### 7. `low_memory_warning`
- **iOS:** `UIApplicationDidReceiveMemoryWarningNotification`
- **Android:** `ComponentCallbacks2.onTrimMemory(level)` — `TRIM_MEMORY_RUNNING_CRITICAL` veya `TRIM_MEMORY_RUNNING_LOW` seviyelerini emit et. Veya `Application.onLowMemory()`.
- **Properties:** Android'de `level` ekleyebilirsin (iOS'ta seviye yok).

### 8. `thermal_state_change`
- **Trigger:** Termal durum değiştiğinde (sadece gerçek değişim, baseline'da emit yok).
- **iOS:** `NSProcessInfoThermalStateDidChangeNotification` → `nominal | fair | serious | critical`
- **Android (API 29+):** `PowerManager.OnThermalStatusChangedListener` → `THERMAL_STATUS_NONE | LIGHT | MODERATE | SEVERE | CRITICAL | EMERGENCY | SHUTDOWN`. iOS string'lerine map et veya kendi string'lerini kullan, ama dokümana yaz.
- **Properties:** `from`, `to`

### 9. `locale_change`
- **iOS:** `NSCurrentLocaleDidChangeNotification`. State karşılaştırması in-memory (cold start'ta baseline yakalanır, transition'larda emit).
- **Android:** `Intent.ACTION_LOCALE_CHANGED` broadcast receiver.
- **Properties:** `from`, `to` (örn: `"en_US"`, `"tr_TR"`)

### 10. `timezone_change`
- **iOS:** `NSSystemTimeZoneDidChangeNotification`
- **Android:** `Intent.ACTION_TIMEZONE_CHANGED` broadcast receiver.
- **Properties:** `from`, `to` (timezone identifier, örn: `"Europe/Istanbul"`)

### 11. `network_change`
- **Trigger:** Network status değişiminde (offline/wifi/cellular).
- **iOS:** Reachability API + `kAMRAppleNetworkReachabilityChangedNotification`. In-memory `lastStatus` ile karşılaştır.
- **Android:** `ConnectivityManager.registerDefaultNetworkCallback(NetworkCallback)`. State: `NetworkCapabilities.TRANSPORT_WIFI | TRANSPORT_CELLULAR` ve `onLost()` = offline.
- **Properties:** `from`, `to` — string değerler: `"offline"`, `"wifi"`, `"cellular"` (cross-platform tutarlı tut).

### 12. `install_to_first_session_delay`
- **Trigger:** İlk session_start'ta, sadece bir kez (idempotency flag).
- **Önemli:** Sadece **gerçek yeni install**'da emit. Mevcut user migration case'inde skip (flag preemptively set edilir).
- **Properties:** `delay_seconds`, `source`
- **iOS source:** `bundle_creation_date` veya `first_launch`.
- **Android source:** `package_first_install_time` (PackageManager) — daha doğru, iOS'tan iyi durumdasın bu metrikte.

## Önemli davranış kuralları

1. **30 dakika idle = session boundary.** Sabit: `1800` saniye. Background'a düşmek session'ı bitirmez; sadece 30dk'dan uzun süre dönmemek bitirir.

2. **Install ↔ Update mutex.** Cold launch'ta önce install kontrolü, sonra (else dalında) update kontrolü. İkisi aynı anda emit edilmez.

3. **Migration safety.** SDK'nın bu lifecycle versiyonunu ilk kez çalıştıran mevcut user'lar için `app_install` ve `install_to_first_session_delay` emit edilmez, ama state marker'ları yazılır ki sonraki açılışlar normal çalışsın.

4. **`session_index` her event'e otomatik.** Event manager submit pipeline'ında, lifecycle / custom / network / screen_view fark etmez — tümüne `properties.session_index = N` inject. Server tarafında session bazlı funnel sorgularını ucuza yapmayı sağlar. `first_session_duration` ayrı event olarak tutulmaz — server `session_index == 1` filter'ı ile aynı bilgiyi alır.

5. **State değişim event'lerinde baseline emit yok.** thermal / locale / timezone / network: ilk açılışta sadece baseline değer in-memory'e alınır, event yok. Sonraki gerçek transition'larda emit.

6. **Defansif persistence.** Her SharedPreferences read'i tipi doğrula, parse hatalarını swallow et. Kazara corrupt key'ler app'i crash etmemeli.

7. **Crash safety.** Lifecycle manager hiçbir koşulda host app'i crash ettirmemeli. Tüm callback'leri try/catch ile sar (özellikle Android'de exception propagation daha agresif).

## iOS implementasyon referansları

- Manager: `AMRSDK/EventTracking/AMRLifecycleEventsManager.m`
- Event helper: `AMRSDK/EventTracking/AMREventManager.m` → `+trackLifecycleEvent:parameters:` ve `+trackLifecycleEvent:parameters:timestamp:`
- session_index injection: `AMREventManager.m` → `-decorateProperties:` her event-build path'inde çağrılır.
- Init wiring: `AMRSDK/Core/Manager/AMRAdapterManager.m`, `application.metaData.isEventsActive` true ise `[AMRLifecycleEventsManager start]` çağrılır.
