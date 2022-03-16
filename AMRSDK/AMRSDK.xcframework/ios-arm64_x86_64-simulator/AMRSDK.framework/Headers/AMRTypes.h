//
//  AMRTypes.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#ifndef AMRTypes_h
#define AMRTypes_h

#import <Foundation/Foundation.h>

/** Log levels of AMRSDK. */

typedef NS_ENUM(NSInteger, AMRLogLevel){
    /// No logs
    AMRLogLevelSilent = 0,

    /// All errors logged
    AMRLogLevelError = 1,

    /// All errors and warnings logged
    AMRLogLevelWarning = 2,

    /// All errors, warnings and infos logged
    AMRLogLevelInfo = 3,

    /// ALL errors, warnings, 3rd party logs and infos logged
    AMRLogLevel3rdParty = 4,

    /// All logged, default
    AMRLogLevelAll = 99
};

/** Banner sizes to use with AMRBanner. */

typedef NS_ENUM(NSInteger, AMRBannerSize){
    /// 320+ x 50
    AMRBannerSizeHeight50 = 0,

    /// 728+ x 90 (Tablet Size)
    AMRBannerSizeHeight90,

    /// 300+ x 250
    AMRBannerSizeHeight250,
};

/** Network Types of AMRSDK. */

typedef NS_ENUM(NSInteger, AMRNetworkType){
    /// NO NETWORK
    AMRNetworkTypeNoNetwork = 0,

    /// ADCOLONY
    AMRNetworkTypeAdColony,

    /// ADFALCON
    AMRNetworkTypeAdFalcon,

    /// ADMOB
    AMRNetworkTypeAdMob,

    /// ADMOST
    AMRNetworkTypeAdMost,

    /// ADTIMING
    AMRNetworkTypeAdtiming,
    
    /// ADX
    AMRNetworkTypeAdX,
    
    /// AFA
    AMRNetworkTypeAFA,

    /// AMAZON
    AMRNetworkTypeAmazon,

    /// APPLOVIN
    AMRNetworkTypeApplovin,

    /// APPNEXT
    AMRNetworkTypeAppnext,
    
    /// AVOCARROT
    AMRNetworkTypeAvocarrot,

    /// CHARTBOOST
    AMRNetworkTypeChartboost,

    /// CONVERSANT
    AMRNetworkTypeConversant,

    /// CROSS PROMOTION
    AMRNetworkTypeCrossPromotion,

    /// FACEBOOK
    AMRNetworkTypeFacebook,

    /// FLURRY
    AMRNetworkTypeFlurry,

    /// FLYMOB
    AMRNetworkTypeFlymob,

    /// FYBER
    AMRNetworkTypeFyber,
    
    /// GLISPA
    AMRNetworkTypeGlispa,

    /// HYPERADS
    AMRNetworkTypeHyper,

    /// INLOCO
    AMRNetworkTypeInloco,

    /// INMOBI
    AMRNetworkTypeInMobi,
    
    /// INNERACTIVE
    AMRNetworkTypeInneractive,
    
    /// IRONSOURCE
    AMRNetworkTypeIronsource,
    
    /// LEADBOLT
    AMRNetworkTypeLeadbolt,
    
    /// LIFTOFF
    AMRNetworkTypeLiftoff,

    /// LOOPME
    AMRNetworkTypeLoopme,

    /// MILLENIAL
    AMRNetworkTypeMillenial,

    /// MOBFOX
    AMRNetworkTypeMobfox,

    /// MOBUSI
    AMRNetworkTypeMobusi,

    /// MOPUB
    AMRNetworkTypeMopub,

    /// NATIVEX
    AMRNetworkTypeNativeX,
    
    /// NEXTAGE
    AMRNetworkTypeNexAge,
    
    /// OGURY
    AMRNetworkTypeOgury,
    
    /// POLLFISH
    AMRNetworkTypePollfish,

    /// PREMIUM
    AMRNetworkTypePremium,
    
    /// PUBNATIVE
    AMRNetworkTypePubNative,

    /// REVMOB
    AMRNetworkTypeRevMob,

    /// SMAATO
    AMRNetworkTypeSmaato,

    /// STARTAPP
    AMRNetworkTypeStartApp, 

    /// SUPERSONIC
    AMRNetworkTypeSupersonic,

    /// TAPJOY
    AMRNetworkTypeTapjoy,
    
    /// TAPPX
    AMRNetworkTypeTappx,

    /// UNITY
    AMRNetworkTypeUnityAds,

    /// VUNGLE
    AMRNetworkTypeVungle,
    
    /// SMART AD SERVER
    AMRNetworkTypeSmartAdServer,
    
    /// YOUAPPI
    AMRNetworkTypeYouappi,

    /// APPSAMURAI
    AMRNetworkTypeAppsamurai,

    /// MINTEGRAL
    AMRNetworkTypeMintegral,

    /// MY TARGET
    AMRNetworkTypeMyTarget,

    /// YANDEX
    AMRNetworkTypeYandex,

    /// TAPRESEARCH
    AMRNetworkTypeTapResearch,
    
    /// QUMPARA
    AMRNetworkTypeQumpara,
    
    /// TIKTOK
    AMRNetworkTypeTikTok,
    
    /// CRITEO
    AMRNetworkTypeCriteo,
    
    /// HYPRMX
    AMRNetworkTypeHyprMX,
    
    /// A4G
    AMRNetworkTypeA4G,
    
    /// ADVIEW
    AMRNetworkTypeAdView,
    
    /// REKLAMUP
    AMRNetworkTypeReklamUP,
    
    /// ADREACT
    AMRNetworkTypeAdreact,
    
    /// VERIZON
    AMRNetworkTypeVerizon,
    
    /// NOKTA
    AMRNetworkTypeNokta,
    
    /// ADTRUE
    AMRNetworkTypeAdtrue,
    
    /// COMMIT
    AMRNetworkTypeCommit,
    
    /// ADIPOLO
    AMRNetworkTypeAdipolo,

    /// MADVERTISE
    AMRNetworkTypeMadvertise
};

