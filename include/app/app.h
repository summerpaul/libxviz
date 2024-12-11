/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 10:38:22
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-11-26 11:01:30
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
    App();
    virtual ~App();
    /**
   * @brief 程序初始化
   * @return true 初始化成功 false 初始化失败
   */
    bool Init();

    /**
   * @brief  运行程序
   *
   */
    void Run();

    /**
   * @brief 可视化数据渲染
   *
   */
    void Update();

    /**
   * @brief 销毁可视化
   *
   */

    void Shutdown();

    /**
   * @brief 判断程序是否在运行
   *
   */
    bool IsRunning();

    /**
   * @brief 添加自定义可视化图层
   * @param layer
   */
    void AddLayer(ui::BaseLayer::Ptr layer);

    /**
   * @brief 添加函数，用于可视化
   *
   * @param name
   * @param callback
   */
    void RegisterUiCallback(const std::string &name,
                            const std::function<void()> &callback);

    /**
   * @brief 使用event bus发布可视化数据
   * @param evt
   */
    void Publish(event_bus::Event *evt);

    void CreateRendererThread();

    void AddDoubleData(const std::string &name, const double data);
    void AddStringData(const std::string &name, const std::string &data);
    void AddRealtimeData(const std::string &name, const std::vector<double> &xs,
                         const std::vector<double> &ys);
    void PubDoubleDatas(const double &t);
    void PubStringDatas();

    void AddPath(const ScenePath &path, bool use_options = true);
    void AddPolygon(const ScenePolygon &polygon, const bool optionsValid = true);
    void AddCircle(const SceneCircle &circle, const bool optionsValid = true);
    void AddPose(const ScenePose &pose, const bool optionsValid = true);
    void AddPointCloud(const ScenePointCloud &cloud,
                       const bool optionsValid = true);
    void AddMarker(const SceneMarker &marker, const bool optionsValid = true);
    void AddPathArray(const ScenePathArray &pathArray,
                      const bool optionsValid = true);
    void AddPolygonArray(const ScenePolygonArray &polygonArray,
                         const bool optionsValid = true);
    void AddCircleArray(const SceneCircleArray &circleArray,
                        const bool optionsValid = true);
    void AddPoseArray(const ScenePoseArray &poseArray,
                      const bool optionsValid = true);
    void AddMarkerArray(const SceneMarkerArray &markerArray,
                        const bool optionsValid = true);
    void SetDrawFrameID(const std::string &frame_id);

    void ClearPlotData();
    void SetCurPlotTime(const double t);

  private:
    void RendererProcess();

  protected:
    Document *m_pDocument;
    bool m_initialized = false;
    DoubleValueMap m_doubleDatas;
    StringValueMap m_stringDatas;
    std::thread m_rendererThread;
  };

} // namespace app

#endif /* __APP_H__ */
