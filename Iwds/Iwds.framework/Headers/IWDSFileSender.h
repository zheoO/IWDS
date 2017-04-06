/*
 *  Copyright (C) 2017 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IWDS Project
 */

#import <Foundation/Foundation.h>

@class DeviceDescriptor;

/* -------------------------- 文件发送失败的原因 ------------------------------- */

/** 传输服务通讯异常 */
extern const int IWDSFileSendFailedReasonUniconnectCommunicationException;

/** 无效的压缩参数 */
extern const int IWDSFileSendFailedReasonInvalidCompressOption;

/** 文件正在发送中 */
extern const int IWDSFileSendFailedReasonSendingFileInProgress;

/** 发送文件操作异常（文件IO异常等） */
extern const int IWDSFileSendFailedReasonSendFileOprationException;

/**
 * 文件发送回调接口, 用于更新设备连接和文件发送状态
 */
@protocol IWDSSenderCallback <NSObject>

@required

/**
 * {@code link}连接状态变化回调
 *
 * @param descriptor 连接设备的描述符
 * @param isConnected
 *            true 已连接, false 连接断开
 */
- (void)onLinkConnected:(DeviceDescriptor *)descriptor connected:(BOOL)isConnected;

/**
 * {@code channel} 状态变化回调, 仅当通道可用时才能进行数据传输
 *
 * @param isAvailable
 *            true 通道可用, false 通道不可用
 */
- (void)onChannelAvailable:(BOOL)isAvailable;

/**
 * 文件发送完成回调
 *
 * @param filePath 发送文件的路径
 */
- (void)onSendSuccess:(NSString *)filePath;

/**
 * 文件发送进度回调
 *
 * @param progress 文件发送进度（百分比)
 * @param filePath 发送文件的路径
 */
- (void)onSendProgress:(int)progress filePath:(NSString *)filePath;

/**
 * 文件发送失败回调
 *
 * @param failedReason 发送失败的原因（错误码）
 * @param filePath 发送文件的路径
 */
- (void)onSendFailed:(int)failedReason filePath:(NSString *)filePath;

/**
 * 文件发送被拒绝回调
 *
 * @param deniedReason 拒绝的原因（错误码）
 */
- (void)onSendDenied:(int)deniedReason;

/**
 * 文件发送断点回调，在文件开始发送前回调
 *
 * @param interruptPoint 断点位置
 * @param filePath 文件路径
 */
- (void)onSendInterruptPoint:(long long)interruptPoint filePath:(NSString *)filePath;

@end

/*
 * 文件发送者，与{@code IWDSFileReceiver}配合使用于文件传输
 */
@interface IWDSFileSender : NSObject

/**
 * 返回文件发送失败原因的描述
 *
 * @param reason 接发送失败的原因（错误码）
 * @return 文件发送失败原因的描述
 */
+ (NSString *)failedReasonString:(int)reason;

/**
 * 返回文件发送者实例
 *
 * @param uuid
 * @param delegate
 */
- (instancetype)initWithUuid:(NSString *)uuid delegate:(id <IWDSSenderCallback>)delegate;

/**
 * 返回文件发送者实例
 *
 * @param uuid 连接通道的UUID
 * @param delegate 文件发送的回调接口
 * @param queue 文件发送回调接口所在的Dispatch queue，若为nil，则默认在Main Queue
 */
- (instancetype)initWithUuid:(NSString *)uuid delegate:(id <IWDSSenderCallback>)delegate queue:(dispatch_queue_t)queue;

/**
 * 启动传输服务
 */
- (void)start;

/**
 * 停止传输服务.
 */
- (void)stop;

/**
 * 检查传输服务是否启动.
 *
 * @return 如果已经启动，返回{@code true}，否则返回{@code false}.
 */
- (BOOL)isStarted;

/**
 * 使用非压缩方式发送文件
 *
 * @param filePath 发送的文件路径
 * @return 发送时若通道不可用则返回false，否则返回true
 */
- (BOOL)send:(NSString *)filePath;

/**
 * 使用默认的压缩算法和压缩等级发送文件
 *
 * @param file 发送的文件
 * @return 发送时若通道不可用则返回false，否则返回true
 */
- (BOOL)sendCompressed:(NSString *)filePath;

/**
 * 自定义压缩算法和压缩等级发送文件，参考
 * {@link com.ingenic.iwds.uniconnect.Connection.CompressAlgorithm CompressAlgorithm}，
 * {@link com.ingenic.iwds.uniconnect.Connection.CompressLevel CompressLevel}
 *
 * @param file 发送的文件
 * @param compressAlgorithm 压缩算法
 * @param compressLevel 发送等级
 * @return 发送时若通道不可用则返回false，否则返回true
 */
- (BOOL)sendCompressedUser:(NSString *)filePath compressAlgorithm:(int)compressAlgorithm compressLevel:(int)compressLevel;

@end
