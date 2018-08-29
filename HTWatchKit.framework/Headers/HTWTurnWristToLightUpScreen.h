//
//  HTWTurnWristToLightUpScreen.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>

// 翻腕亮屏
@interface HTWTurnWristToLightUpScreen : NSObject
@property (nonatomic, assign) BOOL isOn;
@property (nonatomic, assign) NSUInteger stMinutes;
@property (nonatomic, assign) NSUInteger edMinutes;

+ (instancetype)objectWithData:(NSData *)data;
+ (instancetype)objectWithWatchConfig:(NSData *)configData;

/**
 带时间的翻腕亮屏设置需要传感器标志支持，高版本固件有此功能，如果手表配置数据长度小于71则更新会失败
 @return 更新后的手表配置数据
 */
- (NSData*)updateWatchConfig:(NSData*)configData;
- (NSData*)writeData;
@end
