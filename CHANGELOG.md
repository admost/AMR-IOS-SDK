# Changelog

Changelog for AMRSDK.

## [1.5.95-beta.1] - 2026-06-18
### Added (pre-release / test only)
- Automatic `notification_open` lifecycle event: detects when the app is opened by tapping a notification, by observing (not owning) the host's `UNUserNotificationCenter` delegate. Crash-safe (fully guarded, fails silently) with a self-healing boot-time crash guard.
- **Pre-release build only:** notification tracking defaults to ON in this `-beta` so test apps activate it without a server flag. Stable releases keep it OFF (remote `NotificationTrackerEnabled` opt-in). Not picked up by stable CocoaPods/SPM version rules.

## [1.5.94] - 2026-06-02
### Added
- Socket request tracking API (`+trackSocketRequestWithURL:method:startTime:duration:statusCode:requestPayloadSize:responsePayloadSize:error:`), emitting `socket_request` events.

## [1.5.93] - 2026-05-29
### Fixed
- `AMRResources.bundle` was packaged from a simulator (`iPhoneSimulator`) build in 1.5.92, causing App Store validation to fail with "Invalid CFBundleSupportedPlatforms value". Replaced with the device (`iPhoneOS`) bundle. No code or binary changes.

## [1.5.92] - 2026-05-27
### Added
- HTTP request tracking API (`+trackHTTPRequestWithURL:method:startTime:duration:statusCode:requestPayloadSize:responsePayloadSize:error:` and `+startHTTPRequestTraceWithURL:method:`).
- Automatic lifecycle events (app_install, app_update, app_launch, session_start, session_end, app_foreground, app_background, low_memory_warning, thermal_state_change, locale_change, timezone_change, network_change, install_to_first_session_delay).
- `session_index` auto-injected into all event properties.
- Disk-persisted batched event uploader with at-most-once delivery.
- Soft-binding to AMRNetworkSDK (`AutoNetworkTrackerEnabled` remote config flag).

## [1.5.90] - 2026-05-15
### Updated
- Nested JSON support added for remote config.

## [1.5.89] - 2026-04-28
### Updated
- iOS13 crashes fixed.

## [1.5.88] - 2026-04-25
### Updated
- Merge remote config added for experiments.

## [1.5.87] - 2026-04-19
### Updated
- UserDefaults crashes fixed.

## [1.5.85] - 2026-04-03
### Updated
- BuyerID check added.

## [1.5.84] - 2026-03-18
### Updated
- SPM support added.

## [1.5.79] - 2026-03-02
### Updated
- Official release for AMRSDK 1.5.79
