/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import <Iwds/IWDSDataTransactor.h>

@class DeviceDescriptor;

@protocol IWDSRemoteDeviceUnbondDelegate <NSObject>

@required

- (void)onRequestDeviceUnbondResult:(int)resultCode;

@end

@interface IWDSRemoteDeviceManager : NSObject <IWDSDataTransactorCallback>

+ (instancetype)shareInstance;

- (void)startTransaction;
- (void)stopTransaction;

- (void)registerUnbondDelegate:(NSString *)uuid delegate:(id <IWDSRemoteDeviceUnbondDelegate>)delegate;
- (void)unregisterUnbondDelegate:(NSString *)uuid;

- (void)requestNotifyUnbondDeviceDescriptor:(DeviceDescriptor *)descriptor uuid:(NSString *)uuid;

@end