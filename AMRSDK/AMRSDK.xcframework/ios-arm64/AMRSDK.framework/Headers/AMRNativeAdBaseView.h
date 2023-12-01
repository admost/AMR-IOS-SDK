//
//  AMRNativeAdBaseView.h
//  AMRSDK
//
//  Created by Tolga Seremet on 17/09/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AMRTypes.h"

@class AMRPlacement;

extern NSString * const kAMRImageNameDefaultPrivacyIcon;

extern NSString * const kAMRNativeAssetKeyTitle;
extern NSString * const kAMRNativeAssetKeySubtitle;
extern NSString * const kAMRNativeAssetKeyPrice;
extern NSString * const kAMRNativeAssetKeyDescription;
extern NSString * const kAMRNativeAssetKeyCallToAction;
extern NSString * const kAMRNativeAssetKeyIconURL;
extern NSString * const kAMRNativeAssetKeyCoverURL;
extern NSString * const kAMRNativeAssetKeyPrivacyURL;
extern NSString * const kAMRNativeAssetKeyIconImage;
extern NSString * const kAMRNativeAssetKeyCoverImage;
extern NSString * const kAMRNativeAssetKeyPrivacyImage;
extern NSString * const kAMRNativeAssetKeyPrivacyImageName;
extern NSString * const kAMRNativeAssetKeyPrivacyImageView;
extern NSString * const kAMRNativeAssetKeyClickURL;
extern NSString * const kAMRNativeAssetKeySponsored;

@interface AMRNativeAdBaseView : UIView

@property (nonatomic, weak) IBOutlet UILabel *LBLTitle;
@property (nonatomic, weak) IBOutlet UILabel *LBLSubtitle;
@property (nonatomic, weak) IBOutlet UILabel *LBLPrice;
@property (nonatomic, weak) IBOutlet UILabel *LBLDescription;
@property (nonatomic, weak) IBOutlet UILabel *LBLCallToAction;
@property (weak, nonatomic) IBOutlet UILabel *LBLSponsored;
@property (nonatomic, weak) IBOutlet UIImageView *IMGIcon;
@property (nonatomic, weak) IBOutlet UIImageView *IMGCover;
@property (nonatomic, weak) IBOutlet UIImageView *IMGPrivacyIcon;
@property (nonatomic, weak) IBOutlet UIButton *BTNClickFB;
@property (nonatomic, assign) AMRBannerSize bannerSize;
@property (nonatomic, strong) AMRPlacement *placement;

//Will be depreciated soon.
@property (nonatomic, weak) IBOutlet UIView *trackingView __deprecated;
@property (nonatomic, weak) IBOutlet UIButton *BTNClick __deprecated;
@property (nonatomic, weak) IBOutlet UIImageView *IMGCoverBG __deprecated;

+ (instancetype)baseViewWithPlacement:(AMRPlacement *)placement;
- (void)decorateWithDictionary:(NSDictionary *)dictionary;
@end
