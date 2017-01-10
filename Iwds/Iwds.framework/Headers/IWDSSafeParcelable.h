/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class IWDSSafeParcel;

extern const int PARCELABLE_WRITE_RETURN_VALUE;
extern const int CONTENTS_FILE_DESCRIPTOR;

@protocol IWDSSafeParcelableCreator <NSObject>

- (id)createFromParcel:(IWDSSafeParcel *)source;

- (NSMutableArray *)newArray:(int)size;

@end

@protocol IWDSSafeParcelable <NSObject>

/**
 * 对应的android端的java包名+类名
 */
@property (nonatomic, readonly) NSString *androidClassName;

- (int)describeContents;

- (void)writeToParcel:(IWDSSafeParcel *)dest flags:(int)flags;

+ (id <IWDSSafeParcelableCreator>)creator;
@end