typedef NS_ENUM(NSInteger, AMRReachabilityNetworkStatus){
    /// Not reachable
    AMRReachabilityNetworkStatusNotReachable = 0,

    /// Reachable via Wireless LAN
    AMRReachabilityNetworkStatusViaWifi,

    /// Reachable via Wireless Wide Area Network
    AMRReachabilityNetworkStatusViaWWAN,
};

typedef NS_ENUM(NSInteger, AMRTrackPurchaseResponseStatus){
    /// In app purchase uploaded successfuly
    AMRTrackPurchaseResponseStatusSuccess = 0,

    /// In app purchase upload failed, AMRSDK will try to upload again.
    AMRTrackPurchaseResponseStatusFail = 1,

    /// Invalid in app purchase
    AMRTrackPurchaseResponseStatusException
};

typedef NS_ENUM(NSInteger, AMRNetworkExtras){
    /// Unknown parameter
    AMRNetworkExtrasUnknown = 0,
    
    /// AdMob - tagForChildDirectedTreatment
    AMRNetworkExtrasAdMobTagForChildDirectedTreatment = 1,
    
    /// AdMob - tagForUnderAgeOfConsent
    AMRNetworkExtrasAdMobTagForUnderAgeOfConsent = 2
};

typedef NS_ENUM(NSInteger, AMRPrivacyConsentStatus) {
    /// Consent not required.
    AMRPrivacyConsentStatusNone = 0,
    
    /// GDPR consent required.
    AMRPrivacyConsentStatusGDPR = 1,
    
    /// CCPA consent required.
    AMRPrivacyConsentStatusCCPA = 2
};

typedef NS_ENUM(NSInteger, AMRAdState) {
    /// Ad state is unknown.
    AMRAdStateUnknown = 0,
    
    /// Frequency cap is finished.
    AMRAdStateFrequencyCapFinished = 1
};

#endif /* AMRTypes_h */
