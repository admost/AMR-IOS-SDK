//
//  AMRBannerView.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AMRPlacement;

@interface AMRBannerView : UIView
@property AMRPlacement *placement;

@property NSURL *customNativeBannerIconURL;
@property NSString *customNativeBannerDetailText;
@property NSString *customNativeBannerHeaderText;
@property NSString *customNativeBannerCtaText;
@property NSInteger customNativeBannerDuration;
@end
