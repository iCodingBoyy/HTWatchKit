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

- (NSData*)writeData;
@end
