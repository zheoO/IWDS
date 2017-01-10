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
 * 区域类
 */
@interface LocaleInfo : NSObject <IWDSSafeParcelable>

/** 语言 */
@property (copy, nonatomic) NSString *language;

/** 国家 */
@property (copy, nonatomic) NSString *country;

@end
