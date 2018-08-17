//
//  HTWatchReminder.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>


#pragma mark - HTWDrinkWaterReminder
/**
 久坐提醒,手表会在长时间不运动时发出提醒，通知用户起身运动
 */
@interface HTWSedentaryReminder : NSObject <NSCopying,NSCoding>
/**
 久坐提醒开关
 */
@property (nonatomic, assign) BOOL isOn;

/**
 午休免打扰，打开此项，午休时间将不会提醒
 */
@property (nonatomic, assign) BOOL restTimeNotDisturbEnabled;

/**
 久坐提醒开始时间，数值为从0开始的分钟数
 */
@property (nonatomic, assign) NSUInteger stMinute;

/**
 久坐提醒结束时间，数值为从0开始的分钟数
 */
@property (nonatomic, assign) NSUInteger edMinute;

+ (instancetype)objectWithData:(NSData *)data;


/**
 判断是否处于午休时间，午休时间为12:00-14:00,如果处于这个范围则为午休时间。
 
 @return 是否处于午休时间
 */
- (BOOL)isAtRestTime;


- (NSData*)writeData;
@end




#pragma mark - HTWDrinkWaterReminder
/**
 喝水提醒
 */
@interface HTWDrinkWaterReminder : NSObject <NSCopying,NSCoding>
// 开关状态
@property (nonatomic, assign) BOOL isOn;
// 时间间隔 分钟
@property (nonatomic, assign) NSUInteger timeInteval;
// 开始时间 （从0开始的分钟数）
@property (nonatomic, assign) NSUInteger stMinute;
// 结束时间 （从0开始的分钟数）
@property (nonatomic, assign) NSUInteger edMinute;

+ (instancetype)objectWithData:(NSData *)data;


- (NSData*)writeData;
@end

