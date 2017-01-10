/*
 *  Copyright (C) 2016 Ingenic Semiconductor
 *
 *  ZhangTao(Kevin) <tao.zhang@ingenic.com>
 *
 *  Elf/IDWS Project
 */

#import <Foundation/Foundation.h>
#import <Iwds/IWDSSafeParcelable.h>

@interface IWDSRemoteSearchManagerInfo : NSObject

@end

#pragma RemoteLatLonPoint 几何点对象类

/**
 * 几何点对象类。 该类为不可变类，表示一对经、纬度值，以双精度形式存储
 */
@interface RemoteLatLonPoint : NSObject <IWDSSafeParcelable>

/**
 * 该点的纬度，其取值范围是[-80,80]
 */
@property (nonatomic, assign) double latitude;

/**
 * 该点的经度，可被规范化到(-180,180]
 */
@property (nonatomic, assign) double longitude;

@end

#pragma RemoteDistrict 行政区信息

/**
 * 此类定义搜索返回行政区的名称和编码
 */
@interface RemoteDistrict : NSObject <IWDSSafeParcelable>

/**
 * 行政区的编码
 */
@property (nonatomic, copy) NSString *districtAdCode;

/**
 * 行政区的名称
 */
@property (nonatomic, copy) NSString *districtName;

@end

#pragma RemoteSearchCity 城市信息

/**
 * 此类定义搜索返回城市的名称和编码
 */
@interface RemoteSearchCity : NSObject <IWDSSafeParcelable>

/**
 * 城市的行政编码
 */
@property (nonatomic, copy) NSString *searchCityAdCode;

/**
 * 城市的编码
 */
@property (nonatomic, copy) NSString *searchCityCode;

/**
 * 城市的名称
 */
@property (nonatomic, copy) NSString *searchCityName;

/**
 * 构造一个城市信息
 */
- (instancetype)initWithCity:(RemoteSearchCity *)city;

@end

#pragma RemoteRouteSearchCity 路径规划返回的城市信息

/**
 * 此类定义路径规划返回的城市名称、编码和行政区的名称和编码
 */
@interface RemoteRouteSearchCity : RemoteSearchCity <IWDSSafeParcelable>

/**
 * 所有的行政区对象
 */
@property (nonatomic) NSMutableArray <RemoteDistrict *> *districtList;

@end

#pragma RemotePath 路径规划的一个方案

/**
 * 定义了路径规划的一个方案
 */
@interface RemotePath : NSObject <IWDSSafeParcelable>

/**
 * 路径规划方案的距离，单位米。 公交换乘路径规划时，此距离为方案的步行距离与公交距离之和
 */
@property (nonatomic, assign) float distance;

/**
 * 路径规划方案的预计消耗时间，单位秒。
 */
@property (nonatomic, assign) long long duration;

/**
 * 构造一个路径规划的方案
 */
- (instancetype)initWithPath:(RemotePath *)path;

@end

#pragma RemoteRouteResult 路径规划的结果集

/**
 * 定义了路径规划的结果集
 */
@interface RemoteRouteResult : NSObject <IWDSSafeParcelable>

/**
 * 路径规划起点的位置
 */
@property (nonatomic) RemoteLatLonPoint *startPos;

/**
 * 路径规划终点的位置
 */
@property (nonatomic) RemoteLatLonPoint *targetPos;

/**
 * 构造一个路径规划的结果集
 */
- (instancetype)initWithResult:(RemoteRouteResult *)result;

@end

#pragma RemoteFromAndTo 路径规划的起点和终点坐标

/**
 * 路径规划的起点和终点坐标
 */
@interface RemoteFromAndTo : NSObject <IWDSSafeParcelable>

/**
 * 路径规划目的地POI的ID
 */
@property (nonatomic, copy) NSString *destinationPoiId;

/**
 * 路径规划的起点坐标
 */
@property (nonatomic) RemoteLatLonPoint *fromPos;

/**
 * 路径规划的终点坐标
 */
