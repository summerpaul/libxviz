/**
 * @Author: Xia Yunkai
 * @Date:   2024-09-06 23:35:28
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-18 15:14:10
 */
#include <stdint.h>

#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include <memory>
#include <string>
#include <vector>

namespace ui
{
    class BaseLayer
    {
    public:
        typedef std::shared_ptr<BaseLayer> Ptr; // 共享指针
        /**
         * @brief 构建函数
         * 
         * @param name 图层名
         */
        BaseLayer(const std::string &name = "") : m_name(name) {}

        /**
         * @brief 析构函数
         * 
         */
        virtual ~BaseLayer() {}

        /**
         * @brief 获取图层名
         * 
         * @return const std::string& 图层名
         */
        const std::string &GetName() const { return m_name; }

        /**
         * @brief 该函数会被Xviz周期调用，可用于绘制IMGUI控件
         * 
         * @param deltaTime 与上次调用时间间隔
         */
        virtual void Update(float deltaTime){};

        /**
         * @brief 图层内部数据初始化
         * 
         * @return true 
         * @return false 
         */
        virtual bool Init() { return false; }

        /**
         * @brief 被Xviz调用，当向主窗口拖动文件，会调用该函数
         * 
         * @param count 文件数量
         * @param paths 文件地址数组
         */
        virtual void FilesDropCallback(int count, const char **paths) {}

        /**
         * @brief 被Xviz调用，打开Open file控件，会调用该函数
         * 
         * @param paths 文件地址数组
         */
        virtual void FilesOpenCallback(const std::vector<std::string> &paths) {}

        /**
         * @brief 在关闭程序时，会被XVIZ调用
         * 
         */
        virtual void Shutdown(){};

        /**
         * @brief 获取图层初始化状态
         * 
         * @return true 
         * @return false 
         */
        bool IsInitialized() const { return m_initialized; }

    protected:
        std::string m_name;         // 图层名
        bool m_initialized = false; // 初始化标志位
    };
}

#endif /* __BASE_LAYER_H__ */
