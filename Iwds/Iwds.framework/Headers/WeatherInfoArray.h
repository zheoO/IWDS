/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IWDS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

/** 天气预报信息类 */
@interface WeatherInfoArray : NSObject <IWDSSafeParcelable>

/** 天气预报数据 */
@property (copy, nonatomic) NSArray *data;

/** 通过天气信息数组初始化天气预报 */
- (instancetype)initWithArray:(NSArray *)weatherArray;

@end

/** 天气信息类 */
@interface WeatherInfo : NSObject <IWDSSafeParcelable>

/** 城市. */
@property (copy, nonatomic) NSString *city;

/** 天气描述（比如：多云）. */
@property (copy, nonatomic) NSString *weather;

/** 天气图标代码（引用自雅虎天气）. */
@property (copy, nonatomic) NSString *weatherCode;

/** 日期. */
@property (copy, nonatomic) NSString *date;

/** 星期. */
@property (copy, nonatomic) NSString *dayOfWeek;

/** 发布时间. */
@property (copy, nonatomic) NSString *updateTime;

/** 气温单位（'c'摄氏度，'f'华氏度）. */
@property (copy, nonatomic) NSString *tempUnit;

/** 当前实时气温. */
@property (assign, nonatomic) int currentTemp;

/** 最低气温. */
@property (assign, nonatomic) int minimumTemp;

/** 最高气温. */
@property (assign, nonatomic) int maximumTemp;

/** 日期索引. */
@property (assign, nonatomic) int dayIndex;

@end