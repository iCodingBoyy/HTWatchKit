//
//  HTWHealthMonitoring.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 手表健康定时监测
 */
@interface HTWHealthMonitoring : NSObject
/**
 健康监测开关状态
 */
@property (nonatomic, assign) BOOL isOn;

/**
 健康监测开始时间（从0点开始的分钟数）.
 */
@property (nonatomic, assign) NSUInteger stMinute;

/**
 健康监测结束时间（从0点开始的分钟数）.
 */
@property (nonatomic, assign) NSUInteger edMinute;

+ (instancetype)objectWithData:(NSData *)data;
+ (instancetype)objectWithWatchConfig:(NSData *)configData;
- (NSData*)updateWatchConfig:(NSData*)configData;
- (NSData*)writeData;
@end
