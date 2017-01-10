/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

extern NSString * const IWDSErrorDomain;

typedef NS_ENUM(NSInteger, IWDSError) {
    IWDSErrorNoError = 0,
    IWDSErrorLinkUnbonded = -1,
    IWDSErrorLinkDisconnected = -2,
    IWDSErrorPortBusy = -3,
    IWDSErrorPortClosed = -4,
    IWDSErrorPortDisconnected = -5,
    IWDSErrorDisabled = -6
};

extern NSString * const IWDSErrorDescriptionLinkUnbonded;
extern NSString * const IWDSErrorDescriptionLinkDisconnected;
extern NSString * const IWDSErrorDescriptionPortBusy;
extern NSString * const IWDSErrorDescriptionPortClosed;
extern NSString * const IWDSErrorDescriptionPortDisconnected;

