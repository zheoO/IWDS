/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

#import "IWDSSafeParcelable.h"

@class  DeviceDescriptor;
extern const int REQUEST_SUCCESS;
extern const int REQUEST_NOTIFY_UNBOND_FAILD;
extern const int TYPE_NOTIFY_UNBOND;

@interface IWDSRemoteDeviceManagerInfo : NSObject

@end

@interface RemoteResponse : NSObject <IWDSSafeParcelable>

@property (nonatomic) int   type;
@property (nonatomic) int   returnCode;

- (instancetype)initWithType:(int)type;
- (instancetype)initWithType:(int)type returnCode:(int)returnCode;

- (void)readFromParcel:(IWDSSafeParcel *)parcel;

@end

@interface RemoteRequest : NSObject <IWDSSafeParcelable>

@property (copy, nonatomic) NSString    *packageName;
@property (copy, nonatomic) NSString    *apkFilePath;

@property (assign, nonatomic) int       type;
@property (assign, nonatomic) int       subType;
@property (assign, nonatomic) int       value;
@property (assign, nonatomic) long long requiredSize;
@property (assign, nonatomic) BOOL      isInstalledInExternal;

- (instancetype)initWithType:(int)type;
- (instancetype)initWithType:(int)type subType:(int)subType;
- (instancetype)initWithType:(int)type subType:(int)subType value:(int)value;
- (instancetype)initWithType:(int)type packageName:(NSString *)packageName;
- (instancetype)initWithType:(int)type packageName:(NSString *)packageName apkFilePath:(NSString *)apkFilePath
                requiredSize:(long long)requiredSize isInstalledInExternal:(BOOL)isInstalledInExternal;

@end

@interface UnbondRequest : RemoteRequest

@property (retain, nonatomic) DeviceDescriptor *deviceDescriptor;

- (instancetype)initWithDeviceDescriptor:(DeviceDescriptor *)deviceDescriptor;

@end