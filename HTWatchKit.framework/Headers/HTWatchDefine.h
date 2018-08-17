//
//  HTWatchDefine.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#ifndef HTWatchDefine_h
#define HTWatchDefine_h

/**
 蓝牙状态定义
 */
typedef NS_ENUM(NSInteger, HWKManagerState) {
    /*! 未知错误*/
    HWKManagerStateUnknown,
    /*! 蓝牙重置状态*/
    HWKManagerStateResetting,
    /*! 设备不支持状态*/
    HWKManagerStateUnsupported,
    /*! 设备未授权状态*/
    HWKManagerStateUnauthorized,
    /*! 蓝牙关闭*/
    HWKManagerStatePoweredOff,
    /*! 蓝牙打开*/
    HWKManagerStatePoweredOn,
};

/**
 传感器标志，如果存在某个标志可以进行某项数据同步
 */
typedef NS_OPTIONS(UInt32, HWKSensorFlagType)
{
    /*! 心率*/
    HWKSensorFlagTypeHeartRate = 1,
    
    /*! 紫外线*/
    HWKSensorFlagTypeUV = 1 << 1,
    
    /*! 天气预报*/
    HWKSensorFlagTypeWeather = 1 << 2,
    
    /*! 血氧，有此标志则存在血氧功能*/
    HWKSensorFlagTypeBloodOxygen = 1 << 3,
    
    /*! 血压，有此标志则存在血压功能*/
    HWKSensorFlagTypeBloodPressure = 1 << 4,
    
    /*! 呼吸频率*/
    HWKSensorFlagTypeBreathingRate = 1 << 5,
    
    /*! 加强检测*/
    HWKSensorFlagTypeEnhanceMeasurement = 1 << 6,
    
    /*! 睡眠七天历史数据*/
    HWKSensorFlagTypeSevenDaysSleepSummary = 1 << 7,
    
    /*! 心电*/
    HWKSensorFlagTypeECG = 1 << 8,
    
    /*! 外部Flash OTA*/
    HWKSensorFlagTypeFlashOTA = 1 << 9,
    
    /*! 手机系统语言设置*/
    HWKSensorFlagTypeANCS = 1 << 10,
    
    /*! 喝水提醒和翻腕亮屏新设置*/
    HWKSensorFlagTypeDinkWaterReminderAndFWLS = 1 << 11,
    
    /*! 跑步*/
    HWKSensorFlagTypeRuning = 1 << 12,
    
    /*! 日语ANCS字库*/
    HWKSensorFlagTypeANCSJapanese = 1 << 13,
    
    /*! 温度单位设置标志*/
    HWKSensorFlagTypeTemperatureUnit = 1 << 14,
    
    /*! 微信运动标志位*/
    HWKSensorFlagTypeWeRun = 1 << 15,
    
    /*! 华盛达Telegram和Viber提醒标志*/
    HWKSensorFlagTypeTelegramAndViber = 1 << 16,
    
    /*! 挂脖耳机*/
    HWKSensorFlagTypeHalterHeadphones = 1 << 17,
};

/**
 实时同步类型
 */
typedef NS_ENUM(NSInteger, HWKRTSyncType)
{
    /*! 默认*/
    HWKRTSyncTypeUnknown = 0,
    /*! 心率*/
    HWKRTSyncTypeHeartRate,
    /*! 实时血氧*/
    HWKRTSyncTypeBloodOxygen,
    /*! 血压e*/
    HWKRTSyncTypeBloodPressure,
    /*! 呼吸频率*/
    HWKRTSyncTypeBreathingRate,
    /*! 心电图*/
    HWKRTSyncTypeECG,
};


/**
 手环数据同步标志
 */
