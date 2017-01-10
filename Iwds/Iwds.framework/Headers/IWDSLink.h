/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class  IWDSRemoteDeviceDescriptorStorage;
@class  IWDSConnection;
@class  IWDSLinkManager;
@class  DeviceDescriptor;

/**
 * @abstract 链接类.
 */
@interface IWDSLink : NSObject

extern NSString *const    IWDS_ACTION_DISCONNECTED_ADDRESS;
extern NSString *const    IWDS_ACTION_CONNECTED_ADDRESS;

typedef NS_ENUM (int, IWDSLinkState) {
    IWDSLinkStateDisconnected = 0,
    IWDSLinkStateConnected
};

@property (atomic, assign, readonly) IWDSLinkState  linkState;
@property (nonatomic, readonly) NSString            *linkTag;

- (instancetype)initWithLinkManager:(IWDSLinkManager *)linkManager deviceDescriptor:(DeviceDescriptor *)deviceDescriptor linkTag:(NSString *)linkTag;

- (NSString *)getBondedAddress;
- (BOOL)bondAddress:(NSString *)address;
- (BOOL)isBonded;
- (void)unbond;
- (BOOL)isServerStarted;
- (BOOL)startServer;
- (void)stopServer;
- (BOOL)isRoleAsClientSide;
- (DeviceDescriptor *)getLocalDescriptor;

- (void)onLinkStateChanged:(int)state address:(NSString *)address;
@end