@property (nonatomic) RemoteLatLonPoint *toPos;

/**
 * 路径规划起点POI的ID
 */
@property (nonatomic, copy) NSString *startPoiId;

@end

#pragma RemoteDoorway 换乘点的出入口信息

/**
 * 定义了公交换乘路径规划的一个换乘点的出入口信息。换乘点目前指换乘地铁
 */
@interface RemoteDoorway : NSObject <IWDSSafeParcelable>

/**
 * 公交换乘中换乘点的出（入）口名称
 */
@property (nonatomic, copy) NSString *name;

/**
 * 公交换乘中换乘点的出（入）口坐标
 */
@property (nonatomic) RemoteLatLonPoint *latLonPoint;

- (instancetype)initWithName:(NSString *)name latLonPoint:(RemoteLatLonPoint *)latLonPoint;

@end

#pragma RemoteBusStationItem 公交站点信息类

@class RemoteBusLineItem;

/**
 * 公交站点信息类
 */
@interface RemoteBusStationItem : NSObject <IWDSSafeParcelable>

/**
 * 车站区域编码
 */
@property (nonatomic, copy) NSString *adCode;

/**
 * 途径此公交站的公交路线。列表内的公交路线信息为基本信息
 */
@property (nonatomic) NSMutableArray <RemoteBusLineItem *> *busLineItems;

/**
 * 车站ID
 */
@property (nonatomic, copy) NSString *busStationId;

/**
 * 车站名称
 */
@property (nonatomic, copy) NSString *busStationName;

/**
 * 车站城市编码
 */
@property (nonatomic, copy) NSString *cityCode;

/**
 * 车站经纬度坐标
 */
@property (nonatomic) RemoteLatLonPoint *latLonPoint;

@end

#pragma RemoteTaxiItem 出租车信息

/**
 * 出租车信息
 */
@interface RemoteTaxiItem : NSObject <IWDSSafeParcelable>

/**
 * 起点坐标
 */
@property (nonatomic, copy) RemoteLatLonPoint *origin;

/**
 * 终点坐标
 */
@property (nonatomic, copy) RemoteLatLonPoint *destination;

/**
 * 距离，单位米
 */
@property (nonatomic, assign) float distance;

/**
 * 耗时，单位秒
 */
@property (nonatomic, assign) float duration;

/**
 * 起点名称
 */
@property (nonatomic, copy) NSString *sname;

/**
 * 终点名称
 */
@property (nonatomic, copy) NSString *tname;

@end

#pragma RemoteRailwayStationItem 火车站

/**
 * 火车站
 */
@interface RemoteRailwayStationItem : NSObject <IWDSSafeParcelable>

/**
 * 火车站ID
 */
@property (nonatomic, copy) NSString *uid;

/**
 * 名称
 */
@property (nonatomic, copy) NSString *name;

/**
 * 经纬度坐标
 */
@property (nonatomic, copy) RemoteLatLonPoint *location;

/**
 * 区域编码
 */
@property (nonatomic, copy) NSString *adcode;

/**
 * 发车、到站时间，途径站时则为进站时间
 */
@property (nonatomic, copy) NSString *time;

/**
 * 途径站点的停靠时间，单位为分钟
 */
@property (nonatomic, assign) float wait;

/**
 * 是否是始发站，为出发站时有效
 */
@property (nonatomic, assign) BOOL isStart;

/**
 * 是否是终点站，为到达站时有效
 */
@property (nonatomic, assign) BOOL isEnd;

@end

#pragma RemoteRailwaySpace 火车仓位及价格信息

/**
 * 火车仓位及价格信息
 */
@interface RemoteRailwaySpace : NSObject <IWDSSafeParcelable>

/**
 * 类型，硬卧、硬座等
 */
@property (nonatomic, copy) NSString *code;

/**
 * 票价，单位元
 */
@property (nonatomic, assign) float cost;

@end

#pragma RemoteRailway 火车信息

/**
 * 火车信息
 */
