//
//  AMRSDK.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "AMRTypes.h"
#import "AMRError.h"
#import "AMRAd.h"
#import "AMRBannerDelegate.h"
#import "AMRBanner.h"
#import "AMRBannerView.h"
#import "AMRInterstitialDelegate.h"
#import "AMRInterstitial.h"
#import "AMRRewardedVideoDelegate.h"
#import "AMRRewardedVideo.h"
#import "AMROfferWallDelegate.h"
#import "AMROfferWall.h"
#import "AMRNativeAdBaseView.h"
#import "AMRUserExperiment.h"
#import "AMRRemoteConfigValue.h"

typedef void(^AMRInitCompletionHandler)(AMRError *_Nullable error);

@protocol AMRVirtualCurrencyDelegate, AMRTrackPurchaseResponseDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface AMRSDK : NSObject

/**
 * Start AMRSDK with your application ID displayed on AMR Dashboard.
 * Example usage:
 * @code
 * [AMRSDK startWithAppId:@"<appId>"];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param appId Your application ID.
 */
+ (void)startWithAppId:(NSString *)appId;

/**
 * Start AMRSDK with your application ID displayed on AMR Dashboard.
 * @see https://admost.github.io/amrios for more information.
 * @param appId Your application ID.
 * @param completion Completion block for init response.
 */
+ (void)startWithAppId:(NSString *)appId completion:(_Nullable AMRInitCompletionHandler)completion;

/**
 * Start AMRSDK with your application ID displayed on AMR Dashboard and use initNetworks bool value to control network initialization.
 * Example usage:
 * @code
 * [AMRSDK startWithAppId:@"<appId>"];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param appId Your application ID.
 * @param initNetworks Bool value to control network initialization
 * @note Please use @code startWithAppId: @endcode instead.
 */

+ (void)startWithAppId:(NSString *)appId shouldInitNetworks:(BOOL)initNetworks __attribute__((deprecated));

/**
 * Init networks to start cacheing banners.
 * Example usage:
 * @code
 * [AMRSDK initNetworks];
 * @endcode
 */

+ (void)initNetworks;

/**
 * Set logging level of AMRSDK.
 * Default value is AMRLogLevelAll which logs everything.
 * Example usage:
 * @code
 * [AMRSDK setLogLevel:AMRLogLevelInfo];
 * @endcode
 * @see AMRTypes.h for more information.
 * @param logLevel Level of log.
 */
+ (void)setLogLevel:(AMRLogLevel)logLevel;

/**
 * Set this value to YES to clear cache on application termination.
 * Default value is NO.
 * Following file types will be deleted from application's cache folder.
 * [@"mp4", @"m4v", @"jpg", @"jpeg", @"png", @"gif", @"svg", @"ttf", @"js", @"css", @"html", @"htm"].
 * @code
 * [AMRSDK setClearCacheOnTerminate:YES];
 * @endcode
 * @param shouldClear boolean value to clear cache on application termination.
 */

+ (void)setClearCacheOnTerminate:(BOOL)shouldClear;

/// Get current SDK version
+ (NSString *)SDKVersion;

/**
 * You can optionally provide a unique user id for reporting purposes.
 * This provided user id will be associated with the AMR User in AMR Dashboard.
 * Example usage:
 * @code
 * [AMRSDK setUserId:@"myUniqueUserId"];
 * @endcode
 * @param userId unique id.
 */
+ (void)setUserId:(NSString *)userId;

/**
* @deprecated This method is deprecated starting in version 1.3.35
* @note AMRSDK gets AdjustUserId automatically.
*/
+ (void)setAdjustUserId:(NSString *)adjustUserId __attribute__((deprecated));

/**
 * You can optionally provide a campaign id.
 * @param campaignId campaign id.
 */
+ (void)setClientCampaignId:(NSString *)campaignId;

/**
 * You can optionally pass data to Ad networks.
 * @param value object you want to pass.
 * @param key key for value.
 */
