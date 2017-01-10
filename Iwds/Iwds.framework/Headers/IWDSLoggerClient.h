/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class UIViewController;

/**@brief 打印的log类型*/
typedef NS_ENUM(NSUInteger, IWDSLogLevel) {
    /**不区分类型*/
    IWDSLogLevelNone       = 0,
    /**正常信息的log*/
    IWDSLogLevelInfo       = 1,
    /**警告类型的log*/
    IWDSLogLevelWarn       = 2,
    /**Error类型的Log*/
    IWDSLogLevelError      = 3,
};

/**
 *  @brief 选取log日志回调结果
 *
 *  @param logList      选中的log日志路径数组
 */
typedef void(^IWDSLoggerPikerEventHandler) (NSArray *logPathList);

/**
 *  @brief 自定义LOG
 *
 *  @param file         宏 __FILE__
 *  @param lineNumber   宏 __LINE__
 *  @param functionName 宏 __PRETTY_FUNCTION__
 *  @param logLevel     IWDSLogLevel
 *  @param format       自定义参数
 */
void IWDSExtendNSLog(NSString *format, ...);

@interface IWDSLoggerClient : NSObject

/**
 *  @brief 唯一初始化方法
 *
 *  @return IWDSLoggerClient对象
 */
+ (IWDSLoggerClient *)sharedInstance;

/**
 *  @brief 指定log文件存储的路径
 *
 *  @param cacheDirectory log存储的目录，nil则使用默认目录Library/Caches/IWDSLogger
 *  @param fileName       log文件名，nil则根据日期动态生成文件名 eg.2016-08-08
 */
- (void)startLogWithCacheDirectory:(NSString *)cacheDirectory
                          fileName:(NSString *)fileName;

/**
 *  @brief 配置内存允许存储的最大log
 *
 *  @param maxLine 最大条数.IWDSExtendNSLog执行一次算一条
 *  @param maxSize 占用的最大内存，估算存储空间
 */
- (void)configMemoryMaxLine:(NSInteger)maxLine
                    maxSize:(float)maxSize;

/**
 *  @brief 停止log收集
 */
- (void)stopLog;

@end
