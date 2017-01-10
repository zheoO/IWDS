/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSLoggerClient.h"
#import "IWDSLoggerManager.h"

#define LOG_DEBUG    1
#define LOG_VERBOSE  1

#define LOG_PREFIX  (@"IWDS---")

/**
 如下定义了LOG输出宏，对是否定义LOG_DEBUG分别作了特殊处理
     模 式         标 识       DEBUG           RELEASE
 1、IWDSLog         -       打印到控制台        输出到文件
 2、IWDSLogV        V       打印到控制台        输出到文件
 3、IWDSLogD        D       打印到控制台        输出到文件
 4、IWDSLogI        I       打印到控制台        输出到文件
 5、IWDSLogW        W       打印到控制台        输出到文件
 6、IWDSLogE        E       打印到控制台        输出到文件
 */

#ifdef DEBUG

#define IWDSLog(fmt,...)  NSLog(@"%@", [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogV(fmt,...) if(LOG_DEBUG) NSLog(@"V/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogD(fmt,...) if(LOG_DEBUG) NSLog(@"D/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogI(fmt,...) NSLog(@"I/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogW(fmt,...) NSLog(@"W/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogE(fmt,...) NSLog(@"E/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);

#else

#define IWDSLog(fmt,...)  IWDSExtendNSLog([NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogV(fmt,...) if(LOG_DEBUG) IWDSExtendNSLog(@"V/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogD(fmt,...) if(LOG_DEBUG) IWDSExtendNSLog(@"D/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogI(fmt,...) IWDSExtendNSLog(@"I/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogW(fmt,...) IWDSExtendNSLog(@"W/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);
#define IWDSLogE(fmt,...) IWDSExtendNSLog(@"E/%@ %@ %@\n", LOG_PREFIX, self, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]);

#endif

@interface IWDSTrace : NSObject
- (instancetype)initWithTag:(NSString *)tag funcName:(NSString *)funcName;
@end

#define IWDS_TRACE_LOG IWDSTrace *trace = [[IWDSTrace alloc] initWithTag:LOG_TAG funcName:[NSString stringWithUTF8String:__func__]]