+ (void)setNetworkExtras:(id)value forKey:(AMRNetworkExtras)key;

/**
 * You can optionally pass userChild parameter to Ad networks.
 * @param userChild object you want to pass.
 */
+ (void)setUserChild:(BOOL)userChild;

/**
 * useHttps is in closed beta and available invite only.
 * @param useHttps object to force sdk to make https requests.
 */
+ (void)setUseHttps:(BOOL)useHttps;

/**
 * Get user data in JSON format after AMRSDK initialization.
 */
+ (NSString *)userData;

/**
 * Get user experiment data after AMRSDK initialization.
 */
+ (AMRUserExperiment *)userExperiment;

/**
 * Set virtual currenct delegate for virtual currency events.
 * Virtual currency delegate must be set before using offerwalls.
 * @param delegate An object conforms to <AMRVirtualCurrencyDelegate> protocol.
 */
+ (void)setVirtualCurrencyDelegate:(id<AMRVirtualCurrencyDelegate>)delegate;

/**
 * Start spending virtual currencies.
 * Virtual currency delegate must be set before starting to spend virtual currencies.
 */
+ (void)spendVirtualCurrency;

/**
 * @deprecated This method is deprecated starting in version 1.3.10
 * @note Please use @code trackPurchase:idientifier:currencyCode:amount @endcode instead.
 */
+ (void)trackPurchase:(NSString *)identifier
         currencyCode:(NSString *)currencyCode
               amount:(double)amount
              receipt:(NSData *)receipt __attribute__((deprecated));

/**
 * Track purchase.
 * @param identifier Transaction identifier of SKPaymentTransaction
 * @param currencyCode Currency code of transaction
 * @param amount Amount of transaction
 */
+ (void)trackPurchase:(NSString *)identifier
         currencyCode:(NSString *)currencyCode
               amount:(double)amount;

/**
 * Track in-app purchase is in closed beta and available invite only.
 * @param identifier Transaction identifier of SKPaymentTransaction
 * @param currencyCode Currency code of transaction
 * @param amount Amount of transaction
 * @param tags Distinction value for in-app purchase that used in multiple purposes.
 */
+ (void)trackIAP:(NSString *)identifier
    currencyCode:(NSString *)currencyCode
          amount:(double)amount
            tags:(NSArray *)tags;

/**
 * Set track purchase response delegate for track purchase upload responses.
 * @param delegate An object conforms to <AMRTrackPurchaseResponseDelegate> protocol.
 */
+ (void)setTrackPurchaseResponseDelegate:(id<AMRTrackPurchaseResponseDelegate>)delegate;

/**
 * @deprecated This method is deprecated please use startTesterInfoWithAppId method instead.
 */
+ (void)startTestSuiteWithAppId:(NSString *)appId __attribute__((deprecated));

/**
 * @deprecated This method is deprecated please use startTesterInfoWithAppId method instead.
 */
+ (void)startTestSuiteWithZones:(NSArray *)zones __attribute__((deprecated));

/**
 * Start Tester Info
 * You must be a Tester to show Tester Info on devices.
 * @param appId Your application ID.
 */
+ (void)startTesterInfoWithAppId:(NSString *)appId;

/**
 * @deprecated This method is deprecated please use isPrivacyConsentRequired method instead.
 * You can optionally use isGDPRApplicable method to obtain the user is in a GDPR required country.
 */

+ (void)isGDPRApplicable:(void (^)(BOOL isGDPRApplicable))completion __attribute__((deprecated));

/**
 * You can optionally use isPrivacyConsentRequired method to obtain the user is in a GDPR or CCPA required country.
 */

+ (void)isPrivacyConsentRequired:(void (^)(AMRPrivacyConsentStatus consentStatus))completion;

