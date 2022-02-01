//
//  AMRRemoteConfigValue.h
//  AMRSDK
//
//  Created by Mehmet Karagöz on 2.06.2021.
//  Copyright © 2021 Admost. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AMRRemoteConfigValue : NSObject
- (instancetype)initWithObject:(id)object;

- (nullable NSString *)stringValue;
- (BOOL)boolValue;
- (nullable NSNumber *)numberValue;
@end

NS_ASSUME_NONNULL_END
