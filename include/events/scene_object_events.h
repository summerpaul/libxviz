/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 13:36:56
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-07-24 00:08:01
 */
#ifndef __SCENE_OBJECT_EVENTS_H__
#define __SCENE_OBJECT_EVENTS_H__

#include "basis/scene_data_types.h"
#include "event_bus/event.h"

using namespace basis;
using namespace event_bus;
namespace events
{
    class ScenePathEvent : public Event
    {
    public:
        // ScenePathEvent(const ScenePath &path, bool optionsValid = true)
        //     : path(path), optionsValid(optionsValid)
        // {
        // }
        ScenePath path;
        bool optionsValid = true;
    };

    class ScenePathArrayEvent : public Event
    {
    public:
        // ScenePathArrayEvent(const ScenePathArray &paths, bool optionsValid = true)
        //     : paths(paths), optionsValid(optionsValid)
        // {
        // }
        ScenePathArray paths;
        bool optionsValid = true;
    };

    class ScenePolygonEvent : public Event
    {
    public:
        ScenePolygon polygon;
        bool optionsValid = true;
    };

    class ScenePolygonArrayEvent : public Event
    {
    public:
        ScenePolygonArray polygons;
        bool optionsValid = true;
    };

    class SceneCircleEvent : public Event
    {
    public:
        SceneCircle circle;
        bool optionsValid = true;
    };

    class SceneCircleArrayEvent : public Event
    {
    public:
        SceneCircleArray circles;
        bool optionsValid = true;
    };

    class ScenePoseEvent : public Event
    {
    public:
        ScenePose pose;
        bool optionsValid = true;
    };
    class ScenePoseArrayEvent : public Event
    {
    public:
        ScenePoseArray poses;
        bool optionsValid = true;
    };
    class ScenePointCloudEvent : public Event
    {
    public:
        ScenePointCloud pointCloud;
        bool optionsValid = true;
    };

    class SceneMarkerEvent : public Event
    {
    public:
        SceneMarker marker;
        bool optionsValid = true;
    };

    class SceneMarkerArrayEvent : public Event
    {
    public:
        SceneMarkerArray markers;
        bool optionsValid = true;
    };

    class PlotRealtimeDoubleData : public Event
    {
    public:
        std::string name;
        std::vector<double> ys;
        std::vector<double> xs;
    };

    class PlotTimeSeriesDoubleDataMapEvent : public Event
    {
    public:
        DoubleValueMap datas;
        double time;
    };

    class PlotStringDataMapEvent : public Event
    {
    public:
        StringValueMap datas;
    };

    class TransformNodeEvent : public Event
    {
    public:
        float x{0}, y{0}, z{0};
        float roll{0}, pitch{0}, yaw{0};
        std::string frameId;
        std::string parentFrameId;
    };

    class ClearDataEvent : public Event
    {
    };

    class SetDrawFrameIDEvent : public Event
    {
    public:
        std::string frameId;
    };

    class CurPlotTimeEvent : public Event
    {
    public:
        double curTime;
    };

}
#endif /* __SCENE_OBJECT_EVENTS_H__ */
