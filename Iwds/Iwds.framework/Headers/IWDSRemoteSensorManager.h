/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSDataTransactor.h"

@class  Sensor;
@class  SensorEvent;

@protocol IWDSRemoteSensorEventDelegate <NSObject>

- (void)sensorChanged:(SensorEvent *)event;

- (void)accuracyChanged:(Sensor *)sensor accuracy:(int)accuracy;

@end

@protocol IWDSRemoteSensorDelegate <NSObject>

- (void)sensorAvailabled:(NSArray *)sensors;

@end

@interface IWDSRemoteSensorManager : NSObject <IWDSDataTransactorCallback>

+ (instancetype)shareInstance;

- (void)startTransaction;

- (void)stopTransaction;

- (BOOL)addDelegate:(NSString *)uuid delegate:(id <IWDSRemoteSensorDelegate>)delegate;

- (void)removeDelegate:(NSString *)uuid;

/**
 * 使用该方法获取远端设备传感器列表
 *
 * @return 返回传感器列表
 */
- (NSArray *)listSensors;

/**
 * 使用该方法获取指定类型的远端传感器
 *
 * @param sensorType 传感器类型
 * @return 返回指定类型的传感器
 */
- (Sensor *)defaultSensor:(int)sensorType;

- (BOOL)registerDelegate:(NSString *)uuid delegate:(id <IWDSRemoteSensorEventDelegate>)delegate sensor:(Sensor *)sensor rate:(int)rate;

- (void)unregisterDelegate:(NSString *)uuid;

@end