/**
 * We specified your responsibilities for obtaining consent from end-users of your apps in our updated Privacy Policy.
 * By updating GDPR or CCPA compatible SDK you agree that you’re responsible for inform the end users and take their consent.
 * Please note that the GDPR consent collection applies only to users located in the European Economic Area, the United Kingdom, and Switzerland.
 * Please note that the CCPA consent collection applies only to users located in the California..
 * The setUserConsent method takes either NO (user does not consent) or YES (user does consent).
 * @param consent of the user.
 */
+ (void)setUserConsent:(BOOL)consent;

/**
 * We specified your responsibilities for obtaining consent from end-users of your apps in our updated Privacy Policy.
 * By updating GDPR or CCPA compatible SDK you agree that you’re responsible for inform the end users and take their consent.
 * Please note that the GDPR consent collection applies only to users located in the European Economic Area, the United Kingdom, and Switzerland.
 * Please note that the CCPA consent collection applies only to users located in the California..
 * The setTCFConsent method takes either NO (user does not consent) or YES (user does consent).
 * @param vendors consent of the user for vendors.
 */
+ (void)setTCFVendors:(NSDictionary *)vendors;

/**
 * You can optionally use subjectToGDPR method to set GDPR applicable to the user or not.
 * If you do not provide this information AMRSDK will use its own methods.
 * @param subject for GDPR.
 */
+ (void)subjectToGDPR:(BOOL)subject;

/**
 * You can optionally use subjectToCCPA method to set CCPA applicable to the user or not.
 * If you do not provide this information AMRSDK will use its own methods.
 * @param subject for GDPR.
 */
+ (void)subjectToCCPA:(BOOL)subject;

/**
 * You can optionally use updateATTStatus method to set ATT status after permisson request.
 * If you do not provide this information AMRSDK will use its own methods.
 */
+ (void)updateATTStatus;

/**
 * You can optionally use fetchRemoteConfigWithCompletion method to fetch remote config from server.
 */
+ (void)fetchRemoteConfigWithCompletion:(void(^)(AMRError *))completion;

/**
 * You can optionally use getConfigForKey method to get remote config value.
 * * @param key for remote config value.
 */
+ (nullable AMRRemoteConfigValue *)getConfigForKey:(nonnull NSString *)key;

+ (BOOL)isStatusBarHidden __attribute__((deprecated));
+ (BOOL)isInitNetworks __attribute__((deprecated));
+ (void)preloadBannersWithZoneIds:(NSArray *)zoneIds __attribute__((deprecated));
+ (void)setStatusBarHidden:(BOOL)isHidden __attribute__((deprecated));
@end

/**
 * @protocol AMRVirtualCurrencyDelegate
 * @brief The AMRVirtualCurrencyDelegate protocol.
 * This protocol is used as a delegate for virtual currency events.
 */
@protocol AMRVirtualCurrencyDelegate <NSObject>

/**
 * Successfully spent virtual currency.
 * @param amount Amount of virtual currency.
 * @param currency Currency of virtual currency.
 * @param networkName Network name of cirtual currency ad network.
 */
- (void)didSpendVirtualCurrency:(NSString *)currency
                         amount:(NSNumber *)amount
                    networkName:(NSString *)networkName;

@optional
/**
 * @deprecated This method is deprecated starting in version 1.3.64
 * @note Please use @code didSpendVirtualCurrency:currency:amount:networkName @endcode instead.
 */
- (void)didSpendVirtualCurrency:(NSString *)currency
                          amout:(NSNumber *)amount
                        network:(AMRNetworkType)network __attribute__((deprecated));

@end

@protocol AMRTrackPurchaseResponseDelegate <NSObject>

@optional
/**
 * Response for trackPurchase method.
 * @param identifier Transaction identifier of SKPaymentTransaction
 * @param status response status of in app purchase.
 */
- (void)trackPurchaseResponse:(NSString *)identifier status:(AMRTrackPurchaseResponseStatus)status;

@end

NS_ASSUME_NONNULL_END
