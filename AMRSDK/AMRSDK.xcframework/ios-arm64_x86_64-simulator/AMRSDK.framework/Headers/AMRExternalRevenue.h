//
//  AMRExternalRevenue.h
//  AMRSDK
//
//  Created by Mehmet Karagöz on 8.06.2023.
//  Copyright © 2023 Admost. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AMRExternalRevenueAdFormat) {
    AMRExternalRevenueAdFormatInterstitial,
    AMRExternalRevenueAdFormatRewarded,
    AMRExternalRevenueAdFormatRewardedInterstitial,
    AMRExternalRevenueAdFormatAppOpen,
    AMRExternalRevenueAdFormatBanner,
    AMRExternalRevenueAdFormatNative,
    AMRExternalRevenueAdFormatLeader,
    AMRExternalRevenueAdFormatMREC
};

@interface AMRExternalRevenue : NSObject
@property (nonatomic, strong) NSString *network;
@property (nonatomic, assign) double revenue;
@property (nonatomic, strong) NSString *placementId;
@property (nonatomic, strong) NSString *adUnitId;
@property (nonatomic, assign) AMRExternalRevenueAdFormat adFormat;

- (instancetype)initWithAdFormat:(AMRExternalRevenueAdFormat)adFormat;
- (BOOL)isValidRevenue;
- (NSString *)adFormatString;
@end

NS_ASSUME_NONNULL_END
