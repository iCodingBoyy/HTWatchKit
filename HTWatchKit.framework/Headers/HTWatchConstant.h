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


static inline void st_dispatch_async_main(dispatch_block_t block)
{
    if ([NSThread isMainThread]) {
        block();
    }
    else
    {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

static inline void st_dispatch_async(dispatch_queue_t queue, dispatch_block_t block)
{
    if (queue && block) {
        dispatch_async(queue, block);
    }
}

static inline void st_dispatch_sync(dispatch_queue_t queue, dispatch_block_t block)
{
    if (queue && block) {
        dispatch_sync(queue, block);
    }
}

@interface HTWatchConstant : NSObject

@end
