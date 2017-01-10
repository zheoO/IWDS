/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import <Iwds/IWDSRemoteSearchProxyUtils.h>
#import <Iwds/IWDSDataTransactor.h>

#import <AMapFoundationKit/AMapFoundationKit.h>

typedef NS_ENUM (NSInteger, IWDSSearchServiceQueryType) {
    /**
     * 骑行路径规划
     */
    QUERY_TYPE_RIDE_ROUTE_SEARCH = 0,

    /**
     * 步行路径规划
     */
    QUERY_TYPE_WALK_ROUTE_SEARCH = 1
};

/**
 * 远程设备状态改变委托类
 */
@protocol IWDSRemoteStatusChangedDelegate <NSObject>

@required

/**
 * 远程设备是否可用
 */
- (void)onAvailable:(BOOL)isAvailable;

@end

/**
 * 远程搜索服务代理类
 */
@interface IWDSSearchServiceProxy : NSObject

/**
 * 获取单例对象
 */
+ (instancetype)shareInstance;

/**
 * 远程设备是否可用
 */
@property (nonatomic, assign, readonly, getter = isAvailable) BOOL channelAvailable;

/**
 * 远程设备状态改变委托对象
 */
@property (nonatomic, weak) id <IWDSRemoteStatusChangedDelegate> remoteStatusChangedDelegate;

/**
 * 搜索委托对象
 */
@property (nonatomic, weak) id <AMapSearchDelegate> aMapSearchDelegate;

/**
 * 启动代理
 */
- (void)start;

/**
 * 设置高德API key
 */
- (void)setApiKey:(NSString *)key;

/**
 * 公交路径规划，公交路径规划不支持添加途径点
 */
- (void)calculateBusRouteAsynByOrigin:(AMapGeoPoint *)origin destination:(AMapGeoPoint *)destination mode:(int)mode city:(NSString *)city destinationCity:(NSString *)destinationCity nightFlag:(BOOL)nightFlag requireExtension:(BOOL)requireExtension;

/**
 * 驾车路径规划，支持添加最多16个途径点，支持设置避让区域和避让道路
 */
- (void)calculateDriveRouteAsynByOrigin:(AMapGeoPoint *)origin destination:(AMapGeoPoint *)destination mode:(int)mode passedByPoints:(NSArray *)passedByPoints avoidpolygons:(NSArray<AMapGeoPolygon *> *)avoidpolygons avoidroad:(NSString *)avoidroad requireExtension:(BOOL)requireExtension;

/**
 * 骑行或步行路径规划，可添加多个途径点
 */
- (void)calculateRouteAsynByType:(int)queryType origin:(AMapGeoPoint *)origin destination:(AMapGeoPoint *)destination mode:(int)mode passedByPoints:(NSArray *)passedByPoints;

/**
 * 发送公交路径规划结果到远程设备
 */
- (BOOL)sendBusRouteResultToRemote:(AMapRouteSearchResponse *)result request:(AMapTransitRouteSearchRequest *)request;

/**
 * 发送驾车路径规划结果到远程设备
 */
- (BOOL)sendDriveRouteResultToRemote:(AMapRouteSearchResponse *)result request:(AMapDrivingRouteSearchRequest *)request;

/**
 * 发送骑行路径规划结果到远程设备
 */
- (BOOL)sendRideRouteResultToRemote:(AMapRouteSearchResponse *)result request:(AMapRidingRouteSearchRequest *)request;

/**
 * 发送步行路径规划结果到远程设备
 */
- (BOOL)sendWalkRouteResultToRemote:(AMapRouteSearchResponse *)result request:(AMapWalkingRouteSearchRequest *)request;

@end
