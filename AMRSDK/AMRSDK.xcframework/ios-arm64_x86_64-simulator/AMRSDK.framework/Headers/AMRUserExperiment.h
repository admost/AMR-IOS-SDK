//
//  AMRUserExperiment.h
//  AMRSDK
//
//  Created by Mehmet Karagöz on 2.12.2020.
//  Copyright © 2020 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AMRUserExperiment : NSObject
@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *group;
@end

NS_ASSUME_NONNULL_END
