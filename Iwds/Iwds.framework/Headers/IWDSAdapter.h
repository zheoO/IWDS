/*
 *  Copyright (C) 2016, Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class  IWDSLink;
@class  DeviceDescriptor;
@class  IWDSAdapterManager;

extern NSString *const  IWDSLinkTagBleDataChannel;
extern NSString *const  IWDSLinkTagWifiDataChannel;

extern NSString *const  IWDSAdapterStateChanged;

@interface IWDSAdapter : NSObject

@property (nonatomic) NSString          *localAddress;
@property (nonatomic) NSString          *linkTag;
@property (nonatomic) BOOL              enabled;

+ (instancetype)adapterWithAdapterManager   :(IWDSAdapterManager *)adapterManager
                linkTag                     :(NSString *)linkTag;
- (instancetype)initWithAdapterManager  :(IWDSAdapterManager *)adapterManager
                linkTag                 :(NSString *)linkTag;
- (IWDSLink *)createLink:(DeviceDescriptor *)descriptor;
- (void)destroyLink:(IWDSLink *)link;
- (void)onLinkStateChanged  :(int)state isRoleAsClient:(BOOL)isRoleAsClient
        address             :(NSString *)address;

/**
 * Do nothing now
 */
- (BOOL)enable;

/**
 * Do nothing now
 */
- (void)disable;

- (BOOL)isEnabled;

- (NSArray *)getBondedAddressStorage;
@end
