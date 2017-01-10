/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  HuangLihong(Regen) <lihong.huang@ingenic.com, peterlihong@qq.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>

@class NativeSafeparcel;

@protocol IWDSSafeParcelable;
@protocol IWDSSafeParcelableCreator;

@interface IWDSSafeParcel : NSObject

+ (void)registerClassName:(NSString *)objcClassName androidClassName:(NSString *)androidClassName;

/**
 * 从对象池中获取一个SafeParcel对象
 *
 * @return SafeParcel对象
 */

+ (IWDSSafeParcel *)obtain;

/**
 * 将SafeParcel对象放会对象池. 在此之后你不能再访问这个对象.
 */
- (void)recycle;

- (int)dataSize;

/**
 * 设置SafeParcel中数据的大小.
 *
 * @param size
 *            数据的大小, 可以小于或者大于当前大小. 如果大于当前的容量dataCapacity(),将会分配更多的内存
 */
- (void)setDataSize:(int)size;

/**
 * 返回SafeParcel剩余的空间大小. {@link #dataSize}-{@link #dataPosition}.
 *
 * @return 剩余的空间大小
 */
- (int)dataAvail;

/**
 * 返回SafeParcel中当前数据的位置. 永远小于{@link #dataSize}.
 *
 * @return SafeParcel中当前数据的位置
 */
- (int)dataPosition;

/**
 * 移动SafeParcel中数据读/写的当前位置
 *
 * @param pos
 *            　数据读/写的当前位置, 范围必须在0-{@link #dataSize}.
 */
- (void)setDataPosition:(int)pos;

/**
 * 返回SafeParcel容量, 该值总>= {@link #dataSize}.
 *
 * @return 容量
 */
- (int)dataCapacity;

/**
 * 修改SafeParcel的容量
 *
 * @param size
 *            　容量, 不能小于{@link #dataSize}
 */
- (void)setDataCapacity:(int)size;

/**
 * 以字节数组形式返回SafeParcel中的数据
 *
 * @return 字节数组
 */
- (NSData *)marshall;

/**
 * 将字节数组内容放到SafeParcel中
 *
 * @param data
 *            字节数组
 * @param offest
 *            偏移
 * @param length
 *            长度
 */
- (void)unmarshall:(NSData *)data offset:(int)offset length:(int)length;

#pragma mark write
/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            整型数据
 */
- (void)writeInt:(int)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            长整型数据
 */
- (void)writeLongLong:(long long)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            浮点型数据
 */
- (void)writeFloat:(float)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            双精度浮点型数据
 */
- (void)writeDouble:(double)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            String对象
 */
