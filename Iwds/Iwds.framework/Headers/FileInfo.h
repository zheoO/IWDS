/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

@interface FileInfo : NSObject <IWDSSafeParcelable>

@property (nonatomic, retain) NSString  *name;
@property (nonatomic) long long         length;
@property (nonatomic) int               chunkIndex;
@property (nonatomic) int               chunkSize;

@end