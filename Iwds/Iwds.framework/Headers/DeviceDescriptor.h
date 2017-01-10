/*
 *  Copyright (C) 2014 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 *
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

/** 穿戴式设备 */
extern const int IWDS_DEVICE_CLASS_WEARABLE;

/** 智能家居设备 */
extern const int IWDS_DEVICE_CLASS_SMARTHOME;

/** 移动设备 */
extern const int IWDS_DEVICE_CLASS_MOBILE;

/*
 * for wearable devices
 */
/** 穿戴式设备子类：手表 */
extern const int IWDS_WEARABLE_DEVICE_SUBCLASS_WATCH;

/** 穿戴式设备子类：眼镜 */
extern const int IWDS_WEARABLE_DEVICE_SUBCLASS_GLASS;

/*
 * for mobile devices
 */
/** 移动设备子类：智能手机 */
extern const int IWDS_MOBILE_DEVICE_SUBCLASS_SMARTPHONE;

@interface DeviceDescriptor : NSObject <IWDSSafeParcelable, NSCopying>

/** 设备地址 */
@property (nonatomic) NSString *devAddress;

/** 连接标记 */
@property (nonatomic) NSString *linkTag;

/** 设备类别 */
@property (nonatomic) int devClass;

/** 设备子类别 */
@property (nonatomic) int devSubClass;

/** 型号 */
@property (nonatomic) NSString *model;

/** 厂家 */
@property (nonatomic) NSString *manufacture;

/** 序列号 */
@property (nonatomic) NSString *serialNo;

@property (nonatomic) NSString *displayID;

/** android api等级 */
@property (nonatomic) int androidApiLevel;

/** iwds版本 */
@property (nonatomic) int iwdsVersion;

/** LCD外型 */
@property (nonatomic) NSString *lcdExterior;

/** LCD尺寸 */
@property (nonatomic) NSString *lcdSize;

- (instancetype)initWithDeviceAddress  :(NSString *)deviceAddress
                deviceLinkTag           :(NSString *)deviceLinkTag
                deviceClass             :(int)deviceClass
                deviceSubClass          :(int)deviceSubClass;

@end