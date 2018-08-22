//
//  HTWatchCore.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "HTWatchDefine.h"
#import "HTWatchBlock.h"
#import "HTWWeather.h"
#import "HTWatchConstant.h"
#import "HTWatchConfig.h"


// 手表通讯的核心文件
@interface HTWatchCore : NSObject
@property (nonatomic, assign, readonly) HWKSyncType syncType;
@property (nonatomic, assign, readonly, getter=isSynchronizing) BOOL synchronizing;

/**
 蓝牙centralManager状态，你可以通过kvo观察此状态变化并做相对应的处理
 */
@property (nonatomic, assign, readonly) HWKManagerState managerState;

/**
 手表必要的config数据，使用前需要优先配置
 */
@property (nonatomic, strong) HTWatchConfig *watchConfig;


+ (instancetype)shareCore;

/**
 设置debug打印日志模式，暂不支持
 
 @warning 如果设备未连接，则返回空
 @param printLog 是否打印日子
 */
+ (void)setDebugLogMode:(BOOL)printLog;

/**
 获取当前连接设备的uuid
 @warning 如果设备未连接，则返回空
 @return uuid字符串
 */
- (NSString*)uuidString;

/**
 获取当前连接设备的name
 @warning 如果设备未连接，则返回空
 @return name字符串
 */
- (NSString*)connectedPeripheralName;

#pragma mark - 扫描

/**
 扫描蓝牙外设，如果uuidString存在则返回指定uuidString的外设，不存在则扫描所有符合条件的外设
 
 @param uuidString 蓝牙外设uuid字符串
 @param retHandler 扫描结果回调
 */
- (void)scanForPeripherals:(NSString*)uuidString result:(HWKPeripheralsHandler)retHandler;


/**
 停止蓝牙扫描
 */
- (void)stopScanning;



#pragma mark - 连接与断开
/**
 判断当前的<code>servicePeripheral</code>是否已链接
 
 @return YES/NO
 */
- (BOOL)isConnected;


/**
 连接蓝牙外设外设
 注：调用此接口后会调用<i>stopScanning</i>停止扫描蓝牙外设
 
 @param peripheral 要连接的外设
 @seealso EVENT_CONNECT_PERIPHERAL_NOTIFY,EVENT_FAIL_CONNECT_PERIPHERAL_NOTIFY
 @return YES/NO,如果外设进入连接状态返回YES
 */
- (BOOL)connectPeripheral:(CBPeripheral*)peripheral;


/**
 断开<i>peripheral</i>连接, 断开结果回调请接收通知 {@see EVENT_DISCONNECT_PERIPHERAL_NOTIFY}
 
 @param peripheral 要断开的外设
 @return YES/NO, 如果进入了断开流程返回YES
 */
- (BOOL)disconnectPeripheral:(CBPeripheral*)peripheral;


/**
 断开<i>servicePeripheral</i>连接，断开结果回调请接收通知 {@see EVENT_DISCONNECT_PERIPHERAL_NOTIFY}
 
 @return YES/NO, 如果进入了断开流程返回YES
 */
- (BOOL)disconnect;


#pragma mark - 控制监听

/**
 手表发出请求拍照指令，app收到后应该调用相机进行拍照

 @param retHandler 拍照控制响应回调
 */
- (void)wkOnReceivedCameraControlCMD:(dispatch_block_t)retHandler;


/**
 手表发出查找手机指令，app收到指令应该播放声音并做其他动作提醒用户

 @param retHandler 查找手机指令回调
 */
- (void)wkOnReceivedFindYourPhoneCMD:(dispatch_block_t)retHandler;




#pragma mark - 传感器标志

/**
 判断当前类型的数据是否可以同步，随着固件的升级，部分接口可能不适用于老的固件，需要此功能做检查
 在调用部分蓝牙接口时，如果固件不匹配则会返回<i>HWKSyncResponseStateNoSensorFlag</i>表示当前接口不适用当前固件
 @warning 此接口需要在蓝牙绑定成功后有效，包含<i>HWKSensorFlagType</i>类型的数据接口已封装此功能，故使用前无需调用此接口
 
 @param type 同步类型
 @return YES／NO
 */
- (BOOL)isSyncEnable:(HWKSensorFlagType)type;




#pragma mark - 组合指令

/**
 设备登录组合指令，登录成功后会返回手表系统配置

 @param watchConfig 手表配置
 @param retHandler 同步结果回调
 */
- (void)wkLoginDevice:(HTWatchConfig*)watchConfig result:(HWKSyncResponseHandler)retHandler;


/**
 绑定设备组合指令，绑定完成返回手表系统配置数据，如果系统配置存储失败，做绑定失败处理

 @param watchConfig 手表配置数据
 @param retHandler 同步结果回调
 */
