/*
 *  Copyright (C) 2017 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IWDS Project
 */

#import <Foundation/Foundation.h>

@class DeviceDescriptor;

/* -------------------------- 文件接收失败的原因 ------------------------------- */

/** 传输服务通讯异常 */
extern const int IWDSFileReceiveFailedReasonUniconnectCommunicationException;

/** SDCARD不可用 */
extern const int IWDSFileReceiveFailedReasonExternalStorageUniavailable;

/** SDCARD存储空间不足 */
extern const int IWDSFileReceiveFailedReasonExternalStorageNoSpace;

/** 无法创建文件接收目录 */
extern const int IWDSFileReceiveFailedReasonCanNotCreateBaseDir;

/** 接收文件被损坏 */
extern const int IWDSFileReceiveFailedReasonReceivingFileException;

/* ---------------------------- 拒接文件的原因 ------------------------------- */

/** SDCARD不可用 */
extern const int IWDSFileDeniedReceiveReasonExternalStorageUniavailable;

/** SDCARD存储空间不足 */
extern const int IWDSFileDeniedReceiveReasonExternalStorageNoSpace;

/** 无法创建文件接收目录 */
extern const int IWDSFileDeniedReceiveReasonCanNotCreateBaseDir;

/** 接收文件被损坏 */
extern const int IWDSFileDeniedReceiveReasonReceivingFileException;

/** 用户拒绝接收 */
extern const int IWDSFileDeniedReceiveReasonUserDeniedForReceiveFile;

/**
 * 文件接收回调接口, 用于更新设备连接和文件接收状态
 */
@protocol IWDSFileReceiverDelegate <NSObject>

@required

/**
 * {@code link}连接状态变化回调
 *
 * @param descriptor 连接设备的描述符
 * @param isConnected
 *            true 已连接, false 连接断开
 */
- (void)onLinkConnected:(DeviceDescriptor *)descriptor isConnected:(BOOL)isConnected;

/**
 * {@code channel} 状态变化回调, 仅当通道可用时才能进行数据传输
 *
 * @param isAvailable
 *            true 通道可用, false 通道不可用
 */
- (void)onChannelAvailable:(BOOL)isAvailable;

/**
 * 文件接收完成回调
 *
 * @param filePath 接收到的文件的路径
 */
- (void)onFileArrived:(NSString *)filePath;

/**
 * 文件接收进度回调
 *
 * @param filePath 接收到的文件的路径
 * @param progress 接收进度（百分比）
 */
- (void)onFileReceiveProgress:(int)progress filePath:(NSString *)filePath;

/**
 * 文件接收失败回调
 *
 * @param failedReason 接收失败的原因（错误码）
 */
- (void)onFileReceiveFailed:(int)reason;

@end

/**
 * 接收到文件发送请求的回调接口，用于在接收到文件发送请求时通知用户
 */
@protocol IWDSFileReceiverConfirmDelegate <NSObject>

@required

/**
 * 文件发送请求回调
 *
 * @param fileName 文件名
 * @param fileLength　文件长度
 * @param interruptedPoint 断点位置，非断点传输时为0
 */
- (void)onRequestSendFile:(NSString *)fileName fileLength:(long long)fileLength interruptedPoint:(long long)interruptedPoint;

@end

/**
 * 文件接收者，与 {@code IWDSFileSender} 配合使用于文件传输
 */
@interface IWDSFileReceiver : NSObject

/**
 * 返回文件接收失败原因的描述
 *
 * @param reason 接收失败的原因（错误码）
 * @return 文件接收失败原因的描述
 */
+ (NSString *)failedReasonString:(int)reason;

/**
 * 返回文件接收拒绝原因的描述
 *
 * @param reason 拒绝原因（错误码）
 * @return 文件接收拒绝原因的描述
 */
+ (NSString *)deniedReasonString:(int)reason;

/**
 * 返回IWDSFileReceiver实例
 *
 * @param uuid 连接通道对应的UUID
 * @param delegate 文件接收回调
 * @return IWDSFileReceiver实例
 */
- (instancetype)initWithUuid:(NSString *)uuid delegate:(id <IWDSFileReceiverDelegate>)delegate;

/**
 * 返回IWDSFileReceiver实例
 *
 * @param uuid 连接通道对应的UUID
 * @param delegate 文件接收回调
 * @param queue 文件接收回调所在的队列，为nil时，默认在Main Queue
 * @return IWDSFileReceiver实例
 */
- (instancetype)initWithUuid:(NSString *)uuid delegate:(id <IWDSFileReceiverDelegate>)delegate queue:(dispatch_queue_t)queue;

/**
 * 文件接收确认回调，当收到文件发送请求时回调，若未设置该回调接口，则默认允许接收
 */
@property (nonatomic, weak) id <IWDSFileReceiverConfirmDelegate> confirmDelegate;

/**
 * 文件发送请求回调接口所在的Queue，默认在Main Queue
 */
@property (nonatomic) dispatch_queue_t confirmDelegateQueue;

/**
 * 启动传输服务
 */
- (void)start;

/**
 * 停止传输服务
 */
- (void)stop;

/**
 * 检查传输服务是否启动.
 *
 * @return 如果已经启动，返回{@code true}，否则返回{@code false}.
 */
- (BOOL)isStarted;

/**
 * 通知远端设备: 确认接收文件
 */
- (void)notifyAllowForReceiveFile;

/**
 * 通知远端设备: 拒绝接收文件
 */
- (void)notifyDenyForReceiveFile;

/**
 * 设置文件接收目录，默认存储目录为/sdcard/iwds/<br/>
 * 请确保存储目录有效（目录存在或可被创建），该设置将在下次文件接收时生效。
 *
 * @return 返回true表示设置成功，否则返回false
 */
- (BOOL)setFileReceiveDirectory:(NSString *)dir;

@end
