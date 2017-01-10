/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@interface IWDSUtils : NSObject

/**
 * 获取当前应用名称
 */
+ (NSString *)getApplicationName;

/**
 * 立刻发送通知
 */
+ (void)presentLocalNotificationNow:(NSString *)alertTitle alertBody:(NSString *)alertBody alertAction:(NSString *)alertAction userInfo:(NSDictionary *)userInfo;

@end