- (void)wkBondDevice:(HTWatchConfig*)watchConfig result:(HWKSyncResponseHandler)retHandler;


/**
 解除设备绑定

 @param retHandler 响应结果回调
 */
- (void)wkUnbindDevice:(HWKSyncResponseHandler)retHandler;


/**
 获取历史数据组合指令

 @param watchConfig 手表配置
 @param dataCallback 数据回调
 @param retHandler 同步结果回调
 */
- (void)wkGetHistoryData:(HTWatchConfig*)watchConfig dataCallback:(HWKSyncDataHandler)dataCallback result:(HWKSyncResponseHandler)retHandler;




#pragma mark - 蓝牙指令

/**
 更新手表时间
 注：此处获取的是当前app的时间，所以同步到手表的时间会与app的时间一致

 @param retHandler 同步结果回调
 */
- (void)wkUpdateWatchTime:(HWKSyncResponseHandler)retHandler;


/**
 设置闹钟数据，最多可以设置8个闹钟
 
 @see HTWAlarmClock
 @param data 闹钟配置数据
 @param retHandler 同步结果回调
 */
- (void)wkSetAlarmData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 获取闹钟列表数据
 
 @see HTWAlarmClock
 @param retHandler 同步结果回调
 */
- (void)wkGetAlarmList:(HWKSyncResponseHandler)retHandler;


/**
 更新手表用户资料
 
 @param data 用户资料
 @param retHandler 同步结果回调
 */
- (void)wkSetUpdateUserProfileData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 获取电池的电量和充电状态信息
 
 @param retHandler 同步结果回调
 */
- (void)wkGetBatteryLevelAndState:(HWKSyncResponseHandler)retHandler;


/**
 手表屏幕显示设置，使用前需要先获取手表屏幕显示标志，然后在根据标志位是否可用配置屏幕显示数据位
 
 @see HTWScreenDisplayFlag 屏幕显示标志位，e.g. stepCount步数如果为YES,说明手表可以显示步数，否则说明手表没有步数显示功能
 @see HTWScreenDisplayConfig 屏幕显示设置位，通过配置属性参数控制手表屏幕显示
 @param data 屏幕显示配置数据
 @param retHandler 同步结果回调
 */
- (void)wkSetScreenDisplaySettingData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 手表功能开关设置
 
 @see HTWFunctionSwitch
 @param data 功能开关配置数据
 @param retHandler 同步结果回调
 */
- (void)wkSetFunctionSwitchData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 健康历史记录
 
 @param data 健康历史记录数据
 @param retHandler 同步结果回调
 */
- (void)wkSetHealthMonitoringSettingData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 喝水提醒设置 (老固件)
 注：你可以通过<i>HTWSensorFlag</i>的drinkReminderAndFWTLS属性判断是否调用此接口（NO调用）
 
 @param bEnabled 开关设置
 @param retHandler 同步结果回调
 */
- (void)wkSetDrinkWaterRemindEnable:(BOOL)bEnabled result:(HWKSyncResponseHandler)retHandler;


/**
 获取手表配置数据,详细数据解析看<i>HTWatchConfigUtils</i>
 注：绑定和登录组合接口都会获取此数据，如果绑定操作中此数据存储失败应该做绑定失败处理
 
 @see HTWatchConfigUtils
 @param retHandler 同步结果回调
 */
- (void)wkGetWatchConfig:(HWKSyncResponseHandler)retHandler;


/**
 久坐提醒设置
 
 @param data 久坐提醒配置数据
 @param retHandler 同步结果回调
 */
- (void)wkSetSedentaryRemindersSettingData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 设置手表佩戴方式：左手佩戴或者右手佩戴

 @param bEnabled 左右佩戴 ？YES : NO
 @param retHandler 同步结果回调
 */
- (void)wkSetLeftHandWearEnable:(BOOL)bEnabled result:(HWKSyncResponseHandler)retHandler;


/**
 查找手表设置，如果蓝牙处于连接状态，当手表收到手机app发出的查找手表命令后手表开始震动
 
 @param retHandler 同步结果回调
 */
- (void)wkFindYourWatch:(HWKSyncResponseHandler)retHandler;


/**
 天气设置，此接口会判断传感器标志位HWKSensorFlagTypeWeather，如果返回 <i>FCSyncResponseStateNoSensorFlag</i> 说明此功能不可用
 
 @param weather 天气数据对象
 @param retHandler 同步结果回调
 */
- (void)wkSetWeather:(HTWWeather*)weather result:(HWKSyncResponseHandler)retHandler;


/**
 收到手机回复，如果蓝牙处于连接状态，当收到手表发出的查找手机命令后，手机发送一个回复给手表表示找到手机
 
 @param retHandler 同步结果回调
 */
