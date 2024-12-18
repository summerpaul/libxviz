/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 14:15:14
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-18 11:20:14
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

    // 数据头
    struct Header
    {
        std::string name = "";             //数据的名称
        std::string frameId = WORLD_FRAME; //数据的坐标系
        std::string info = "";             // 数据的文本信息
    };

    // 数据配置选项
    struct SceneObjectOptions
    {
        float thickness = 0.05f;    // 线段粗细
        float radius = 0.05f;       // 半径
        float length = 1.0f;        // 长度
        bool showInfo = false;      // 显示文本信息
        bool visible = true;        // 是否可视化
        bool valid = true;          // 是否有效
        bool selected = false;      // 是否被选中
        bool useOwnOptions = false; // 是否使用单独配置
        Color color;                // 颜色
    };

    //数据基类
    struct SceneObject
    {
        typedef std::shared_ptr<SceneObject> Ptr; // 共享指针

        virtual ~SceneObject() {}
        virtual void clear() {}
        //  获取结构体名
        virtual std::string GetObjectName()
        {
            return typeid(*this).name();
        }
        Header header;              // 数据头
        SceneObjectOptions options; // 数据配置选项
    };

    // 点
    struct Point
    {
        Point(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z) {}
        float x = 0.0; // x坐标
        float y = 0.0; // y坐标
        float z = 0.0; // z坐标
    };

    // 点集
    struct Points : public std::vector<Point>
    {

        void append(const Point &p)
        {
            push_back(p);
        }
    };

    // 路径数据
    struct ScenePath : public SceneObject
    {

        Points points;               // 路径点集
        bool isDashed = false;       // 是否时虚线
        float thicknessScale = 1.0f; // 缩放比例（未生效）
        float dashLength = 0.4f;     //虚线长度
        void append(const Point &p)
        {
            points.append(p);
        }
        void clear()
        {
            points.clear();
        }
    };

    // 路径数组数据
    struct ScenePathArray : public SceneObject
    {
        std::vector<ScenePath> paths; // 路径数据
        void append(const ScenePath &scenePath)
        {
            paths.push_back(scenePath);
        }
        void clear()
        {
            paths.clear();
        }
    };

    // 多边形数据
    struct ScenePolygon : public SceneObject
    {
        Points vertices;     //多边形顶点
        bool filled = false; //是否填充
        void clear()
        {
            vertices.clear();
        }

        void append(const Point &p)
        {
            vertices.append(p);
        }
    };

    // 多边形数组数据
    struct ScenePolygonArray : public SceneObject
    {
        std::vector<ScenePolygon> polygons; // 多边形数组
        void append(const ScenePolygon &scenePolygon)
        {
            polygons.push_back(scenePolygon);
        }
        void clear()
        {
            polygons.clear();
        }
    };

    // 圆数据
    struct SceneCircle : public SceneObject
    {
        SceneCircle()
        {
            this->options.valid = false;
        }
        Point center;        // 圆心
        float radius = 0.0f; // 圆半径
        bool filled = false; // 是否填充
    };

    // 圆数组数据
    struct SceneCircleArray : public SceneObject
    {
        std::vector<SceneCircle> circles; // 圆数组
        void append(const SceneCircle &sceneCircle)
        {
            circles.push_back(sceneCircle);
        }

        void clear()
        {
            circles.clear();
        }
    };

    // 位姿数据
    struct ScenePose : public SceneObject
    {
        ScenePose()
        {
            options.valid = false;
        }
        Point position;  // 点坐标
        float roll = 0;  // 翻滚角
        float pitch = 0; // 俯仰角
        float yaw = 0;   //横摆角
    };

    // 位置数组数据
    struct ScenePoseArray : public SceneObject
    {
        std::vector<ScenePose> poses; //位姿数组
        void append(const ScenePose &scenePose)
        {
            poses.push_back(scenePose);
        }

        void clear()
        {
            poses.clear();
        }
    };

    // 点云数据
    struct ScenePointCloud : public SceneObject
    {
        Points points; // 点集
        void append(const Point &p)
        {
            points.append(p);
        }
        void clear()
        {
            points.clear();
        }
    };

    // 通用marker标志位
    enum MARKER_TYPE
    {
        PATH = 0,
        POLYGON = 1,
        CIRCLE = 3,
        POSE = 4,
        POINT_CLOUD = 5,
        NONE_TYPE
    };
    // 通用Marker数据
    struct SceneMarker : public SceneObject
    {
        int type = MARKER_TYPE::NONE_TYPE; // marker类型
        ScenePath path;                    // 路径
        ScenePolygon polygon;              //多边形
        SceneCircle circle;                // 圆
        ScenePose pose;                    // 位姿
        ScenePointCloud pointCloud;        //点云
    };

    // 通用marker数据组合
    struct SceneMarkerArray : public SceneObject
    {
        std::vector<SceneMarker> markers; // marker数组
        void append(const SceneMarker &sceneMarker)
        {
            markers.push_back(sceneMarker);
        }
        void clear()
        {
            markers.clear();
        }
    };

    // double数组
    struct DoubleVector : public std::vector<double>
    {

        void append(const double &value)
        {
            push_back(value);
        }
    };
    // string关联数组
    struct StringValueMap : public std::map<std::string, std::string>
    {
        /**
         * @brief 添加一个数据
         * @param name 数据名
         * @param value 数据值
         */
        void Insert(const std::string &name, const std::string &value)
        {

            this->emplace(name, value);
        }

        /**
         * @brief 获取数据值
         * @param name 数据名
         * @return std::string 数据值
         */
        std::string Get(const std::string &name) const
        {
            auto it = this->find(name);
            if (it != this->end())
            {
                return it->second;
            }
            return "";
        }

        /**
         * @brief 重载赋值操作符
         * @param other 要赋值的关联数组
         * @return StringValueMap& 自身
         */
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

    // double类型关联数组
    struct DoubleValueMap : public std::map<std::string, double>
    {
        /**
         * @brief 添加一个数据
         * @param name 数据名
         * @param value 数据值
         */
        void Insert(const std::string &name, const double value)
        {
            this->emplace(name, value);
        }

        /**
         * @brief 获取数据值
         * @param name 数据名
         * @return double 数据值
         */
        double Get(const std::string &name) const
        {
            auto it = this->find(name);
            if (it != this->end())
            {
                return it->second;
            }
            return 0.0;
        }

        /**
         * @brief 重载赋值操作符
         * @param other 要赋值的关联数组
         * @return DoubleValueMap& 自身
         */
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

}
#endif /* __SCENE_DATA_TYPES_H__ */
