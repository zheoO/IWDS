/*
 *  Copyright (C) 2014 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 *
 */

#import <Foundation/Foundation.h>

/**
 * 指示通道使用速度和压缩率平衡的压缩策略
 */
extern const int IWDSConnectionCompressLevelBalance;

/**
 * 指示通道使用快速压缩策略
 */
extern const int IWDSConnectionCompressLevelFaster;

/**
 * 指示通道使用以最高压缩比为目标的压缩策略
 */
extern const int IWDSConnectionCompressLevelHighCompression;

/**
 * 指示通道使用ZLIB压缩算法
 */
extern const int IWDSConnectionCompressAlgorithmGzip;

/**
 * 指示通道使用LZO压缩算法
 */
extern const int IWDSConnectionCompressAlgorithmLzo;

@class IWDSConnection;

@interface IWDSConnectionInputStream : NSObject
{
    IWDSConnection *_connection;
}
- (instancetype)initWithConnection:(IWDSConnection *)connection;
- (int)available;
- (void)close;
- (int)read;
- (int)read:(char *)buffer offset:(int)offset maxSize:(int)maxSize;
- (int)readInt;
- (int)readData:(NSMutableData *)data;
@end

@interface IWDSConnectionOutputStream : NSObject
{
    IWDSConnection *_connection;
}
- (instancetype)initWithConnection:(IWDSConnection *)connection;
- (void)flush;
- (void)close;
- (int)write:(int)oneByte;
- (int)write:(char *)buffer offset:(int)offset maxSize:(int)maxSize;
- (int)writeInt:(int)oneInt;
- (int)writeData:(NSData *)data;
@end

@class DeviceDescriptor;

@interface IWDSConnection : NSObject

@property (nonatomic, readonly) NSString                *address;
@property (nonatomic, readonly) NSString                *uuid;
@property (nonatomic, readonly) long long               port;
@property (nonatomic, readonly) int                     dataChunkSize;
@property (nonatomic, readonly) IWDSConnectionInputStream   *inputStream;
@property (nonatomic, readonly) IWDSConnectionOutputStream  *outputStream;

- (instancetype)init;
- (int)open:(NSString *)uuid address:(NSString *)address;
- (int)open:(DeviceDescriptor *)descriptor uuid:(NSString *)uuid;
- (void)close;
- (int)read:(char *)buffer offset:(int)offset maxSize:(int)maxSize;
- (int)write:(char *)buffer offset:(int)offset maxSize:(int)maxSize;
- (int)available;
- (int)handshake;

/**
 * 打开或关闭当前已经打开的连接的在线数据压缩功能
 *
 * @return 如果成功, 返回0, 否则返回错误号，参考IWDSError.
 */
- (int)setCompressEnabled:(BOOL)enabled;

/**
 * 返回当前已经打开的连接的在线数据压缩功能是否已经打开
 *
 * @return 如果压缩功能已经打开则返回1, 已经关闭返回0, 否则返回错误号. 参考IWDSError.
 */
- (int)getCompressEnabled;

/**
 * 返回当前已经打开的连接的在线数据压缩等级
 *
 * @return 如果调用成功则返回压缩等级, 否则返回错误号. 参考IWDSError.
 */
- (int)getCompressLevel;

/**
 * 设置已经打开的连接的在线数据压缩等级, 输入参数:
 * IWDSConnectionCompressLevelBalance,
 * IWDSConnectionCompressLevelFaster,
 * IWDSConnectionCompressLevelHighCompression
 *
 * @return 如果调用成功则返回0, 否则返回错误号. 参考IWDSError.
 */
- (int)setCompressLevel:(int)level;

/**
 * 返回当前已经打开的连接使用的在线数据压缩算法
 *
 * @return 如果调用成功则返回压缩等级. 否则返回错误号. 参考IWDSError.
 */
- (int)getCompressAlgorithm;

/**
 * 设置已经打开的连接{@code connection}的在线数据压缩算法, 输入参数请参考:
 * IWDSConnectionCompressAlgorithmGzip,
 * IWDSConnectionCompressAlgorithmLzo
 *
 * @return 如果调用成功则返回0, 否则返回错误号. 参考IWDSError.
 */
- (int)setCompressAlgorithm:(int)algorithm;

- (IWDSConnectionInputStream *)inputStream;
- (IWDSConnectionOutputStream *)outputStream;

@end