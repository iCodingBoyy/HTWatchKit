//
//  HTWatchConstant.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>

// 外设状态更新通知
FOUNDATION_EXTERN NSString *const EVENT_CENTRALMANAGER_UPDATE_STATE_NOTIFY;

// 外设连接成功通知
FOUNDATION_EXTERN NSString *const EVENT_CONNECT_PERIPHERAL_NOTIFY;

// 外设连接失败通知
FOUNDATION_EXTERN NSString *const EVENT_FAIL_CONNECT_PERIPHERAL_NOTIFY;

// 外设断开连接通知
FOUNDATION_EXTERN NSString *const EVENT_DISCONNECT_PERIPHERAL_NOTIFY;

// 发现服务特征,接到此通知，你可以进行蓝牙写数据,为防止蓝牙连接后扫描不到特征服务，你最好在蓝牙成功连接后启动一个定时器，在收到这个通知后关闭定时器
FOUNDATION_EXTERN NSString *const EVENT_DISCOVER_CHARACTERISTICS_NOTIFY;

// 固件升级成功断开连接通知
FOUNDATION_EXTERN NSString *const EVENT_FIRMWARE_UPDATE_DISCONNECT_PERIPHERAL_NOTIFY;


// 收到手表发出的拍摄照片指令，收到此指令你可以调用相机拍照功能进行拍照
FOUNDATION_EXTERN NSString *const EVENT_TAKE_PICTURES_COMMAND_NOTIFY;

// 收到手表发出的查找手机指令，收到此指令你可以震动、响铃或者做其他操作方便用户通过手表找到手机
FOUNDATION_EXTERN NSString *const EVENT_FIND_YOUR_PHONE_COMMAND_NOTIFY;



#pragma mark  - 响应数据

typedef NSString * HWKResponseDataIdentifier NS_STRING_ENUM;

// 手表系统配置数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKWatchConfigDataIdentifier;
// 手表mac地址数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKMacAddressDataIdentifier;
// 心电同步状态数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKECGSyncStateDataIdentifier;
// 闹钟列表数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKAlarmListDataIdentifier;
// 电池电量和充电状态数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKBatteryLevelAndChargingStateDataIdentifier;
// 手表日总数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKDaySummaryDataIdentifier;
// 手表运动量数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKExerciseDataIdentifier;
// 手表睡眠数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKSleepDataIdentifier;
// 手表心率数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKHeartRateDataIdentifier;
// 手表血氧数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKBloodOxygenDataIdentifier;
// 手表紫外线数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKUltravioleDataIdentifier;
// 手表血压数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKBloodPressureDataIdentifier;
// 手表呼吸频率数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKBreathingRateDataIdentifier;
// 手表七日睡眠总数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKSevenDaysSleepTotalDataIdentifier;
// 手表跑步总数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKRuningSummaryDataIdentifier;
// 手表跑步状态数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKRuningStateDataIdentifier;
// 手表固件版本数据标志
FOUNDATION_EXTERN HWKResponseDataIdentifier const HWKFirmwareVersionDataIdentifier;


@interface HTWatchConstant : NSObject

@end
