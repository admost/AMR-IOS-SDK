//
//  AMRAd.h
//  AMRSDK
//
//  Created by Tolga Seremet on 31/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMRTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface AMRAd : NSObject
/// Set by the SDK once an ad loads; nil before that.
@property (nullable) NSString *adInfo;
@property NSInteger stickyRate;
/// Optional network-specific data set by the publisher.
@property (nullable) NSDictionary *networkData;
/// Optional placement ids to exclude from the waterfall.
@property (nullable) NSArray<NSString *> *excludedPlacementIds;
/// The ad's zone id (set at creation).
@property NSString *zoneId;
/// Set by the SDK once an ad loads; nil before that.
@property (nullable) NSString *placementId;
/// Set by the SDK once an ad loads; nil before that.
@property (nullable) NSString *adSpaceId;
@property AMRNetworkType networkType;
@property AMRBannerType bannerType;
/// Set by the SDK once an ad loads; nil before that.
@property (nullable) NSString *networkName;
/// Set by the SDK once an ad loads; nil before that.
@property (nullable) NSNumber *ecpm;
/// Optional tag set by the publisher when showing.
@property (nullable) NSString *tag;
@property (readonly) NSNumber *revenue;
@property (readonly) NSString *currency;
@end

NS_ASSUME_NONNULL_END
