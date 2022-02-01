//
//  AMRError.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AMRErrorCode) {
    AMRErrorCodeUnknownError = 0,
    
    /** No server response. */
    AMRErrorCodeServerError = 500,
    
    /** All placements returned no fill or timeouted! */
    AMRErrorCodeAdRequestFailed = -1,
    
    /** No placements found for zone. */
    AMRErrorCodeNoPlacementFound = 1077,
    
    /** Frequency capping is filled for zone. */
    AMRErrorCodeFrequencyCappingFilled = 1078,
    
    /** No Internet Connection. */
    AMRErrorCodeNoInternetConnection = 1079,
    
    /** Tag disabled for zone. */
    AMRErrorCodeTagDisabled = 1081,
    
    /** NoAd Ad policy found for zone. */
    AMRErrorCodeNoAdPolicyFoundForZone = 1082,
    
    /** NoAd Ad policy found for tag. */
    AMRErrorCodeNoAdPolicyFoundForTag = 1083,
    
    /** Frequency capping is filled for tag. */
    AMRErrorCodeFrequencyCappingFilledForTag = 1084,
    
    /** Ad is not ready to show. */
    AMRErrorCodeAdNotReady = 1085,
    
    /** Invalid zoneId. */
    AMRErrorCodeInvalidZoneId = 1086,
    
    /** Invalid appId. */
    AMRErrorCodeInvalidAppId = 1087,
    
    /** AppId and zoneId does not match. */
    AMRErrorCodeMismatchZoneId = 1088,
    
    /** Unknown error when try to show ad. */
    AMRErrorCodeUnknownFailToShow = 1089
    
};

@interface AMRError : NSObject
/**
 * Error code.
 * @see https://admost.github.io/amrios for more information.
 */
@property AMRErrorCode errorCode;
/**
 * Description of error.
 */
@property (readonly) NSString *errorDescription;

+ (instancetype)errorWithError:(NSError *)error;
+ (instancetype)errorWithCode:(AMRErrorCode)code detail:(NSString *)detail;
@end