- (void)wkFindYourPhoneReply:(HWKSyncResponseHandler)retHandler;


/**
 获取手表的mac地址

 @param retHandler 同步结果回调
 */
- (void)wkGetMacAddress:(HWKSyncResponseHandler)retHandler;


/**
 通知提醒开关设置

 @see HTWAlertMessage
 @param data 通知提醒开关配置
 @param retHandler 同步结果回调
 */
- (void)wkSetAlertMessageSettingData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 ANCS语言设置，此接口会判断传感器标志位HWKSensorFlagTypeANCS，如果返回 <i>FCSyncResponseStateNoSensorFlag</i> 说明此功能不可用
 
 @param retHandler 同步结果回调
 */
- (void)wkSetANCSLanguage:(HWKSyncResponseHandler)retHandler;


/**
 喝水提醒设置(新固件)
 注：你可以通过<i>HTWSensorFlag</i>的drinkReminderAndFWTLS属性判断是否调用此接口（YES调用）

 @see HTWDrinkWaterReminder
 @param data 喝水提醒配置数据
 @param retHandler 同步结果回调
 */
- (void)wkSetDrinkWaterReminderSettingData:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 翻腕亮屏设置
 注：此设置会判断标志位,如果同步结果返回 <i>FCSyncResponseStateNoSensorFlag</i> 说明无此标志位，此功能不可用

 @see HTWTurnWristToLightUpScreen
 @param data 翻腕亮屏配置数据
 @param retHandler 同步结果回调
 */
- (void)wkSetTurnWristToLightUpScreen:(NSData*)data result:(HWKSyncResponseHandler)retHandler;


/**
 默认参考血压设置
 
 @param sbp 收缩压
 @param dbp 舒张压
 @param retHandler 同步结果回调
 */
- (void)wkSetBloodPressure:(UInt16)sbp dbp:(UInt16)dbp result:(HWKSyncResponseHandler)retHandler;


/**
 相机状态设置，拍照控制页面，app进入前台或者后台需要把相机状态发送给手表

 @param bInForeground YES:app在后台  NO:app在前台
 @param retHandler 同步结果回调
 */
- (void)wkSetCameraState:(BOOL)bInForeground result:(HWKSyncResponseHandler)retHandler;



#pragma mark - 健康实时同步
/**
 打开健康实时同步
 
 @param syncType 健康实时同步操作类型
 @param dataCallback 实时同步数据回调
 @param retHandler 同步结果回调
 */
- (void)wkOpenHealthyRealTimeSync:(HWKRTSyncType)syncType dataCallback:(HWKSyncDataHandler)dataCallback result:(HWKSyncResponseHandler)retHandler;


/**
 关闭健康实时同步
 
 @warning 如果关闭成功，此接口和上面的打开接口都会回调结果，关闭失败，只有此结果回调结果
 @param retHandler 同步结果回调
 */
- (void)wkCloseHealthyRealTimeSync:(HWKSyncResponseHandler)retHandler;



#pragma mark - 固件升级

/**
 获取手表固件版本信息
 
 @param retHandler 同步结果回调
 */
- (void)wkGetFirmwareVersion:(HWKSyncResponseHandler)retHandler;


/**
 固件升级接口，掉用此接口，蓝牙将会断开连接并进入固件升级模式，升级成功后，手表会重启
 
 @warning OTA升级过程中，队列中的其他任务会取消调度，如果升级途中有加入其他任务，升级完成或失败也会取消其他任务调度
 @param filePath 要升级的固件路径
 @param progressHandler 固件升级进度回调
 @param retHandler 同步结果回调
 */
- (void)wkUpdateFirmwareWithPath:(NSString*)filePath progress:(HWKProgressHandler)progressHandler result:(HWKSyncResponseHandler)retHandler;


#pragma mark - 移除任务

/**
 从队列中移除任务，正在执行的任务不受影响

 @param selector 当前任务接口api
 @return YES/NO
 */
- (BOOL)removeTaskInQueueWithSelector:(SEL)selector;

/**
 移除队列中的所有任务，调用此接口，已入队的任务竟不会有回调
 */
- (void)removeAllTasksInQueue;


#pragma mark - 发送数据 <请不要调用此接口>

/**
 无响应写数据，数据分包写入
 
 @param data 要写入的数据
 @return YES/NO 如果写入条件不足，则返回NO
 */
- (BOOL)writeValue:(NSData*)data;

/**
 写数据，数据分包写入
 
 @param data 要写入的数据
 @param type 写类型
 @return YES/NO 如果写入条件不足，则返回NO
 */
- (BOOL)writeValue:(NSData*)data type:(CBCharacteristicWriteType)type;
@end