@interface RemoteRailway : NSObject <IWDSSafeParcelable>

/**
 * 火车线路ID
 */
@property (nonatomic, copy) NSString *uid;

/**
 * 名称
 */
@property (nonatomic, copy) NSString *name;

- (instancetype)initWithRailway:(RemoteRailway *)railway;

@end

#pragma RemoteRailway 火车乘坐信息

/**
 * 火车乘坐信息
 */
@interface RemoteRouteRailwayItem : RemoteRailway <IWDSSafeParcelable>

/**
 * 车次
 */
@property (nonatomic, copy) NSString *trip;

/**
 * 类型
 */
@property (nonatomic, copy) NSString *type;

/**
 * 该换乘段行车总距离，单位为米
 */
@property (nonatomic, assign) float distance;

/**
 * 该线路车段耗时，单位为秒
 */
@property (nonatomic, assign) float time;

/**
 * 出发站
 */
@property (nonatomic, strong) RemoteRailwayStationItem *departureStation;

/**
 * 到达站
 */
@property (nonatomic, strong) RemoteRailwayStationItem *arrivalStation;

/**
 * 仓位及价格信息
 */
@property (nonatomic, strong) NSMutableArray <RemoteRailwaySpace *> *spaces;

// 扩展信息

/**
 * 途径站点信息
 */
@property (nonatomic, strong) NSMutableArray <RemoteRailwayStationItem *> *viaStops;

/**
 * 备选路线信息, 目前只有id和name
 */
@property (nonatomic, strong) NSMutableArray <RemoteRailway *> *alters;

- (instancetype)initWithRailway:(RemoteRailway *)railway;

@end

#pragma RemoteBusLineItem 公交线路信息类

/**
 * 公交线路信息类
 */
@interface RemoteBusLineItem : NSObject <IWDSSafeParcelable>

/**
 * 公交线路的起步价
 */
@property (nonatomic) float basicPrice;

/**
 * 公交线路外包矩形的左下与右上顶点坐标
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *bounds;

/**
 * 公交线路所属的公交公司
 */
@property (nonatomic, copy) NSString *busCompany;

/**
 * 公交线路的唯一ID
 */
@property (nonatomic, copy) NSString *busLineId;

/**
 * 公交线路的名称，包含线路编号和文字名称、类型、首发站、终点站
 */
@property (nonatomic, copy) NSString *busLineName;

/**
 * 公交线路的类型，类型为中文名称。 公交线路的类型有普通公交、地铁、 轻轨、有轨电车、无轨电车、旅游专线、机场大巴、社区专车、磁悬浮列车、轮渡、索道交通、其他
 */
@property (nonatomic, copy) NSString *busLineType;

/**
 * 公交线路的站点列表。此列表返回的公交站数据有ID、站名、经纬度、序号
 */
@property (nonatomic) NSMutableArray <RemoteBusStationItem *> *busStations;

/**
 * 公交线路的城市编码
 */
@property (nonatomic, copy) NSString *cityCode;

/**
 * 公交线路的沿途坐标，包含首发站和终点站坐标
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *directionCoordinates;

/**
 * 公交线路全程里程，单位千米
 */
@property (nonatomic) float distance;

/**
 * 公交线路的首发时间
 */
@property (nonatomic) long long firstBusTime;

/**
 * 公交线路的末班车发车时间
 */
@property (nonatomic) long long lastBusTime;

/**
 * 公交线路的始发站名称
 */
@property (nonatomic, copy) NSString *originatingStation;

/**
 * 公交线路的终点站名称
 */
@property (nonatomic, copy) NSString *terminalStation;

/**
 * 公交线路的全程票价
 */
@property (nonatomic) float totalPrice;

/**
 * 构造一个公交线路信息
 */
- (instancetype)initWithItem:(RemoteBusLineItem *)item;

@end

#pragma RemoteRouteBusLineItem 换乘段的公交信息

/**
 * 定义了公交换乘路径规划的一个换乘段的公交信息
 */
