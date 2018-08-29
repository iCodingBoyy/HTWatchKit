//
//  HTWFunctionSwitch.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>

// 功能开关，用户打开或者关闭某些功能
@interface HTWFunctionSwitch : NSObject

/**
 翻动手腕时点亮手表屏幕
 注：如果翻腕亮屏可以设置时间(HTWSensorFlag标志drinkReminderAndFWTLS位YES)，则此处应当设置为NO
 */
@property (nonatomic, assign) BOOL flipWristToLightScreen;

/**
 加强测量，心率等测量不出来时，手环会开启加强光反射
 */
@property (nonatomic, assign) BOOL enhanceMeasurementEnabled;

/**
 12小时时间制式，如果为NO，则使用24小时时间制式
 */
@property (nonatomic, assign) BOOL twelveHoursSystem;


/**
 距离和重量单位，0 为公制单位  1 英制单位
 */
@property (nonatomic, assign) BOOL isImperialUnits;

/**
 温度单位，0：摄氏温度 1：华氏温度
 */
@property (nonatomic, assign) BOOL isFahrenheitTemperatureUnit;

+ (instancetype)objectWithData:(NSData*)data;
+ (instancetype)objectWithWatchConfig:(NSData*)configData;
- (NSData*)updateWatchConfig:(NSData*)configData;
- (NSData*)writeData;
@end
