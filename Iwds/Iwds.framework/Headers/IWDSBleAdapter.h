/*
 *  Copyright (C) 2016, Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSAdapter.h"

@protocol ScanDeviceMatchRule <NSObject>

@optional

- (BOOL)matchDevice:(NSDictionary <NSString *, id> *)advertisementData;

@end

@interface IWDSBleAdapter : IWDSAdapter

/**
 * 设置BLE设备扫描的匹配规则
 */
- (void)setScanDeviceMatchRule:(id <ScanDeviceMatchRule>)matchRule serviceUuid:(NSString *)serviceUuid;

- (BOOL)isEnabled;

/**
 * Deprecated
 */
- (void)saveBleConnectionState;

- (void)notifyRemoteToDisconnect;

- (void)setMTU:(NSUInteger)mtu;

@end
