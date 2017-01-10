/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  LiJingwen(Kevin) <kevin.jwli@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import "IWDSSafeParcelable.h"

/**
 * 该类对应手机端中的一条日程的提醒设置，日程可能没有设置提醒， 但是一条提醒 设置只能对应一条日程.
 * 可以在手机端的日历的数据库中的Reminders表中获取下面的字段.
 */
@interface ScheduleReminder : NSObject <IWDSSafeParcelable>

/** 该条提醒在手机端的数据库中的ID. */
@property (nonatomic) long long reminderId;

/** 该条提醒对应的日程的在手机端的数据库中的ID（日程的ID）. */
@property (nonatomic) long long eventId;

/** 提醒持续的时间（分钟）. */
@property (nonatomic) long long minutes;

/** 提醒的方式. */
@property (nonatomic) long long method;

@end

/**
 * 事件类.
 */
@interface ScheduleEvent : NSObject <IWDSSafeParcelable>

/** 该条日程在手机的数据库中的ID. */
@property (nonatomic) long long eventId;

/** 标题：日程名称. */
@property (nonatomic) NSString *title;

/** 地点：日程的地点. */
@property (nonatomic) NSString *eventLocation;

/** 描述：日程的内容. */
@property (nonatomic) NSString *eventDescription;

/** 开始时间：日期+时间. */
@property (nonatomic) long long dtStart;

/** 结束时间：日期+时间. */
@property (nonatomic) long long dtEnd;

/** 时区. */
@property (nonatomic) NSString *eventTimezone;

/** 持续时间. */
@property (nonatomic) NSString *duration;

/** 是否是一整天. */
@property (nonatomic) int allDay;

/** 是否有闹钟. */
@property (nonatomic) int hasAlarm;

/** 重复. */
@property (nonatomic) NSString *rrule;

/** 提醒. */
@property (nonatomic) ScheduleReminder *reminder;

@end

/**
 * 日程信息类.
 */
@interface ScheduleInfo : NSObject <IWDSSafeParcelable>

/** 事件数量. */
@property (nonatomic) int eventCount;

/** 事件. */
@property (nonatomic) NSMutableArray *events;

/**
 * 实例化日程信息对象.
 *
 * @param count
 *            事件数量 count等于0，表示没有日程
 */
- (instancetype)initWithEventCount:(int)eventCount;

@end
