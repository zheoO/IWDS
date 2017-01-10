/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IWDS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

/**
 * 时间日期同步类
 */
@interface SyncTimeInfo : NSObject <IWDSSafeParcelable>

/** 当前时间 */
@property (assign, nonatomic) long long currenttime;

/** 当前时区 */
@property (copy, nonatomic) NSString *timezoneid;

@end