//
//  AMRHTTPRequestTrace.h
//  AMRSDK
//
//  Created by Mehmet Karagöz on 18.05.2026.
//  Copyright © 2026 Admost. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AMRHTTPRequestTrace : NSObject

- (void)setRequestPayloadSize:(int64_t)bytes;
- (void)setResponsePayloadSize:(int64_t)bytes;
- (void)endWithStatusCode:(NSInteger)statusCode;
- (void)endWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
