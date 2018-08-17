//
//  HTWatchKit.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <UIKit/UIKit.h>

#if __has_include(<HTWatchKit/HTWatchKit.h>)
//! Project version number for HTWatchKit.
FOUNDATION_EXPORT double HTWatchKitVersionNumber;

//! Project version string for HTWatchKit.
FOUNDATION_EXPORT const unsigned char HTWatchKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <HTWatchKit/PublicHeader.h>

#import <HTWatchKit/HTWatchCore.h>

// utils
#import <HTWatchKit/HTWRTSyncUtils.h>
#import <HTWatchKit/HTWSyncUitls.h>
#import <HTWatchKit/HTWOtherUtils.h>
#import <HTWatchKit/HTWatchConfigUtils.h>

// response
#import <HTWatchKit/HTWSyncResponse.h>

// define
#import <HTWatchKit/HTWServiceAPI.h>
#import <HTWatchKit/HTWatchConstant.h>
#import <HTWatchKit/HTWatchBlock.h>
#import <HTWatchKit/HTWatchDefine.h>

// model
#import <HTWatchKit/HTWTurnWristToLightUpScreen.h>
#import <HTWatchKit/HTWScreenDisplay.h>
#import <HTWatchKit/HTWatchReminder.h>
#import <HTWatchKit/HTWHealthMonitoring.h>
#import <HTWatchKit/HTWFunctionSwitch.h>
#import <HTWatchKit/HTWSensorFlag.h>
#import <HTWatchKit/HTWAlertMessage.h>
#import <HTWatchKit/HTWAlarmClock.h>
#import <HTWatchKit/HTWWeather.h>
#import <HTWatchKit/HTWatchConfig.h>
#import <HTWatchKit/HTWHistoryData.h>
#import <HTWatchKit/HTWRunning.h>

#else

#import "HTWatchKit/HTWatchCore.h"

// utils
#import "HTWatchKit/HTWRTSyncUtils.h"
#import "HTWatchKit/HTWSyncUitls.h"
#import "HTWatchKit/HTWOtherUtils.h"
#import "HTWatchKit/HTWatchConfigUtils.h"

// response
#import "HTWatchKit/HTWSyncResponse.h"

// define
#import "HTWatchKit/HTWServiceAPI.h"
#import "HTWatchKit/HTWatchConstant.h"
#import "HTWatchKit/HTWatchBlock.h"
#import "HTWatchKit/HTWatchDefine.h"

// model
#import "HTWatchKit/HTWTurnWristToLightUpScreen.h"
#import "HTWatchKit/HTWScreenDisplay.h"
#import "HTWatchKit/HTWatchReminder.h"
#import "HTWatchKit/HTWHealthMonitoring.h"
#import "HTWatchKit/HTWFunctionSwitch.h"
#import "HTWatchKit/HTWSensorFlag.h"
#import "HTWatchKit/HTWAlertMessage.h"
#import "HTWatchKit/HTWAlarmClock.h"
#import "HTWatchKit/HTWWeather.h"
#import "HTWatchKit/HTWatchConfig.h"
#import "HTWatchKit/HTWHistoryData.h"
#import "HTWatchKit/HTWRunning.h"

#endif
