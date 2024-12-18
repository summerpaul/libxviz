/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 13:36:56
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-18 14:23:27
 */
#ifndef __SCENE_OBJECT_EVENTS_H__
#define __SCENE_OBJECT_EVENTS_H__

#include "basis/scene_data_types.h"
#include "event_bus/event.h"

using namespace basis;
using namespace event_bus;
namespace events
{
    // 路径事件
    class ScenePathEvent : public Event
    {
    public:
        ScenePath path;           // 路径
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 路径数组事件
    class ScenePathArrayEvent : public Event
    {
    public:
        ScenePathArray paths;     // 路径数组
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 多边形事件
    class ScenePolygonEvent : public Event
    {
    public:
        ScenePolygon polygon;     //多边形
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 多边形数组事件
    class ScenePolygonArrayEvent : public Event
    {
    public:
        ScenePolygonArray polygons; //多边形数组
        bool optionsValid = true;   // 数据配置选项是否生效
    };

    // 圆形事件
    class SceneCircleEvent : public Event
    {
    public:
        SceneCircle circle;       // 原形状
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 圆形数组事件
    class SceneCircleArrayEvent : public Event
    {
    public:
        SceneCircleArray circles; // 圆形数组
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 位姿事件
    class ScenePoseEvent : public Event
    {
    public:
        ScenePose pose;           // 位姿
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 位姿数组事件
    class ScenePoseArrayEvent : public Event
    {
    public:
        ScenePoseArray poses;     // 位姿数组
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 点云事件
    class ScenePointCloudEvent : public Event
    {
    public:
        ScenePointCloud pointCloud; //点云
        bool optionsValid = true;   // 数据配置选项是否生效
    };

    // marker事件
    class SceneMarkerEvent : public Event
    {
    public:
        SceneMarker marker;       // 通用marker
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // marker数组事件
    class SceneMarkerArrayEvent : public Event
    {
    public:
        SceneMarkerArray markers; // marker数组
        bool optionsValid = true; // 数据配置选项是否生效
    };

    // 实时数据事件
    class PlotRealtimeDoubleData : public Event
    {
    public:
        std::string name;       //数据名
        std::vector<double> ys; // y序列
        std::vector<double> xs; // x序列
    };

    // 时间序列数据事件
    class PlotTimeSeriesDoubleDataMapEvent : public Event
    {
    public:
        DoubleValueMap datas; // Double关联数组
        double time;          //当前时间
    };

    // 实时string关联数组事件
    class PlotStringDataMapEvent : public Event
    {
    public:
        StringValueMap datas; // string关联数组
    };

    // 坐标系节点事件
    class TransformNodeEvent : public Event
    {
    public:
        float x{0}, y{0}, z{0};          //相对父坐标系的平移量
        float roll{0}, pitch{0}, yaw{0}; //相对父坐标系的旋转量
        std::string frameId;             // 当前坐标系名
        std::string parentFrameId;       //父坐标系名
    };

    // 清空绘制数据事件
    class ClearDataEvent : public Event
    {
    };

    // 设置绘制坐标系事件
    class SetDrawFrameIDEvent : public Event
    {
    public:
        std::string frameId; // 当前坐标系名
    };

    // 当前时间戳事件
    class CurPlotTimeEvent : public Event
    {
    public:
        double curTime; //当前时间戳
    };

}
#endif /* __SCENE_OBJECT_EVENTS_H__ */
