/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import <Iwds/IWDSRemoteSearchManagerInfo.h>
#import <AMapSearchKit/AMapSearchKit.h>

@interface IWDSRemoteSearchProxyUtils : NSObject

#pragma Build Request

+ (AMapTransitRouteSearchRequest *)buildAMapTransitRouteSearchRequestWithRemoteBusRouteQuery:(RemoteBusRouteQuery *)busRouteQuery;

+ (AMapDrivingRouteSearchRequest *)buildAMapDrivingRouteSearchRequestWithRemoteDriveRouteQuery:(RemoteDriveRouteQuery *)driveRouteQuery;

+ (AMapRidingRouteSearchRequest *)buildAMapRidingRouteSearchRequestWithRemoteRideRouteQuery:(RemoteRideRouteQuery *)rideRouteQuery;

+ (AMapWalkingRouteSearchRequest *)buildAMapWalkingRouteSearchRequestWithRemoteWalkRouteQuery:(RemoteWalkRouteQuery *)walkRouteQuery;

#pragma Build Result

+ (RemoteBusRouteResult *)buildRemoteBusRouteResultWithAMapRouteSearchResponse:(AMapRouteSearchResponse *)response request:(AMapTransitRouteSearchRequest *)request;

+ (RemoteDriveRouteResult *)buildRemoteDriveRouteResultWithAMapRouteSearchResponse:(AMapRouteSearchResponse *)response request:(AMapDrivingRouteSearchRequest *)request;

+ (RemoteRideRouteResult *)buildRemoteRideRouteResultWithAMapRouteSearchResponse:(AMapRouteSearchResponse *)response request:(AMapRidingRouteSearchRequest *)request;

+ (RemoteWalkRouteResult *)buildRemoteWalkRouteResultWithAMapRouteSearchResponse:(AMapRouteSearchResponse *)response request:(AMapWalkingRouteSearchRequest *)request;

+ (AMapRouteSearchResponse *)mergeRouteSearchResponse:(AMapRouteSearchResponse *)target other:(AMapRouteSearchResponse *)other;

@end