typedef NS_ENUM(NSInteger, HWKSyncType) {
    
    /*! 默认类型*/
    HWKSyncTypeUnknown = 0,
    
    /*! 登录设备，复合指令分条执行，可能包含下面多个任务类型*/
    HWKSyncTypeLogin = 1,
    
    /*! 绑定设备，复合指令分条执行，可能包含下面多个任务类型*/
    HWKSyncTypeBind = 2,
    
    /*! 历史数据同步，复合指令分条执行，可能包含下面多个任务类型*/
    HWKSyncTypeGetHistoryData = 3,
    
    /*! 解绑设备*/
    HWKSyncTypeUnBindDevice = 4,
    
    /*! 登录设备*/
    HWKSyncTypeLoginDevice = 5,
    
    /*! 绑定设备*/
    HWKSyncTypeBindDevice = 6,
    
    /*! 设置系统时间*/
    HWKSyncTypeUpdateWatchTime = 7,
    
    /*! 更新功能开关*/
    HWKSyncTypeSetFeatures = 8,
    
    /*! 更新佩戴方式*/
    HWKSyncTypeSetWearingStyle = 9,
    
    /*! 更新用户资料*/
    HWKSyncTypeSetUserProfile = 10,
    
    /*! 更新默认参考血压*/
    HWKSyncTypeSetDefaultBloodPressure = 11,
    
    /*! 获取手表配置*/
    HWKSyncTypeGetWatchConfig = 12,
    
    /*! 查找手表*/
    HWKSyncTypeFindTheWatch = 13,
    
    /*! 获取闹钟列表*/
    HWKSyncTypeGetAlarmList = 14,
    
    /*! 闹钟设置*/
    HWKSyncTypeSetAlarmData = 15,
    
    /*! 电量和充电状态获取*/
    HWKSyncTypeGetBatteryLevelAndState = 16,
    
    /*! 屏幕显示设置*/
    HWKSyncTypeSetScreenDisplay = 17,
    
    /*! 通知开关设置*/
    HWKSyncTypeSetNotification = 18,
    
    /*! 久坐提醒*/
    HWKSyncTypeSetSedentaryReminder = 19,
    
    /*! 健康监测*/
    HWKSyncTypeSetHealthMonitoring = 20,
    
    /*! 喝水提醒*/
    HWKSyncTypeSetDrinkReminder = 21,
    
    /*! 相机状态设置*/
    HWKSyncTypeSetCameraState = 22,
    
    /*! 天气更新*/
    HWKSyncTypeUpdateWeather = 23,
    
    /*! 请求固件升级*/
    HWKSyncTypeEnterOTAMode = 27,
    
    /*! 获取固件版本*/
    HWKSyncTypeGetFirmwareVersion = 28,
    
    /*! 获取手表mac地址*/
    HWKSyncTypeGetMacAddress = 29,
    
    /*! 发现手机回复*/
    HWKSyncTypeFoundPhoneReplay = 29,
    
    /*! 设置ANCS语言*/
    HWKSyncTypeSetANCSLanguage = 30,
    
    /*! 获取日总数据包括运动总步数、总距离、总卡路里等*/
    HWKSyncTypeGetDaySummary = 31,
    
    /*! 获取运动量详细记录*/
    HWKSyncTypeGetMotionData = 32,
    
    /*! 获取睡眠详细记录*/
    HWKSyncTypeGetSleepData = 33,
    
    /*! 获取血氧记录*/
    HWKSyncTypeGetBloodOxygenData = 34,
    
    /*! 获取血压记录*/
    HWKSyncTypeGetBloodPressureData = 35,
    
    /*! 获取呼吸频率记录*/
    HWKSyncTypeGetBreathingRateData = 36,
    
    /*! 获取心率记录*/
    HWKSyncTypeGetHeartRateData = 37,
    
    /*! 获取紫外线记录*/
    HWKSyncTypeGetUltravioletData = 38,
    
    /*! 获取七日睡眠总数据*/
    HWKSyncTypeGetSevenDaysSleepSummary = 39,
    
    /*! 翻腕亮屏设置*/
    HWKSyncTypeSetFlipWristToLightScreen = 40,
    
    /*! 跑步指令设置*/
    HWKSyncTypeSetEnterRuningMode = 41,
    
    /*! 跑步指令开关状态设置*/
    HWKSyncTypeSetRuningMode = 42,
    
    /*! 获取跑步状态*/
    HWKSyncTypeGetRuningMode = 43,
    
    /*! 获取跑步数据*/
    HWKSyncTypeGetRuningSummary = 44,
    
    /*! 获取跑步详细数据*/
    HWKSyncTypeGetRuningDetailData = 45,
    
    /*! 重启手表设置*/
    HWKSyncTypeSetRestartWatch = 46,
    
    /*! 关闭睡眠监测*/
    HWKSyncTypeCloseSleepMonitoring,
    
    /*! 健康实时同步包含打开和关闭实时同步*/
    HWKSyncTypeHealthyRealtimeSync,
    
    /*! 打开健康实时同步*/
    HWKSyncTypeOpenRealtimeSync,
    
    /*! 关闭健康实时同步*/
    HWKSyncTypeCloseRealtimeSync,
    
    /*! 心电实时同步*/
    HWKSyncTypeECGRTSync,
    
    /*! 打开心电实时同步*/
    HWKSyncTypeOpenECG,
    
    /*! 关闭心电实时同步*/
    HWKSyncTypeCloseECG,
    
    /*! 获取心电同步状态*/
    HWKSyncTypeGetECGSyncState,
    
    /*! 心电历史数据1同步*/
    HWKSyncTypeGetECGHistoryData,
    
    /*! 结束*/
    HWKSyncTypeEnd = 1000,
};

#endif /* HTWatchDefine_h */
