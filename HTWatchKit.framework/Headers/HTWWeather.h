//
//  HTWWeather.h
//  HTWatchKit
//
//  Created by 远征 马 on 2017/11/8.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 天气状态，你需要把自己获取的天气转换成以下状态同步到手表，手表才能显示正确的天气状态
 */
typedef NS_ENUM(NSInteger, HTWWeatherState)
{
    /*! 未知天气*/
    HTWWeatherStateUnknown = 0xFF,
    /*! 晴天*/
    HTWWeatherStateSunnyDay = 0x01,
    /*! 多云*/
    HTWWeatherStateCloudy = 0x02,
    /*! 阴天*/
    HTWWeatherStateOvercast = 0x03,
    /*! 阵雨*/
    HTWWeatherStateShower = 0x04,
    /*! 雷阵雨、雷阵雨伴有冰雹*/
    HTWWeatherStateThunderyShower = 0x05,
    /*! 小雨*/
    HTWWeatherStateDrizzle = 0x06,
    /*! 中雨、大雨、暴雨*/
    HTWWeatherStateHeavyRain = 0x07,
    /*! 雨夹雪、冻雨*/
    HTWWeatherStateSleet = 0x08,
    /*! 小雪*/
    HTWWeatherStateLightSnow = 0x09,
    /*! 大雪、暴雪*/
    HTWWeatherStateHeavySnow = 0x0a,
    /*! 沙尘暴、浮尘*/
    HTWWeatherStateSandstorm = 0x0b,
    /*! 雾、雾霾*/
    HTWWeatherStateFogOrHaze = 0x0c,
};


@interface HTWWeather : NSObject
/**
 当前温度
 */
@property (nonatomic, assign) NSInteger temperature;

/**
 最高温度
 */
@property (nonatomic, assign) NSInteger maxTemperature;

/**
 最低温度
 */
@property (nonatomic, assign) NSInteger minTemperature;

/**
 天气状况，从服务器获取天气状态后，你需要转换为枚举值对应的天气
 */
@property (nonatomic, assign) HTWWeatherState weatherState;

/**
 当前天气所在城市
 */
@property (nonatomic, strong) NSString *city;

- (NSData*)writeData;
@end
