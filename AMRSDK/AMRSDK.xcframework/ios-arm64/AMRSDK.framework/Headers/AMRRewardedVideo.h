//
//  AMRRewardedVideo.h
//  AMRSDK
//
//  Created by Tolga Seremet on 26/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMRSDK.h"

@class AMRAd, UIViewController;

@interface AMRRewardedVideo : AMRAd

/// An object conforms to <AMRRewardedVideoDelegate> protocol.
@property (weak) id<AMRRewardedVideoDelegate> delegate;
/// Returns YES if the rewarded video is requested.
@property (nonatomic, readonly) BOOL isLoading;
/// Returns YES if the rewarded video is loaded.
@property (nonatomic, readonly) BOOL isLoaded;
/// Returns YES if the interstitial is ready to show. (loaded + capping free)
@property (nonatomic, readonly) BOOL isReadyToShow;

/// Parameter to move your custom data.
@property (nonatomic, strong) NSDictionary *customData;

/// Parameter to set reward amount.
@property (nonatomic, assign) CGFloat completionReward;

/// Server Key for server to server.
@property (nonatomic, strong) NSString *ssvServerKey;

/**
 * Create an instance of AMRRewardedVideo to show in your application.
 * Example usage:
 * @code
 * [AMRRewardedVideo rewardedVideoForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param zoneId Your rewardedvideo's zone ID displayed on AMR Dashboard.
 * @return An instance of AMRRewardedVideo created by zoneId provided.
 */
+ (instancetype)rewardedVideoForZoneId:(NSString *)zoneId;

/**
 * Start rewardedvideo load request. Delegate must be set before loading an rewardedvideo.
 * Example usage:
 * @code
 * [rewardedVideo loadRewardedVideo];
 * @endcode
 */
- (void)loadRewardedVideo;

/**
 * Use to show rewardedvideo after delegate callback of AMRRewardedVideoDelegate's didReceiveRewardedVideo method.
 * Example usage:
 * @code
 * [rewardedVideo showFromViewController:myViewController];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param viewController Your rewardedvideo's presenting viewcontroller.
 */
- (void)showFromViewController:(UIViewController * )viewController;

/**
 * Use to show rewardedvideo after delegate callback of AMRRewardedVideoDelegate's didReceiveRewardedVideo method.
 * Example usage:
 * @code
 * [rewardedVideo showFromViewController:myViewController withTag:@"<myTag>"];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param viewController Your rewardedvideo's presenting viewcontroller.
 * @param tag Distinction value for ads that used in multiple purposes.
 */
- (void)showFromViewController:(UIViewController * )viewController withTag:(NSString *)tag;

@end
