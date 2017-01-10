/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSDataTransactor.h"
#import "IWDSSafeParcelable.h"

@class DeviceDescriptor;

/**
 * 数据传输请求
 */
static NSString *CMD_REQUEST = @"provider_transaction_request_cmd";

/**
 * 请求失败
 */
static NSString *CMD_REQUEST_FAILED = @"provider_transaction_request_failed_cmd";

/**
 * 数据传输回调接口, 用于更新设备连接和数据传输状态
 */
@protocol IWDSProviderTransactionModelCallback <NSObject>

@optional

/**
 * 数据传输请求回调
 */
- (void)onRequest;

/**
 * 远端设备通知传输失败回调
 */
- (void)onRequestFailed;

/**
 * 数据接收完成回调
 * @param object
 *        接收到的数据
 */
- (void)onObjectArrived:(id)object;

/**
 * IWDSLink 连接状态变化回调
 */
- (void)onLinkConnected:(DeviceDescriptor *)descriptor isConnected:(BOOL)isConnected;

/**
 * Channel 状态变化回调, 仅当通道可用时才能进行数据传输
 *
 * @param isAvailable
 *        YES 通道可用, NO 通道不可用
 */
- (void)onChannelAvailable:(BOOL)isAvailable;

/**
 * 发送结果回调, 用于检查发送是否成功, 注意每次发送之前需要检查上次发送是否成功
 * @param result IWDSDataTransactResult
 */
- (void)onSendResult:(IWDSDataTransactResult *)result;

@end

/**
 * 通用数据传输模型, 实现了 IWDSDataTransactorCallback 接口, 用于更新连接和传输状态
 */
@interface IWDSProviderTransactionModel : NSObject <IWDSDataTransactorCallback>

/**
 * 构造 {@code ProviderTransactionModel}
 *
 * @param callback
 *        回调接口 IWDSProviderTransactionModelCallback 用于更新连接和传输状态
 * @param uuid
 *        UUID
 */
- (instancetype)initWithUuid:(NSString *)uuid creator:(id <IWDSSafeParcelableCreator>)creator callback:(id <IWDSProviderTransactionModelCallback>)callback;

/**
 * 发送数据
 * @param object
 *        待发送的数据 IWDSTransferAdapter
 */
- (void)send:(id)object;

/**
 * 发送传输请求
 * Notice:暂时不可用，Android端的数据类型不对应(Serializable).
 */
- (void)request;

/**
 * 通知远端设备传输请求失败
 * Notice:暂时不可用，Android端的数据类型不对应(Serializable).
 */
- (void)notifyRequestFailed;

/**
 * 连接 IWDSConnection 互连
 */
- (void)start;

/**
 * 检查传输服务是否启动.
 *
 * @return 如果已经启动，返回YES.
 */
- (BOOL)isStarted;

/**
 * 断开 IWDSConnection 互连
 */
- (void)stop;

@end