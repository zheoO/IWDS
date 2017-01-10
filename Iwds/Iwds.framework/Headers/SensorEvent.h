/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

/**
 * 描述语音唤醒系统事件的常量，当且仅当系统唤醒时才产生该事件
 */
extern const int IWDS_SENSOR_EVENT_WAKE_UP;

/**
 * 描述手势传感器上报的手势
 */
typedef NS_ENUM(int, IWDSSensorGesture) {

    /**
     * 摇晃手腕
     */
    IWDSSensorGestureShakeHand = 1,

    /**
     * 抬起手腕
     */
    IWDSSensorGestureRaiseHandAndLook,

    /**
     * 放下手腕
     */
    IWDSSensorGestureLetHandDownAfterLook,

    /**
     * 翻转手腕
     */
    IWDSSensorGestureTurnWrist,
};

/**
 * 描述运动状态
 */
typedef NS_ENUM(int, IWDSSensorMotion) {

    /**
     * 静止
     */
    IWDSSensorMotionReset,

    /**
     * 运动停止
     */
    IWDSSensorMotionStop,

    /**
     * 正在走路
     */
    IWDSSensorMotionWalk,

    /**
     * 正在跑步
     */
    IWDSSensorMotionRun,

    /**
     * 睡眠
     */
    IWDSSensorMotionSleep,

    /**
     * 深睡
     */
    IWDSSensorMotionDeepSleep,
};

typedef NS_ENUM(int, IWDSSensorAccuracy) {

    /**
     * 该变量只应用于原相心率，仅在获取当前传感器厂商返回值为"PixArt"时有效。
     * <p>更多详细参考 Sensor vendor
     *
     * 目前心率传感器上报的精度值有两种，
     * 分别为IWDSSensorAccuracyHeartRateUnavaliable和IWDSSensorAccuracyHeartRateAvaliable。
     *
     * 当上报精度为IWDSSensorAccuracyHeartRateUnavaliable时，表示心率传感器工作状态不正常，
     * 有可能是心率没有正常接触人体皮肤，或者手表佩戴不适导致测量心率超时。
     */
    IWDSSensorAccuracyHeartRateUnavaliable = 1,

    /**
     * 该变量只应用于原相心率，仅在获取当前传感器厂商返回值为"PixArt"时有效。
     * <p>更多详细参考 Sensor vendor
     *
     * 目前心率传感器上报的精度值有两种，
     * 分别为IWDSSensorAccuracyHeartRateUnavaliable和IWDSSensorAccuracyHeartRateAvaliable。
     *
     * 当上报精度为IWDSSensorAccuracyHeartRateAvaliable时，表示心率传感器工作状态正常，
     * 手表佩戴良好，心率测量数据即将上报（通常会在1～5s内上报心率数据）。
     */
    IWDSSensorAccuracyHeartRateAvaliable,
};

/**
 * 传感器事件类, 该类表示一个 Sensor 事件, 并且保存传感器类型, 精度以及传感器的数据 values 等信息.
 *
 * @see IWDSRemoteSensorManager
 * @see Sensor
 */
@interface SensorEvent : NSObject <IWDSSafeParcelable>

/**
 * 传感器数据
 *
 * 当监听原相心率事件，且在获取当前传感器厂商返回值为"PixArt"时以下有效：
 * <p>更多详细参考 Sensor vender
 
 * values[0]为心率值，values[1]为传感器精度值
 * （有效值为IWDSSensorAccuracyHeartRateUnavaliable或者IWDSSensorAccuracyHeartRateAvaliable）。
 */
@property (nonatomic, retain)NSMutableArray *values;

/**
 * 传感器数据精度
 */
@property (nonatomic)int accuracy;

/**
 * 传感器类型
 */
@property (nonatomic)int sensorType;

/**
 * 传感器事件时间戳
 */
@property (nonatomic)long long timeStamp;

- (instancetype)initWithValueSize:(int)valueSize;

@end