- (void)writeString:(NSString *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel. key值必须为String类型, 推荐使用
 * {@link #writeBundle}, 因为RemoteBundle数据类型安全
 *
 * @param val
 *            Map数据
 */
- (void)writeMap:(NSDictionary *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            字节数据
 */
- (void)writeByte:(Byte)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param p
 *            SafeParcelable 对象
 * @param flags
 *            上下文标志
 */
 -(void)writeParcelable:(id<IWDSSafeParcelable>)p flags:(int)flags;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            CharSequenced对象
 */
- (void)writeCharSequence:(NSString *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            List对象
 */
- (void)writeList:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val byte char
 *            boolean[]数据
 */
- (void)writeBooleanArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            byte[]数据
 */
- (void)writeByteArray:(NSData *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            字节数组
 * @param offset
 *            偏移位置
 * @param len
 *            长度
 */
- (void)writeByteArray:(NSData *)val offset:(int)offset length:(int)len;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            String[]数据
 */
- (void)writeStringArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            CharSequence[]数据
 */
- (void)writeCharSequenceArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            char[]数据
 */
- (void)writeCharArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            SafeParcelable[]数据
 */
- (void)writeParcelableArray:(NSArray *)val flags:(int)flags;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            Object[]数据
 */
- (void)writeArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            int[]数据
 */
- (void)writeIntArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            long[]数据
 */
- (void)writeLongLongArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            float[]数据
 */
- (void)writeFloatArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            double[]数据
 */
- (void)writeDoubleArray:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            List<T>数据
 */
- (void)writeTypedList:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            List<String>数据
 */
- (void)writeStringList:(NSArray *)val;

/**
 * 在当前位置dataPosition(), 将val写入SafeParcel
 *
 * @param val
 *            T[]数据
 */
- (void)writeTypedArray:(NSArray *)val flags:(int)flags;

/**
 * 在当前位置dataPosition(), 将v写入SafeParcel
 *
 * @param v
 *            Object对象
 */
- (void)writeValue:(id)v;

#pragma mark read

/**
 * 从当前位置dataPosition()读取int
 *
 * @return int
 */
- (int)readInt;

/**
 * 从当前位置dataPosition()读取String
 *
 * @return String
 */
- (NSString *)readString;

/**
 * 从当前位置dataPosition()读取long long
 *
 * @return long long
 */
- (long long)readLongLong;

/**
 * 从当前位置dataPosition()读取float
 *
 * @return float
 */
- (float)readFloat;

/**
 * 从当前位置dataPosition()读取double
 *
 * @return double
 */
- (double)readDouble;

/**
 * 从当前位置dataPosition()读取byte
 *
 * @return byte
 */
- (Byte)readByte;

/**
 * 从当前位置dataPosition()读取List到outVal
 *
 * @param outVal
 *            List
 */
- (void)readList:(NSArray *)outVal;

/**
 * 从当前位置dataPosition()读取ArrayList
 *
 * @return NSArray
 */
- (NSArray *)readArrayList;

/**
 * 从当前位置dataPosition()读取CharSequence对象
 *
 * @return CharSequence对象
 */
- (NSString *)readCharSequence;

/**
 * 从当前位置dataPosition()读取Map到outVal
 *
 * @param outVal
 *            Map
 */
- (void)readMap:(NSMutableDictionary *)outVal;

/**
 * 从当前位置dataPosition()读取HashMap
 *
 * @return HashMap
 */
- (NSDictionary *)readHashMap;

/**
 * 从当前位置dataPosition()创建boolean[]
 *
 * @return boolean[]
 */
- (NSArray *)createBooleanArray;

/**
 * 从当前位置dataPosition()读取boolean[]到val
 *
 * @param val
 *            boolean[]
 */
- (void)readBooleanArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()创建byte[]
 *
 * @return byte[]
 */
- (NSData *)createByteArray;

/**
 * 从当前位置dataPosition()读取byte[]到val
 *
 * @param val
 *            byte[]
 */
- (void)readByteArray:(NSMutableData *)val;

/**
 * 从当前位置dataPosition()读取String[]
 *
 * @return String[]
 */
- (NSArray *)readStringArray;

/**
 * 从当前位置dataPosition()读取String[]到val
 *
 * @param val
 *            String[]
 */
- (void)readStringArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()读取CharSequence[]
 *
 * @return CharSequence[]
 */
- (NSArray *)readCharSequenceArray;

/**
 * 从当前位置dataPosition()读取Object[]
 *
 * @return Object[]
 */
- (NSArray *)readArray;

/**
 * 从当前位置dataPosition()创建int[]
 *
 * @return int[]
 */
- (NSArray *)createIntArray;

/**
 * 从当前位置dataPosition()读取int[]到val
 *
 * @param val
 *            int[]
 */
- (void)readIntArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()读取long array到val
 *
 * @param val
 *            long[]
 */
- (void)readLongLongArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()创建long long array
 *
 * @return long long array
 */
- (NSArray *)createLongLongArray;

/**
 * 从当前位置dataPosition()创建char array
 *
 * @return char array
 */
- (NSArray *)createCharArray;

/**
 * 从当前位置dataPosition()读取char[]到val
 *
 * @param val
 *            char[]
 */
- (void)readCharArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()创建float[]
 *
 * @return float[]
 */
- (NSArray *)createFloatArray;

/**
 * 从当前位置dataPosition()读取float[]到val
 *
 * @param val
 *            float[]
 */
- (void)readFloatArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()创建double[]
 *
 * @return double[]
 */
- (NSArray *)createDoubleArray;

/**
 * 从当前位置dataPosition()读取double[]到val
 *
 * @param val
 *            double[]
 */
- (void)readDoubleArray:(NSMutableArray *)val;

/**
 * 从当前位置dataPosition()读取SafeParcelable
 *
 * @return SafeParcelable
 */
- (id<IWDSSafeParcelable>)readParcelable;

+ (NSString *)objcClassNameFromJavaClassName:(NSString *)javaClassName;

+ (id<IWDSSafeParcelableCreator>)readParcelableCreatorFromName:(NSString *)objcClassName;

- (id<IWDSSafeParcelableCreator>)readParcelableCreator;

/**
 * 从当前位置dataPosition()读取SafeParcelable[]
 *
 * @return SafeParcelable[]
 */
- (NSArray *)readParcelableArray;

/**
 * 从当前位置dataPosition()创建ArrayList<T>
 *
 * @param c
 *            SafeParcelable.Creator
 * @return ArrayList<T>
 */
- (NSArray *)createTypedArrayList:(id<IWDSSafeParcelableCreator>)creator;

/**
 * 从当前位置dataPosition()读取ArrayList<T>到list
 *
 * @param c
 *            SafeParcelable.Creator
 */
- (void)readTypedList:(NSMutableArray *)list creator:(id<IWDSSafeParcelableCreator>)creator;

/**
 * 从当前位置dataPosition()创建ArrayList<String>
 *
 * @return ArrayList<String>
 */
- (NSArray *)createStringArrayList;

/**
 * 从当前位置dataPosition()读取List<String>到list
 *
 * @param list
 *            List<String>
 */
- (void)readStringList:(NSMutableArray *)list;

/**
 * 从当前位置dataPosition()创建T[]
 *
 * @param c
 *            SafeParcelable.Creator
 * @return T[]
 */
- (NSArray *)createTypedArray:(id<IWDSSafeParcelableCreator>)creator;

/**
 * 从当前位置dataPosition()读取T[]到val
 *
 * @param val
 *            T[]
 * @param c
 *            SafeParcelable.Creator
 */
- (void)readTypedArray:(NSMutableArray *)val creator:(id<IWDSSafeParcelableCreator>)creator;

/**
 * 从当前位置dataPosition()读取Object
 *
 * @return Object
 */
- (id)readValue;

@end