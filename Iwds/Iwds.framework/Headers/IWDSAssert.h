/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@interface IWDSAssert : NSObject
+ (void)dieIf:(BOOL)condition who:(id)who message:(NSString *)message;
@end