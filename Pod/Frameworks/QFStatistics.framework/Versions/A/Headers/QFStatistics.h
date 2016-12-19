//
//  QFStatistics.h
//  NearMerchant
//
//  Created by QFPayShadowMan on 16/5/25.
//  Copyright © 2016年 qmm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface QFStatistics : NSObject

+ (void)start;
+ (void)startWithUserId:(NSString *)userId;

/** 自定义事件,数量统计.
 @param  eventId 网站上注册的事件Id.
 @param  label 分类标签。不同的标签会分别进行统计，方便同一事件的不同标签的对比,为nil或空字符串时后台会生成和eventId同名的标签.
 @param  attributes 其他附加参数以json类型传入
 @return void.
 */
+ (void)event:(NSString *)eventId; //等同于 event:eventId label:eventId;

/** 自定义事件,数量统计.
 */
+ (void)event:(NSString *)eventId attributes:(NSDictionary *)attributes;


/** 自定义事件,时长统计.
 beginEvent,endEvent要配对使用,也可以自己计时后通过durations参数传递进来
 
 @param  eventId 网站上注册的事件Id.
 @param  millisecond 自己计时需要的话需要传毫秒进来
 @param  attributes 其他参数以字典形式传入
 @param  serverSendTime 服务器发送推送的时间
 @return void.
 
 @warning 每个event的attributes不能超过10个
 eventId、attributes中key和value都不能使用空格和特殊字符，且长度不能超过255个字符（否则将截取前255个字符）
 id， ts， du是保留字段，不能作为eventId及key的名称
 */
+ (void)beginEvent:(NSString *)eventId;

/** 自定义事件,时长统计.
 */
+ (void)endEvent:(NSString *)eventId;

/** 自定义事件,时长统计.
 */
+ (void)beginEvent:(NSString *)eventId attributes:(NSDictionary *)attributes;

/** 自定义事件,时长统计.
 */
+ (void)endEvent:(NSString *)eventId attributes:(NSDictionary *)attributes;

/** 自定义事件,时长统计.
 */
+ (void)event:(NSString *)eventId durations:(int)millisecond;

/** 自定义事件,推送时长统计.
 */
+ (void)event:(NSString *)eventId serverSendTime:(double)serverSendTime;

/** 自定义事件,推送时长统计,增加param
 */
+ (void)event:(NSString *)eventId serverSendTime:(double)serverSendTime attributes:(NSDictionary *)attributes;


// ***************************************************************************************
// 注意：以下设置的参数必须在设置eventId方法之前调用，否则将记录到下次的eventId中。
// ***************************************************************************************

/** 为了更精确的统计用户地理位置，可以调用此方法传入经纬度信息
 需要链接 CoreLocation.framework 并且 #import <CoreLocation/CoreLocation.h>
 @param latitude 纬度.
 @param longitude 经度.
 @param location CLLocation *型的地理信息
 @return void
 */

+ (void)setLongitude:(double)longitude latitude:(double)latitude;

/** 为了更精确的统计用户地理位置，可以调用此方法传入经纬度信息
 */
+ (void)setLocation:(CLLocation *)location;

/** 设置UserId
 */
+ (void)setUserid:(NSString *)strUserId;

/** 设置交易的流水号
 */
+ (void)setSyssn:(NSString *)strSyssn;

/** 设置服务器的时间：SDK可以计算出系统与服务器的时间差
 */
+ (void)setSystemTime:(double)systemTimeInterval;

/** 设置系统与服务器的时间差
 */
+ (void)setTimeDiff:(NSString *)strTimeDiff;

@end
