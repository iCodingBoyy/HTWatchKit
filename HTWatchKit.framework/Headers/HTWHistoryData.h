//
//  HTWHistoryData.h
//  HTWatchKit
//
//  Created by 马远征 on 2017/11/28.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 同步数据的类型，用于区分HWKDataObject数据类型
 */
typedef NS_ENUM(NSInteger, HWKDataType)
{
    /*!  默认未知类型*/
    HWKDataTypeUnknown = 0,
    /*!  运动量*/
    HWKDataTypeExercise,
    /*!  睡眠*/
    HWKDataTypeSleep,
    /*!  心率*/
    HWKDataTypeHeartRate,
    /*!  血氧*/
    HWKDataTypeBloodOxygen,
    /*!  血压*/
    HWKDataTypeBloodPressure,
    /*!  呼吸频率*/
    HWKDataTypeBreathingRate,
    /*!  七天日总睡眠数据*/
    HWKDataTypeSevenDaySleepData,
};



// 同步到的数据对象，包括运动数据，睡眠数据，健康数据等
@interface HTWHistoryData : NSObject
/**
 数据类型，用于区分不同的数据，详细见<i>HWKDataType</i>
 */
@property (nonatomic, assign) HWKDataType DataType;

/**
 自1970开始的时间戳
 */
@property (nonatomic, strong) NSNumber *timeStamp;

/**
 运动和健康数据，dataType为一下类型时分别对应一下数据
 <i>HWKDataTypeExercise</i>：value为运动的步数；
 <i>HWKDataTypeSleep</i>：value为睡眠状态（1：深睡眠 2：浅睡眠 3：清醒）；
 <i>HWKDataTypeHeartRate</i>：value为平均心率；
 <i>HWKDataTypeBloodOxygen</i>：value为血氧数值；
 <i>HWKDataTypeBloodPressure</i>：value为收缩压，extravalue为舒张压；
 <i>HWKDataTypeBreathingRate</i>：value为呼吸频率
 */
@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, strong) NSNumber *extraValue;

// 下面两个属性在FCDataTypeExercise类型时有效
@property (nonatomic, strong) NSNumber *calorie; // 小卡
@property (nonatomic, strong) NSNumber *distance; // 米
@end