@interface RemoteRouteBusLineItem : RemoteBusLineItem <IWDSSafeParcelable>

/**
 * 此公交换乘路段的到达站。此站有可能不是公交线路的终点站
 */
@property (nonatomic) RemoteBusStationItem *arrivalBusStation;

/**
 * 此公交换乘路段的出发站。此站有可能不是公交线路的始发车站
 */
@property (nonatomic) RemoteBusStationItem *departureBusStation;

/**
 * 此公交换乘路段公交预计行驶时间
 */
@property (nonatomic, assign) float duration;

/**
 * 此公交换乘路段经过的站点数目（除出发站、到达站）
 */
@property (nonatomic, assign) int passStationNum;

/**
 * 此公交换乘路段经过的站点名称集合
 */
@property (nonatomic) NSMutableArray <RemoteBusStationItem *> *passStations;

/**
 * 此公交换乘路段（出发站-到达站）的坐标点集合
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *polyLine;

@end

#pragma RemoteWalkStep 步行路径规划的一个路段

/**
 * 定义了步行路径规划的一个路段
 */
@interface RemoteWalkStep : NSObject <IWDSSafeParcelable>

/**
 * 步行路段的导航主要操作
 */
@property (nonatomic, copy) NSString *action;

/**
 * 步行路段的导航辅助操作
 */
@property (nonatomic, copy) NSString *assistantAction;

/**
 * 步行路段的距离，单位米
 */
@property (nonatomic, assign) float distance;

/**
 * 步行路段的预计时间
 */
@property (nonatomic, assign) float duration;

/**
 * 步行路段的行进指示
 */
@property (nonatomic, copy) NSString *instruction;

/**
 * 步行路段的行进方向
 */
@property (nonatomic, copy) NSString *orientation;

/**
 * 步行路段的坐标点集合
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *polyline;

/**
 * 步行路段的道路名称
 */
@property (nonatomic, copy) NSString *road;

@end

#pragma RemoteWalkPath 步行路径规划的一个方案

/**
 * 定义了步行路径规划的一个方案
 */
@interface RemoteWalkPath : RemotePath <IWDSSafeParcelable>

/**
 * 步行方案的路段列表
 */
@property (nonatomic) NSMutableArray <RemoteWalkStep *> *walkStepList;

/**
 * 构造一个路径规划方案
 */
- (instancetype)initWithPath:(RemotePath *)path;

@end

#pragma RemoteWalkRouteQuery 步行路径规划的查询参数对象

/**
 * 此类定义了步行路径的起终点和计算路径的模式
 */
@interface RemoteWalkRouteQuery : NSObject <IWDSSafeParcelable>

/**
 * 步行路径的起终点
 */
@property (nonatomic) RemoteFromAndTo *fromAndTo;

/**
 * 计算路径的模式
 */
@property (nonatomic, assign) int mode;

@end

#pragma RemoteWalkRouteResult 步行路径规划的结果集

/**
 * 定义了步行路径规划的结果集
 */
@interface RemoteWalkRouteResult : RemoteRouteResult <IWDSSafeParcelable>

/**
 * 该结果对应的查询参数
 */
@property (nonatomic) RemoteWalkRouteQuery *walkRouteQuery;

/**
 * 步行路径规划方案
 */
@property (nonatomic) NSMutableArray <RemoteWalkPath *> *walkPathList;

@end

#pragma RemoteRouteBusWalkItem 换乘段的步行信息

/**
 * 定义了公交换乘路径规划的一个换乘段的步行信息
 */
@interface RemoteRouteBusWalkItem : RemoteWalkPath <IWDSSafeParcelable>

/**
 * 此路段步行导航信息的终点坐标
 */
@property (nonatomic) RemoteLatLonPoint *destination;

/**
 * 此路段步行导航信息的起点坐标
 */
@property (nonatomic) RemoteLatLonPoint *origin;

- (instancetype)initWithPath:(RemoteWalkPath *)path;

@end

#pragma RemoteBusRouteQuery 公交路径规划查询参数对象

