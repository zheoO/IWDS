/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class IWDSConnection;
@protocol IWDSSafeParcelable;
@protocol IWDSSafeParcelableCreator;

@protocol IWDSTransferAdapterCallback <NSObject>

@optional

/**
 * 文件发送进度回调
 *
 * @param currentBytes
 *            当前已发送的字节数
 * @param totalBytes
 *            发送数据总大小
 */
- (void)onSendFileProgress:(long long)currentBytes totalBytes:(long long)totalBytes;

/**
 * 文件接收进度回调
 *
 * @param currentBytes
 *            当前已接收的字节数
 * @param totalBytes
 *            接收数据总大小
 */
- (void)onRecvFileProgress:(long long)currentBytes totalBytes:(long long)totalBytes;

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

/**
 * 文件传输错误
 */
-(void)onFileTransferError:(int)error;

@end

@interface IWDSTransferAdapter : NSObject

+ (int)send:(IWDSConnection *)connection object:(id)object creator:(id <IWDSSafeParcelableCreator>)creator;

+ (int) send    :(IWDSConnection *)connection
        file    :(FILE *)file
        callBack:(id <IWDSTransferAdapterCallback>)callBack;

+ (int)sendFile:(IWDSConnection *)connection filePath:(NSString *)filePath chunkIndex:(int)chunkIndex callback:(id <IWDSTransferAdapterCallback>)callback;

+ (int) recv    :(IWDSConnection *)connection creator:(id <IWDSSafeParcelableCreator>)creator
        callBack:(id <IWDSTransferAdapterCallback>)callBack value:(id *)value;

@end