/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

extern const int IWDSSensorTypeBase;

/**
 * 描述心率传感器的常量
 */
extern const int IWDSSensorTypeHeartRate;

/**
 * 描述紫外线传感器的常量
 */
extern const int IWDSSensorTypeUv;

/**
 * 描述特定手势传感器的常量
 */
extern const int IWDSSensorTypeGesture;

/**
 * 描述特定动作传感器的常量
 */
extern const int IWDSSensorTypeMotion;

/**
 * 描述语音唤醒传感器的常量
 */
extern const int IWDSSensorTypeVoiceTrigger;

/**
 * 描述计步传感器的常量
 */
extern const int IWDSSensorTypeStepCounter;

/**
 * 描述环境湿度传感器的常量
 */
extern const int IWDSSensorTypeRelativeHumidity;

/**
 * 描述环境温度传感器的常量
 */
extern const int IWDSSensorTypeAmbientTemperature;

/**
 * 描述大气压力传感器的常量
 */
extern const int IWDSSensorTypePressure;

/**
 * 描述距离传感器的常量
 */
extern const int IWDSSensorTypeProximity;

/**
 * 描述所有传感器的常量, 不要使用
 */
extern const int IWDSSensorTypeAll;

/**
 * 传感器类
 */
@interface Sensor : NSObject <IWDSSafeParcelable>

/**
 * 传感器的类型
 */
@property (nonatomic)int sensorType;

/**
 * 传感器的最大采集数据范围
 */
@property (nonatomic)float maxRange;

/**
 * 传感器的数值数据采集分辨率
 */
@property (nonatomic)float resolution;

/**
 * 传感器上报事件之间的最小延时
 */
@property (nonatomic)int minDelay;

/**
 * 传感器的名字
 */
@property (nonatomic, retain)NSString *sensorName;

/**
 * 传感器的版本
 */
@property (nonatomic)int version;

/**
 * 传感器的厂商
 */
@property (nonatomic, retain)NSString *vendor;

@end