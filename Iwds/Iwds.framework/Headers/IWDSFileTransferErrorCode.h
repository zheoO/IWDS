/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, IWDSFileTransferErrorCode) {
    IWDSFileTransferErrorCodeNoError,
    IWDSFileTransferErrorCodeFileStatusError,
    IWDSFileTransferErrorCodeNoSdcardError,
    IWDSFileTransferErrorCodeSdcardFullError,
};

//const NSArray *___cIWDSFileTransferErrorCode;
//
//#define cIWDSFileTransferErrorCodeGet (___cIWDSFileTransferErrorCode == nil ? ___cIWDSFileTransferErrorCode = @[@"no error", @"file status", @"no sdcard", @"sdcard full"] : ___cIWDSFileTransferErrorCode)
//
//#define IWDSFileTransferErrorCodeString(type) (cIWDSFileTransferErrorCodeGet[type])