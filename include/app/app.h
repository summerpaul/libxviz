/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 10:38:22
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-18 15:04:12
 */

#ifndef __APP_H__
#define __APP_H__
#include <thread>

#include "basis/base_layer.h"
#include "basis/scene_data_types.h"

using namespace basis;
class Document;

namespace event_bus
{
  class Event;
}

namespace app
{
  class App
  {
  public:
    /**
     * @brief 构造函数
     * 
     */
    App();

    /**
     * @brief 析构函数
     * 
     */

    virtual ~App();

    /**
     * @brief 程序初始化
     * 
     * @return true 初始化成功
     * @return false 初始化失败
     */
    bool Init();

    /**
     * @brief 运行程序
     * 
     */
    void Run();

    /**
     * @brief 更新数据渲染
     * 
     */
    void Update();

    /**
     * @brief 销毁资源
     * 
     */
    void Shutdown();

    /**
     * @brief 判断程序是否在运行
     * 
     * @return true 程序在运行
     * @return false 程序已关闭
     */
    bool IsRunning();

    /**
     * @brief 添加自定义可视化图层
     * 
     * @param layer 自定义的图层
     */
    void AddLayer(ui::BaseLayer::Ptr layer);

    /**
   * @brief 添加函数，用于可视化
   *
   * @param name 函数名
   * @param callback 包含可视化的函数
   */
    void RegisterUiCallback(const std::string &name,
                            const std::function<void()> &callback);

    /**
     * @brief 向可视化窗口发布事件
     * 
     * @param evt 事件
     */
    void Publish(event_bus::Event *evt);

    /**
     * @brief 向double关联数组添加数据，添加所有数据后，需要调用PubDoubleDatas(t)
     * @param name 数据名
     * @param data 数据
     */
    void AddDoubleData(const std::string &name, const double data);

    /**
     * @brief 向string关联数组添加数据，添加所有数据后，需要调用PubStringDatas()
     * @param name 数据名
     * @param data 数据
     */
    void AddStringData(const std::string &name, const std::string &data);

    /**
     * @brief 添加实时数据 
     * 
     * @param name 数据名
     * @param xs x轴数据（可为空）
     * @param ys y轴数据（可为空）
     */
    void AddRealtimeData(const std::string &name, const std::vector<double> &xs,
                         const std::vector<double> &ys);

    /**
     * @brief 在添加完所有Double数据后调用
     * 
     * @param t 数据时间戳
     */
    void PubDoubleDatas(const double &t);

    /**
     * @brief 在添加完所有String数据后调用
     * 
     */
    void PubStringDatas();

    /**
     * @brief 添加可视化路径（线）
     * 
     * @param path 路径
     * @param use_options 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPath(const ScenePath &path, bool use_options = true);

    /**
     * @brief 添加可视化路径数组
     * 
     * @param pathArray 路径数组
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPathArray(const ScenePathArray &pathArray,
                      const bool optionsValid = true);

    /**
     * @brief 添加可视化多边形
     * 
     * @param polygon 多边形
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPolygon(const ScenePolygon &polygon, const bool optionsValid = true);

    /**
     * @brief 添加可视化多边形数组
     * 
     * @param polygonArray 多边形数组
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPolygonArray(const ScenePolygonArray &polygonArray,
                         const bool optionsValid = true);

    /**
     * @brief 添加可视化圆
     * 
     * @param circle 圆
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddCircle(const SceneCircle &circle, const bool optionsValid = true);

    /**
     * @brief 添加可视化圆数组
     * 
     * @param circleArray 圆数组
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddCircleArray(const SceneCircleArray &circleArray,
                        const bool optionsValid = true);

    /**
     * @brief 添加可视化位姿
     * 
     * @param pose 位姿
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPose(const ScenePose &pose, const bool optionsValid = true);

    /**
     * @brief 添加PoseArray绘图对象
     * 
     * @param poseArray PoseArray绘图对象
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPoseArray(const ScenePoseArray &poseArray,
                      const bool optionsValid = true);

    /**
     * @brief 添加可视化点云
     * 
     * @param cloud 点云
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddPointCloud(const ScenePointCloud &cloud,
                       const bool optionsValid = true);

    /**
     * @brief 添加可视化点云数组
     * 
     * @param cloudArray 点云数组
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddMarker(const SceneMarker &marker, const bool optionsValid = true);

    /**
     * @brief 添加MarkerArray绘图对象
     * 
     * @param markerArray MarkerArray绘图对象
     * @param optionsValid 是否使用对象中的配置选项（false后界面可以重设）
     */
    void AddMarkerArray(const SceneMarkerArray &markerArray,
                        const bool optionsValid = true);

    /**
     * @brief 设置绘制的坐标系
     * 
     * @param frame_id 
     */
    void SetDrawFrameID(const std::string &frame_id);

    /**
     * @brief 清空数据
     * 
     */
    void ClearPlotData();

    /**
     * @brief 设置绘制时的时间戳
     * 
     * @param t 
     */
    void SetCurPlotTime(const double t);

  protected:
    Document *m_pDocument;
    bool m_initialized = false;
    DoubleValueMap m_doubleDatas;
    StringValueMap m_stringDatas;
  };

} // namespace app

#endif /* __APP_H__ */
