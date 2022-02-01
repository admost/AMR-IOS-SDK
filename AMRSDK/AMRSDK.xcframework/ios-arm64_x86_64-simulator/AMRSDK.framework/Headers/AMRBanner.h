//
//  AMRBanner.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "AMRBannerView.h"
#import "AMRTypes.h"
#import "AMRSDK.h"

@interface AMRBanner : AMRAd

/// An object conforms to <AMRBannerDelegate> protocol.
@property (weak) id<AMRBannerDelegate> delegate;
/// A UIView to add as a subview to show banner.
@property AMRBannerView *bannerView;
/// A parent UIViewController required to catch taps.
@property UIViewController *viewController;
/// Width value of banner, default is 320px for 50px, 300px for 250px, 728px for 90px.
@property (nonatomic) CGFloat bannerWidth;
/// Custom size for custom native ads.
@property (nonatomic) CGSize customNativeSize;
/// Custom native ad xib name.
@property NSString *customeNativeXibName;
/// Adaptive banner info.
@property (readonly) BOOL isAdaptiveEnabled;
/// Actual size of bannerView object after banner is loaded.
@property (nonatomic, assign, readonly) CGSize bannerSize;

/**
 * Create an instance of AMRBanner to show in your application.
 * Example usage:
 * @code
 * [AMRBanner bannerForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param zoneId Your banner's zone ID displayed on AMR Dashboard.
 * @return An instance of AMRBanner created by zoneId provided.
 */
+ (instancetype)bannerForZoneId:(NSString *)zoneId;

/**
 * Start asynchronous banner loading request. Delegate must be set before loading a banner ad.
 * Example usage:
 * @code
 * [banner loadBanner];
 * @endcode
 */
- (void)loadBanner;

/**
 * Start asynchronous banner loading request. Delegate must be set before loading a banner ad.
 * Example usage:
 * @code
 * [banner loadBannerWithTag:@"MY_TAG"];
 * @endcode
 * @param tag Distinction value for ads that used in multiple purposes.
 */
- (void)loadBannerWithTag:(NSString *)tag;


/**
 * Start synchronous banner loading request.
 * Example usage:
 * @code
 * [_banner50 loadWithReceiveHandler:^(AMRBanner *banner) {
 *     [self.view addSubview:banner.bannerView];
 * } failHandler:^(AMRError *error) {
 *     NSLog(@"Failed with error: %@", error.description);
 * }];
 * @endcode
 */
- (void)loadWithReceiveHandler:(void (^)(AMRBanner *banner))receive
                   failHandler:(void (^)(AMRError *error))fail;

// start caching banner
- (void)cacheBanner;

@end
