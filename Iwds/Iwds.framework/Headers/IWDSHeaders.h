/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

//#define DEBUG_IWDS

#ifdef DEBUG_IWDS

#import "DeviceDescriptor.h"
#import "IWDSAdapterManager.h"
#import "IWDSAdapter.h"
#import "IWDSLink.h"
#import "IWDSConnection.h"
#import "IWDSSafeParcelable.h"
#import "IWDSDataTransactor.h"

#import "IWDSLog.h"
#import "IWDSAssert.h"
#import "IWDSErrors.h"
#import "IWDSUtils.h"

#else

#import <Iwds/DeviceDescriptor.h>
#import <Iwds/IWDSAdapterManager.h>
#import <Iwds/IWDSAdapter.h>
#import <Iwds/IWDSLink.h>
#import <Iwds/IWDSConnection.h>
#import <Iwds/IWDSSafeParcelable.h>
#import <Iwds/IWDSDataTransactor.h>

#import <Iwds/IWDSLog.h>
#import <Iwds/IWDSAssert.h>
#import <Iwds/IWDSErrors.h>
#import <Iwds/IWDSUtils.h>

#endif
