//
//  HTWSyncResponse.h
//  HTWatchKit
//
//  Created by 马远征 on 2017/11/21.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HTWatchDefine.h"



typedef NS_ENUM(NSInteger, HWKSyncResponseState) {
    
    /*! 未知类型*/
    HWKSyncResponseStateUnKnown = 0,
    /*! 同步响应成功*/
    HWKSyncResponseStateSuccess,
    /*! 同步响应失败*/
    HWKSyncResponseStateError,
};


/**
 同步响应结果错误码，如果蓝牙在通讯过程中centralManager发生状态变化，部分蓝牙相关状态被回调
 */
typedef NS_ENUM(NSInteger, HWKSyncResponseErrorCode) {
    
    /*! 未知类型*/
    HWKSyncResponseErrorCodeUnKnown = 0,
    
    /*! 当前设备不支持蓝牙4.0*/
    HWKSyncResponseErrorCodeBleUnsupported = 1,
    
    /*! 蓝牙未授权*/
    HWKSyncResponseErrorCodeBleUnauthorized = 2,
    
    /*! 蓝牙重置状态*/
    HWKSyncResponseErrorCodeBleResetting = 3,
    
    /*! 蓝牙未连接*/
    HWKSyncResponseErrorCodeBleNotConnected = 4,
    
    /*! 蓝牙关闭，主动关闭蓝牙时回调*/
    HWKSyncResponseErrorCodeBlePowerOff = 5,
    
    /*! 蓝牙断开连接，主动或者被动断开都会调用*/
    HWKSyncResponseErrorCodeBleDisconnect = 7,
    
    /*! 同步参数错误,部分带入参的接口有此返回*/
    HWKSyncResponseErrorCodeParameterError = 8,
    
    /*! 正在同步，蓝牙正在同步时发起同步操作会返回此结果*/
    HWKSyncResponseErrorCodeSyncing = 10,
    
    /*! 同步超时*/
    HWKSyncResponseErrorCodeTimeOut,
    
    /*! 实时同步超时*/
    HWKSyncResponseErrorCodeRTSTimeOut,
    
    /*! 打开实时同步错误*/
    HWKSyncResponseErrorCodeOpenRTSError,
    
    /*! 关闭实时同步错误*/
    HWKSyncResponseErrorCodeCloseRTSError,
    
    /*! 心电正在同步*/
    HWKSyncResponseErrorCodeECGSynching,
    
    /*! 心电正在保存*/
    HWKSyncResponseErrorCodeECGSaving,
    
    /*! 低电量模式，固件升级时低电量提示*/
    HWKSyncResponseErrorCodeLowPower,
    
    /*! 找不到要发送的指令*/
    HWKSyncResponseErrorCodeNoCommand,
    
    /*! 通用响应错误*/
    HWKSyncResponseErrorCodeError,
    
    /*! 数据长度错误*/
    HWKSyncResponseErrorCodeDataLenError,
    
    /*! 当前无实时同步任务*/
    HWKSyncResponseErrorCodeNoRTSyncTask,
    
    /*! ota文件路径不存在*/
    HWKSyncResponseErrorCodeOTAFilePathIsNULL,
    
    /*! 调用其他实时任务接口如果正在执行实时健康同步或者Task Queued则返回以下errorCode*/
    HWKSyncResponseErrorCodeRTHealthRateIsSyncing,
    HWKSyncResponseErrorCodeRTBloodOxygenIsSyncing,
    HWKSyncResponseErrorCodeRTBloodPressureIsSyncing,
    HWKSyncResponseErrorCodeRTBreathingRateIsSyncing,
    
    /*! 调用其他实时任务接口如果正在执行ECG或者ECG Queued则返回此errorCode*/
    HWKSyncResponseErrorCodeRTECGIsSyncing,
    
    /*! 调用其他实时任务接口如果正在执行OTA或者OTA Queued则返回此errorCode*/
    HWKSyncResponseErrorCodeOTAIsTransferring,
};


@interface HTWSyncResponse : NSObject
@property (nonatomic, assign) HWKSyncType syncType;
/**
 响应状态，获取结果时优先判断响应状态
 */
@property (nonatomic, assign) HWKSyncResponseState responseState;
/**
 responseState为Error时，此错误码有效-
 */
@property (nonatomic, assign) HWKSyncResponseErrorCode errorCode;
/**
 responseState为Error时，此描述有效
 */
@property (nonatomic, strong) NSString *errorDesc;


/**
 设置响应数据，如果蓝牙指令成功发送出去，携带目标数据响应，则目标数据保存在此缓存中

 @param data 蓝牙目标数据
 @param identifier 目标结果数据标志
 */
- (void)setResponseData:(NSData*)data forIdentifier:(NSString*)identifier;


/**
 根据identifier获取响应数据，如果传入nil，则默认返回第一个数据
 此接口只针对带有响应数据接口有效，具体查看HWKResponseDataIdentifier标志定义
 @param identifier 数据类型标志
 @return 响应数据
 */
- (NSData*)getResponseDataWithIdentifier:(NSString*)identifier;

@end