/**
 * 此类定义了公交路径规划查询路径的起终点、计算路径的模式、城市和是否计算夜班车
 */
@interface RemoteBusRouteQuery : NSObject <IWDSSafeParcelable>

/**
 * 路径的起终点
 */
@property (nonatomic) RemoteFromAndTo *fromAndTo;

/**
 * 计算路径的模式。可选，默认为最快捷
 */
@property (nonatomic) int mode;

/**
 * 是否计算夜班车，默认为不计算。0：不计算，1：计算。可选
 */
@property (nonatomic) int nightFlag;

/**
 * 城市名称/城市区号/电话区号。此项不能为空
 */
@property (nonatomic, copy) NSString *city;

/**
 * 跨城公交规划的目的地城市，目的城市跨城时需要填写，否则会出错
 */
@property (nonatomic, copy) NSString *destinationCity;

/**
 * 是否返回扩展信息，默认为 NO
 */
@property (nonatomic, assign) BOOL requireExtension;

@end

#pragma RemoteBusStep 公交路径规划的一个路段

/**
 * 定义了公交路径规划的一个路段。 路段最多包含一段步行信息和公交导航信息。可能出现路段中没有步行信息的情况
 */
@interface RemoteBusStep : NSObject <IWDSSafeParcelable>

/**
 * 此路段的公交导航信息列表
 */
@property (nonatomic) NSMutableArray <RemoteRouteBusLineItem *> *busLineList;

/**
 * 此路段的入口信息。 入口信息指换乘地铁时的进站口
 */
@property (nonatomic) RemoteDoorway *entrance;

/**
 * 此路段的出口信息。 出口信息指乘地铁之后的出站口信息
 */
@property (nonatomic) RemoteDoorway *exit;

/**
 * 此路段的步行信息
 */
@property (nonatomic) RemoteRouteBusWalkItem *walk;

/**
 * 出租车信息，跨城时有效
 */
@property (nonatomic, strong) RemoteTaxiItem *taxi;

/**
 * 火车信息，跨城时有效
 */
@property (nonatomic, strong) RemoteRouteRailwayItem *railway;

@end

#pragma RemoteBusPath 公交换乘路径规划的一个方案

/**
 * 定义了公交换乘路径规划的一个方案
 */
@interface RemoteBusPath : RemotePath <IWDSSafeParcelable>

/**
 * 此方案的公交行驶的总距离，单位米
 */
@property (nonatomic) float busDistance;

/**
 * 公交换乘方案的花费，单位元
 */
@property (nonatomic) float cost;

/**
 * 公交路径规划方案的路段列表
 */
@property (nonatomic) NSMutableArray <RemoteBusStep *> *stepList;

/**
 * 此方案整条路线的距离，包括公交行驶距离与步行距离，单位米
 */
@property (nonatomic) float walkDistance;

/**
 * 是否包含夜班车
 */
@property (nonatomic) BOOL isNightBus;

@end

#pragma RemoteBusRouteResult 公交路径规划的结果集

/**
 * 定义了公交路径规划的结果集
 */
@interface RemoteBusRouteResult : RemoteRouteResult <IWDSSafeParcelable>

/**
 * 该结果对应的查询参数
 */
@property (nonatomic) RemoteBusRouteQuery *busRouteQuery;

/**
 * 公交路径规划方案
 */
@property (nonatomic) NSMutableArray <RemoteBusPath *> *busPathList;

/**
 * 从起点到终点打车的费用，单位元。 费用是以驾车路线最短距离估计出租车的费用
 */
@property (nonatomic) float taxiCost;

@end

#pragma RemoteTMC 路径规划的交通拥堵信息类

@interface RemoteTMC : NSObject <IWDSSafeParcelable>

/**
 * 长度（单位：米）
 */
@property (nonatomic, assign) int distance;

/**
 * 路况状态描述：0 未知，1 畅通，2 缓行，3 拥堵
 */
@property (nonatomic, copy) NSString *status;

