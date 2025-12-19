//
//  AMRAd.h
//  AMRSDK
//
//  Created by Tolga Seremet on 31/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMRTypes.h"

@interface AMRAd : NSObject
@property NSString *adInfo;
@property NSInteger stickyRate;
@property NSDictionary *networkData;
@property NSArray<NSString *> *excludedPlacementIds;
@property NSString *zoneId;
@property NSString *placementId;
@property NSString *adSpaceId;
@property AMRNetworkType networkType;
@property AMRBannerType bannerType;
@property NSString *networkName;
@property NSNumber *ecpm;
@property NSString *tag;
@property (readonly) NSNumber *revenue;
@property (readonly) NSString *currency;
@end
