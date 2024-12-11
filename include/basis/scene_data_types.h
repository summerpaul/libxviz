/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 14:15:14
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-11-13 13:38:13
 */

#ifndef __SCENE_DATA_TYPES_H__
#define __SCENE_DATA_TYPES_H__

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "xviz_color.h"
namespace basis
{
#define ROOT_FRAME "root"
#define WORLD_FRAME "world"
#define BASE_LINK "base_link"
#define BASE_LINK2 "base_link2"

#define PATH_MIN_INTERVAL 1.0f

    struct StringValueMap : public std::map<std::string, std::string>
    {
        void Insert(const std::string &name, const std::string &value)
        {

            this->emplace(name, value);
        }

        std::string Get(const std::string &name) const
        {
            auto it = this->find(name);
            if (it != this->end())
            {
                return it->second;
            }
            return "";
        }

        //
        StringValueMap &operator=(const std::map<std::string, std::string> &other)
        {
            this->clear();
            for (const auto &item : other)
            {
                this->emplace(item.first, item.second);
            }
            return *this;
        }
    };

    struct DoubleValueMap : public std::map<std::string, double>
    {
        void Insert(const std::string &name, const double value)
        {
            this->emplace(name, value);
        }

        double Get(const std::string &name) const
        {
            auto it = this->find(name);
            if (it != this->end())
            {
                return it->second;
            }
            return 0.0;
        }

        DoubleValueMap &operator=(const std::map<std::string, double> &other)
        {
            this->clear();
            for (const auto &item : other)
            {
                this->emplace(item.first, item.second);
            }
            return *this;
        }
    };

    struct Header
    {
        std::string name = "";
        std::string frameId = WORLD_FRAME;
        std::string info = "";
    };

    struct SceneObjectOptions
    {
        float thickness = 0.05f;
        float radius = 0.05f;
        float length = 1.0f;
        bool showInfo = false;
        bool visible = true;
        bool valid = true;
        bool selected = false;
        bool useOwnOptions = false;
        Color color;
    };

    struct SceneObject
    {
        typedef std::shared_ptr<SceneObject> Ptr;

        virtual ~SceneObject() {}
        virtual void clear() {}
        //  获取结构体名
        virtual std::string GetObjectName()
        {
            return typeid(*this).name();
        }
        Header header;
        SceneObjectOptions options;
    };

    struct Point
    {
        Point(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z) {}
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;
    };

    struct Points : public std::vector<Point>
    {
        void append(const Point &p)
        {
            push_back(p);
        }
    };

    struct ScenePath : public SceneObject
    {

        Points points;
        bool isDashed = false;
        float thicknessScale = 1.0f;
        float dashLength = 0.4f;
        void append(const Point &p)
        {
            points.append(p);
        }
        void clear()
        {
            points.clear();
        }
    };

    struct ScenePathArray : public SceneObject
    {
        std::vector<ScenePath> paths;
        void append(const ScenePath &scenePath)
        {
            paths.push_back(scenePath);
        }
        void clear()
        {
            paths.clear();
        }
    };

    struct ScenePolygon : public SceneObject
    {
        Points vertices;
        bool filled = false;
        void clear()
        {
            vertices.clear();
        }

        void append(const Point &p)
        {
            vertices.append(p);
        }
    };

    struct ScenePolygonArray : public SceneObject
    {
        std::vector<ScenePolygon> polygons;
        void append(const ScenePolygon &scenePolygon)
        {
            polygons.push_back(scenePolygon);
        }
        void clear()
        {
            polygons.clear();
        }
    };
    struct SceneCircle : public SceneObject
    {
        SceneCircle()
        {
            this->options.valid = false;
        }
        Point center;
        float radius = 0.0f;
        bool filled = false;
    };

    struct SceneCircleArray : public SceneObject
    {
        std::vector<SceneCircle> circles;
        void append(const SceneCircle &sceneCircle)
        {
            circles.push_back(sceneCircle);
        }

        void clear()
        {
            circles.clear();
        }
    };
    struct ScenePose : public SceneObject
    {
        ScenePose()
        {
            options.valid = false;
        }
        Point position;
        float roll = 0;
        float pitch = 0;
        float yaw = 0;
    };
    struct ScenePoseArray : public SceneObject
    {
        std::vector<ScenePose> poses;
        void append(const ScenePose &scenePose)
        {
            poses.push_back(scenePose);
        }

        void clear()
        {
            poses.clear();
        }
    };

    struct ScenePointCloud : public SceneObject
    {
        Points points;
        void append(const Point &p)
        {
            points.append(p);
        }
        void clear()
        {
            points.clear();
        }
    };
    enum MARKER_TYPE
    {
        PATH = 0,
        POLYGON = 1,
        CIRCLE = 3,
        POSE = 4,
        POINT_CLOUD = 5,
        NONE_TYPE
    };

    struct SceneMarker : public SceneObject
    {
        int type = MARKER_TYPE::NONE_TYPE;
        ScenePath path;
        ScenePolygon polygon;
        SceneCircle circle;
        ScenePose pose;
        ScenePointCloud pointCloud;
    };
    struct SceneMarkerArray : public SceneObject
    {
        std::vector<SceneMarker> markers;
        void append(const SceneMarker &sceneMarker)
        {
            markers.push_back(sceneMarker);
        }
        void clear()
        {
            markers.clear();
        }
    };

    struct DoubleVector : public std::vector<double>
    {
        void append(const double &value)
        {
            push_back(value);
        }
    };

}
#endif /* __SCENE_DATA_TYPES_H__ */