/*
 * 此路段坐标点串
 */
@property (nonatomic, copy) NSMutableArray <RemoteLatLonPoint *> *polyline;

@end

#pragma RemoteDriveStep 驾车路径规划的一个路段

/**
 * 定义了驾车路径规划的一个路段
 */
@interface RemoteDriveStep : NSObject <IWDSSafeParcelable>

/**
 * 驾车路段的导航主要操作
 */
@property (nonatomic, copy) NSString *action;

/**
 * 驾车路段的导航辅助操作
 */
@property (nonatomic, copy) NSString *assistantAction;

/**
 * 驾车路段的距离，单位米
 */
@property (nonatomic, assign) float distance;

/**
 * 驾车路段的预计时间，单位秒。时间根据当时路况估算
 */
@property (nonatomic, assign) float duration;

/**
 * 驾车路段的行驶指示
 */
@property (nonatomic, copy) NSString *instruction;

/**
 * 驾车路段的行驶方向。方向为中文名称，如东、西南等
 */
@property (nonatomic, copy) NSString *orientation;

/**
 * 驾车路段的坐标点集合
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *polyline;

/**
 * 驾车路段的道路名称
 */
@property (nonatomic, copy) NSString *road;

/**
 * 搜索返回的路径规划途径城市和行政区
 */
@property (nonatomic) NSMutableArray <RemoteRouteSearchCity *> *routeSearchCityList;

/**
 * 驾车收费路段的距离，单位米
 */
@property (nonatomic, assign) float tollDistance;

/**
 * 驾车路段的主要收费道路
 */
@property (nonatomic, copy) NSString *tollRoad;

/**
 * 驾车路段的收费价格，单位元
 */
@property (nonatomic, assign) float tolls;

/**
 * 驾车路段的交通拥堵信息集合
 */
@property (nonatomic) NSMutableArray <RemoteTMC *> *tmcs;

@end

#pragma RemoteDrivePath 驾车路径规划的一个方案

/**
 * 定义了驾车路径规划的一个方案
 */
@interface RemoteDrivePath : RemotePath <IWDSSafeParcelable>

/**
 * 驾车规划方案的路段列表
 */
@property (nonatomic) NSMutableArray <RemoteDriveStep *> *stepList;

/**
 * 导航策略，显示为中文，如返回“速度最快”
 */
@property (nonatomic, copy) NSString *strategy;

/**
 * 此方案中的收费道路的总长度
 */
@property (nonatomic, assign) float tollDistance;

/**
 * 此方案中的收费道路的总费用
 */
@property (nonatomic, assign) float tolls;

/**
 * 此方案交通信号灯个数
 */
@property (nonatomic, assign) int totalTrafficLights;

@end

#pragma RemoteDriveRouteQuery 驾车路径查询规划

/**
 * 此类定义了驾车路径查询规划
 */
@interface RemoteDriveRouteQuery : NSObject <IWDSSafeParcelable>

/**
 * 路径的起点终点
 */
@property (nonatomic) RemoteFromAndTo *fromAndTo;

/**
 * 计算路径的模式。可选，默认为速度优先
 */
@property (nonatomic, assign) int mode;

/**
 * 避让道路名称，可选。目前只支持一条避让道路
 */
@property (nonatomic, copy) NSString *avoidRoad;

/**
 * 避让区域，可选。区域避让，支持32个避让区域，每个区域最多可有16个顶点。如果是四边形则有4个坐标点，如果是五边形则有5个坐标点
 */
@property (nonatomic) NSMutableArray <NSMutableArray <RemoteLatLonPoint *> *> *avoidPolygons;

/**
 * 途经点，可选。最多支持16个途经点
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *passedByPoints;

@end

#pragma RemoteDriveRouteResult 驾车路径规划的结果集

/**
 * 定义了驾车路径规划的结果集
 */
@interface RemoteDriveRouteResult : RemoteRouteResult <IWDSSafeParcelable>

/**
 * 该结果对应的查询参数
 */
