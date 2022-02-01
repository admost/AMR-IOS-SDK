//
//  AMRRewardedVideoDelegate.h
//  AMRSDK
//
//  Created by Tolga Seremet on 26/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

@class AMRRewardedVideo, AMRError;

/**
 * @protocol AMRRewardedVideoDelegate
 * @brief The AMRRewardedVideoDelegate protocol.
 * This protocol is used as a delegate for rewarded video events.
 */
@protocol AMRRewardedVideoDelegate <NSObject>

/**
 * Successfully received a rewarded video. Call AMRRewardedVideo's showFromViewController method to start rewarded video.
 * Example usage:
 * @code
 * [rewardedVideo showFromViewController:myViewController];
 * @endcode
 * @param rewardedVideo AMRRewardedVideo object to show.
 */
- (void)didReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * Failed to receive an rewarded video. Inspect AMRError's errorCode and errorDescription properties to identify the problem.
 * @param rewardedVideo Failed AMRRewardedVideo object.
 * @param error AMRError object with error code and descriptions.
 */
- (void)didFailToReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo error:(AMRError *)error;

@optional

/**
 * Successfully shown received rewarded video.
 * @param rewardedVideo Shown AMRRewardedVideo object.
 */
- (void)didShowRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * Failed to show rewarded video. This delegate expected to be called very rarely.
 * @param rewardedVideo Failed AMRRewardedVideo object.
 * @param error AMRError object with error code and descriptions.
 */
- (void)didFailToShowRewardedVideo:(AMRRewardedVideo *)rewardedVideo error:(AMRError *)error;

/**
 * @deprecated This method is deprecated starting in version 1.3.84
 * Failed to show rewarded video. This delegate expected to be called very rarely.
 * @param rewardedVideo Failed AMRRewardedVideo object.
 */
- (void)didFailToShowRewardedVideo:(AMRRewardedVideo *)rewardedVideo __attribute__((deprecated));

/**
 * User clicked rewarded video.
 * @param rewardedVideo Clicked AMRRewardedVideo object.
 */
- (void)didClickRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * User watched rewarded video till end. User can get the reward.
 * @param rewardedVideo AMRRewardedVideo object.
 */
- (void)didCompleteRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * Presented rewarded video is dismissed. Continue stopped tasks while the rewardedvideo ad is present. Called after didCompleteRewardedVideo delegate callback.
 * @param rewardedVideo Dismissed AMRRewardedVideo object.
 */
- (void)didDismissRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * Rewarded video state changed.
 * @param rewardedVideo AMRRewardedVideo object.
 * @param state AMRRewardedVideo new state.
 */
- (void)didRewardedVideoStateChanged:(AMRRewardedVideo *)rewardedVideo state:(AMRAdState)state;

@end
