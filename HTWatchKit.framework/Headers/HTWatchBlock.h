//
//  HTWatchBlock.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "HTWatchDefine.h"
#import "HTWSyncResponse.h"


#ifndef HTWatchBlock_h
#define HTWatchBlock_h


/**
 外设回调block，返回当前扫描到的外设和所有扫描的外设列表，当有新外设被扫描到，此block会被调用
 
 @param retArray 一组 <i>CBPeripheral</i> 对象
 @param aPeripheral 当前被扫描到的外设
 */
typedef void (^HWKPeripheralsHandler)(NSArray<CBPeripheral*>*retArray, CBPeripheral *aPeripheral);


/**
 同步响应结果block

 @param response 包含响应结果的响应对象
 */
typedef void (^HWKSyncResponseHandler) (HTWSyncResponse *response);


/**
 同步数据回调block

 @param syncType 同步类型
 @param data 同步数据
 */
typedef void (^HWKSyncDataHandler) (HWKSyncType syncType, NSData *data);


/**
 实时同步数据回调block
 
 @param data 健康实时同步数据
 */
typedef void (^HWKRTSyncDataHandler)(NSData *data);


/**
 同步进度回调block

 @param progressValue 进度值
 */
typedef void (^HWKProgressHandler) (CGFloat progressValue);

#endif /* HTWatchBlock_h */
