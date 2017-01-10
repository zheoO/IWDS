/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

#import <Iwds/IWDSTransferAdapter.h>

@class DeviceDescriptor;

extern const int    IWDSDataTransactorResultOk;
extern const int    IWDSDataTransactorResultFailedChannelUnavailable;
extern const int    IWDSDataTransactorResultFailedLinkDisconnected;
extern const int    IWDSDataTransactorResultFailedFileStatusError;

/**
 * 描述对象传输时, 选择了一个不支持的压缩选项
 */
extern const int IWDSDataTransactorResultFailedInvalidCompressOption;

@interface IWDSDataTransactResult : NSObject

@property (nonatomic) int   resultCode;
@property (nonatomic) id    transferedObject;
@property (nonatomic) BOOL  isFileTransfer;

@end

@protocol IWDSDataTransactorCallback <NSObject>

@optional

/**
 * link连接状态变化回调
 */
- (void)onLinkConnected:(DeviceDescriptor *)descriptor isConnected:(BOOL)isConnected;

/**
 * channel状态变化回调, 仅当通道可用时才能进行数据传输
 *
 * @param isAvailable
 *            true 通道可用, false 通道不可用
 */
- (void)onChannelAvailable:(BOOL)isAvailable;

/**
 * 发送结果回调, 用于检查发送是否成功, 注意每次发送之前需要检查上次发送结果是否成功
 *
 * @param result
 *            通信结果
 */
- (void)onSendResult:(IWDSDataTransactResult *)result;

/**
 * 数据接收完成回调
 *
 * @param object
 *            接收到的数据
 */
- (void)onDataArrived:(id)object;

/**
 * 文件发送进度变化回调
 *
 * @param progress
 *            发送进度
 */
- (void)onSendFileProgress:(int)progress;

/**
 * 文件接收进度变化回调
 *
 * @param progress
 *            接收进度
 */
- (void)onRecvFileProgress:(int)progress;

/**
 * 文件发送中断回调
 *
 * @param index
 *            发送断点
 */
- (void)onSendFileInterrupted:(int)index;

/**
 * 文件接收中断回调
 *
 * @param index
 *            接收断点
 */
- (void)onRecvFileInterrupted:(int)index;

@end

@interface IWDSDataTransactor : NSObject <IWDSTransferAdapterCallback>

- (instancetype)initWithUuid:(NSString *)uuid callback:(id <IWDSDataTransactorCallback>)callback;
- (instancetype)initWithUuid:(NSString *)uuid creator:(id <IWDSSafeParcelableCreator>)creator
                callback    :(id <IWDSDataTransactorCallback>)callback;

- (instancetype)initWithUuid:(NSString *)uuid callback:(id <IWDSDataTransactorCallback>)callback
                queue       :(dispatch_queue_t)queue;
- (instancetype)initWithUuid:(NSString *)uuid creator:(id <IWDSSafeParcelableCreator>)creator
                callback    :(id <IWDSDataTransactorCallback>)callback queue:(dispatch_queue_t)queue;

- (void)start;
- (void)stop;
- (BOOL)isStarted;
- (void)cancelAll;
- (void)send:(id)object;

/**
 * 以数据压缩方式发送对象
 */
- (void)sendCompressed:(id)object;

/**
 * 以自定义数据压缩参数发送对象
 */
- (void)sendCompressedUser  :(id)object compressAlgorithm:(int)compressAlgorithm
        compressLevel       :(int)compressLevel;

- (void)sendFile:(NSString *)filePath;
- (void)sendFile:(NSString *)filePath chunkIndex:(int)chunkIndex;

/**
 * 以数据压缩方式发送文件
 */
- (void)sendFileCompressed:(NSString *)filePath chunkIndex:(int)chunkIndex;

/**
 * 以自定义数据压缩参数发送文件
 */
- (void)sendFileCompressedUser  :(NSString *)filePath chunkIndex:(int)chunkIndex
        compressAlgorithm       :(int)compressAlgorithm compressLevel:(int)compressLevel;
@end