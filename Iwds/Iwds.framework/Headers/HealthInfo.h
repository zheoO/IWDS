/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IWDS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

/**
 * 记录类.
 */
@interface Record : NSObject <IWDSSafeParcelable>

/** 开始时间 */
@property (assign, nonatomic) long long startTime;

/** 结束时间 */
@property (assign, nonatomic) long long endTime;

/** 睡眠类型（深睡/浅睡） */
@property (assign, nonatomic) int type;

@end

/** 描述运动状态： 静放 */
static const int MOTION_RESET = 0;

/** 描述运动状态： 运动停止 */
static const int MOTION_STOP = 1;

/** 描述运动状态： 正在走路 */
static const int MOTION_WALK = 2;

/** 描述运动状态： 正在跑步 */
static const int MOTION_RUN = 3;

/** 描述运动状态： 正在车上（单车，公交，开车） */
static const int MOTION_VEHICLE = 4;

/** 描述运动状态： 无含义，保留 */
static const int MOTION_MAX = 5;

/** 描述睡眠状态： 睡眠 */
static const int MOTION_SLEEP = 6;

/** 描述睡眠状态： 深睡 */
static const int MOTION_DEEP_SLEEP = 7;

/** 描述运动状态： 跌倒 */
static const int MOTION_FALL = 64;

@interface HealthInfo : NSObject <IWDSSafeParcelable>

/** 睡眠监测日期 */
@property (assign, nonatomic) long long recordDate;

/** 总睡眠时间/小时 */
@property (assign, nonatomic) long long sleepTime;

/** 深睡时间/小时 */
@property (assign, nonatomic) long long deepSleepTime;

/** 浅睡时间/小时 */
@property (assign, nonatomic) long long lightSleepTime;

/** 睡眠质量/五星等级（1～５） */
@property (assign, nonatomic) int sleepQuality;

/** 睡眠监测记录数 */
@property (assign, nonatomic) int sleepRecordCount;

/** 睡眠记录详情 record[] */
@property (retain, nonatomic) NSArray *record;

/**
 * 表示2-24点（每隔2点的总步数）. 12个数据，但是并不一定每一个都有意义，只有小于或者等于当前小时数的数据才有意义.
 */
@property (retain, nonatomic) NSArray *days;

/** 表示按天记录的计步. 7个数据（暂时只右一周，后面再做修改）. */
@property (retain, nonatomic) NSArray *weeks;

/** 表示心率[A[rate,time]A[rate,time]] */
@property (copy, nonatomic) NSString *rates;

/** 手表当前时间的long型(可精确到秒，具体看手表端的需求，从该值可以得到days字符串的长度) */
@property (assign, nonatomic) long long nowDate;

/** 温度值 */
@property (assign, nonatomic) int temp;

/** 湿度值 */
@property (assign, nonatomic) int humidity;

/** 气压值 */
@property (assign, nonatomic) int pressure;

/** 　紫外线强度 */
@property (assign, nonatomic) int uitravioletIntensity;

/** 海拔高度 */
@property (copy, nonatomic) NSString *altitude;

@property (assign, nonatomic) int       _id;
@property (assign, nonatomic) int       command;
@property (assign, nonatomic) int       type;
@property (copy, nonatomic) NSString    *data;

/**
 * 实例化健康信息类
 *
 * @param count
 *            睡眠监测记录数
 */
- (instancetype)initWithCount:(int)count;

/**
 * 对应Android5.1版本手表的数据
 */
- (NSString *)descriptionForAndroidLollipop;

@end