@property (nonatomic) RemoteDriveRouteQuery *driveRouteQuery;

/**
 * 驾车路径规划方案
 */
@property (nonatomic) NSMutableArray <RemoteDrivePath *> *drivePathList;

/**
 * 搭乘的士的花费
 */
@property (nonatomic, assign) float taxiCost;

@end

#pragma RemoteRideStep 骑行路径规划的一个路段

/**
 * 定义了骑行路径规划的一个路段
 */
@interface RemoteRideStep : NSObject <IWDSSafeParcelable>

/**
 * 骑行路段的行进指示
 */
@property (nonatomic, copy) NSString *instruction;

/**
 * 骑行路段的行进方向，方向为中文名称，如东、西南等
 */
@property (nonatomic, copy) NSString *orientation;

/**
 * 骑行路段的道路名称
 */
@property (nonatomic, copy) NSString *road;

/**
 * 骑行路段的距离，单位米
 */
@property (nonatomic, assign) float distance;

/**
 * 骑行路段的预计时间，单位为秒。时间根据当时路况估算
 */
@property (nonatomic, assign) float duration;

/**
 * 骑行路段的坐标点集合
 */
@property (nonatomic) NSMutableArray <RemoteLatLonPoint *> *polyline;

/**
 * 骑行路段的导航主要操作，如向左、向右等
 */
@property (nonatomic, copy) NSString *action;

@end

#pragma RemoteRidePath 骑行路径规划的一个方案

/**
 * 定义了骑行路径规划的一个方案
 */
@interface RemoteRidePath : RemotePath <IWDSSafeParcelable>

/**
 * 骑行方案的路段列表
 */
@property (nonatomic) NSMutableArray <RemoteRideStep *> *rideStepList;

@end

#pragma RemoteRideRouteQuery 骑行路径规划的查询参数对象

/**
 * 此类定义了骑行路径的起终点和计算路径的模式
 */
@interface RemoteRideRouteQuery : NSObject <IWDSSafeParcelable>

/**
 * 骑行路径的起终点
 */
@property (nonatomic) RemoteFromAndTo *fromAndTo;

/**
 * 计算路径的模式
 */
@property (nonatomic, assign) int mode;

@end

#pragma RemoteRideRouteResult 骑行路径规划的结果集

/**
 * 定义了骑行路径规划的结果集
 */
@interface RemoteRideRouteResult : RemoteRouteResult <IWDSSafeParcelable>

/**
 * 该结果对应的查询参数
 */
@property (nonatomic) RemoteRideRouteQuery *rideRouteQuery;

/**
 * 骑行路径规划方案
 */
@property (nonatomic) NSMutableArray <RemoteRidePath *> *ridePathList;

@end

@interface RemoteGeocodeQuery : NSObject <IWDSSafeParcelable>@end
@interface RemoteRegeocodeQuery : NSObject <IWDSSafeParcelable>@end
@interface RemoteDistrictQuery : NSObject <IWDSSafeParcelable>@end
@interface RemotePoiQuery : NSObject <IWDSSafeParcelable>@end
@interface RemoteInputQuery : NSObject <IWDSSafeParcelable>@end
@interface RemoteBusLineQuery : NSObject <IWDSSafeParcelable>@end
@interface RemoteBusStationQuery : NSObject <IWDSSafeParcelable>@end

@interface RemoteGeocodeResult : NSObject <IWDSSafeParcelable>@end
@interface RemoteRegeocodeResult : NSObject <IWDSSafeParcelable>@end
@interface RemoteDistrictResult : NSObject <IWDSSafeParcelable>@end
@interface RemotePoiResult : NSObject <IWDSSafeParcelable>@end
@interface RemotePoiItem : NSObject <IWDSSafeParcelable>@end
@interface RemoteTip : NSObject <IWDSSafeParcelable>@end
@interface RemoteBusLineResult : NSObject <IWDSSafeParcelable>@end
@interface RemoteBusStationResult : NSObject <IWDSSafeParcelable>@end
