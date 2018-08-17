//
//  HTWRunning.h
//  HTWatchKit
//
//  Created by 马远征 on 2017/11/28.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 (1) APP通过此配置来控制手表跑步模式和跑步状态
 (2) 手表启动跑步指令，会将此配置发送给APP
 */
@interface HTWRunningConfig : NSObject

// 跑步模式
@property (nonatomic, assign) UInt8 runMode;
/**
 跑步状态 0 结束,1 开始,2 暂停,3 恢复
 */
@property (nonatomic, assign) UInt8 runState;

/**
 跑步的id号码
 */
@property (nonatomic, assign) UInt32 runId;

@property (nonatomic, assign) UInt32 extraBytes;

+ (instancetype)runConfigWithData:(NSData*)data;

- (NSData*)writeData;
@end


#pragma mark - HTWRunningStateCode
/**
 （1）当手表发起开始或者结束跑步时，需要回复此数据给手表响应跑步结果
 （2）如果是App发送指令给手表，将会收到此响应结果
 */
@interface HTWRunningStateCode : NSObject
@property (nonatomic, assign) UInt8 runMode;
@property (nonatomic, assign) UInt8 runState;
@property (nonatomic, assign) UInt8 responseCode;
/**
 错误码
 0x01: 其他失败原因
 0x02: 对端正在进行其他运动
 0x03: 蓝牙未连接
 0x04 设置模式参数错误失败
 0x05 GPS 启动搜索失败
 */
@property (nonatomic, assign) UInt8 errorCode;
@property (nonatomic, assign) UInt16 extraBytes;

+ (instancetype)runStateCodeWithData:(NSData*)data;
- (NSData*)writeData;
@end


#pragma mark - HTWRunningMode
/**
 跑步状态，通过发送获取跑步状态指令获取手表的跑步状态
 */
@interface HTWRunningMode : NSObject
@property (nonatomic, assign) UInt8 runMode;
@property (nonatomic, assign) UInt8 runState;
@property (nonatomic, assign) UInt32 runId;
+ (instancetype)runModeWithData:(NSData*)data;
@end


#pragma mark - HTWRunningData
/**
 跑步总数据，app配合手表跑步时需要定时获取一次手表的跑步
 注：获取这个总数据命令需要判断一下运动模式是否是对应手机上的运动模式，还有如果运动模式状态为停止，两个有一个满足的话就结束手机上的运动
 */
@interface HTWRunningData : NSObject
@property (nonatomic, assign) UInt8 runMode;
@property (nonatomic, assign) UInt8 runState;
@property (nonatomic, assign) UInt32 runTime; // 时长(秒)
@property (nonatomic, assign) UInt32 steps;
@property (nonatomic, assign) UInt32 distance; // 距离(cm)
@property (nonatomic, assign) UInt32 calorie; // 卡路里(小卡cal)
@property (nonatomic, assign) UInt32 pace; // 配速(s/km)
@property (nonatomic, assign) UInt32 runId; // 跑步Id
@property (nonatomic, assign) UInt32 avgPace; // 跑步过程的平均配速(s/km)
+ (instancetype)runTotalDataWithData:(NSData*)data;
@end


#pragma mark - HTRunSummary

@interface HTRunSummary : NSObject
@property (nonatomic, assign) UInt32 date;
@property (nonatomic, assign) NSInteger runType;
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, assign) NSInteger stepCount;
@property (nonatomic, assign) NSInteger distance;
@property (nonatomic, assign) NSInteger calorie;
@property (nonatomic, assign) NSInteger avgPace;
@end
