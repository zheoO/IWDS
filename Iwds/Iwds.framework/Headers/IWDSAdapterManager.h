/*
 *  Copyright (C) 2016, Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class IWDSAdapter;
@class IWDSLinkManager;

@interface IWDSAdapterManager : NSObject

@property (nonatomic) NSArray *adapters;
@property (nonatomic) IWDSLinkManager *linkManager;

+ (instancetype)shareInstance;
- (IWDSAdapter *) getAdapter:(NSString *) linkTag;

@end
