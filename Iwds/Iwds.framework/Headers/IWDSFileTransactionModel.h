/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

#import <Iwds/IWDSSafeParcelable.h>
#import <Iwds/IWDSDataTransactor.h>
#import <Iwds/FileInfo.h>

@class  DeviceDescriptor;

extern const NSString   *IWDSFileTransactionConfirmReceiveFile;
extern const NSString   *IWDSFileTransactionCancelReceiveFile;

@protocol IWDSFileTransactionDelegate <NSObject>

@optional

- (void)onRequestSendFile:(FileInfo *)info;

- (void)onLinkConnected:(DeviceDescriptor *)descriptor isConnected:(BOOL)isConnected;

- (void)onChannelAvailable:(BOOL)isAvailable;

- (void)onSendResult:(IWDSDataTransactResult *)result;

- (void)onFileArrived:(NSString *)filePath;

- (void)onSendFileProgress:(int)progress;

- (void)onRecvFileProgress:(int)progress;

- (void)onConfirmReceiveFile;

- (void)onCancelReceiveFile;

- (void)onFileTransferError:(int)errorCode;

- (void)onSendFileInterrupted:(int)index;

- (void)onRecvFileInterrupted:(int)index;

@end

@interface RequestSendFile : NSObject <IWDSSafeParcelable>
@property (nonatomic, retain) FileInfo *info;
@end

@interface IWDSFileTransactionModel : NSObject <IWDSDataTransactorCallback>

- (instancetype)initWithUuid:(NSString *)uuid delegate:(id <IWDSFileTransactionDelegate>)delegate;

- (void)requestSendFile:(NSString *)filePath;

- (void)requestSendFile:(NSString *)filePath chunkIndex:(int)chunkIndex;

- (void)requestSendFileCompressed:(NSString *)filePath;

- (void)requestSendFileCompressed:(NSString *)filePath chunkIndex:(int)chunkIndex;

- (void)confirmReceiveFile;

- (void)cancelReceiveFile;

- (void)start;

- (void)stop;

- (BOOL)isStarted;

@end
