/**
 * @Author: Xia Yunkai
 * @Date:   2024-09-09 14:50:53
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-09-09 14:51:21
 */
#include <stdint.h>

#ifndef __DRAW_UTILS_H__
#define __DRAW_UTILS_H__
#include "basis/scene_data_types.h"

using namespace basis;
// 三次多项式的值
static float GetCubicPolyValue(const float *curve_param, float x)
{
    float y = 0.0f;
    y = curve_param[0] + curve_param[1] * x + curve_param[2] * (x * x) + curve_param[3] * (x * x * x);
    return y;
}

inline void GenRectangle(const float pose_left_x, const float pose_top_y, const float pose_right_x, const float pose_bottom_y, basis::Points &points)
{
    points.clear();
    points.emplace_back(pose_left_x, pose_top_y, 0);     // p0
    points.emplace_back(pose_right_x, pose_top_y, 0);    // p1
    points.emplace_back(pose_right_x, pose_bottom_y, 0); // p2
    points.emplace_back(pose_left_x, pose_bottom_y, 0);  // p2
}

inline void GenRectangle(const basis::Point &near_pt, const basis::Point &far_pt, basis::Points &points)
{
    const float pose_left_x = near_pt.x;
    const float pose_bottom_y = near_pt.y;
    const float pose_right_x = far_pt.x;
    const float pose_top_y = far_pt.y;
    GenRectangle(pose_left_x, pose_top_y, pose_right_x, pose_bottom_y, points);
}

inline void GenRectangle(const basis::Point &pose, const float width, const float height, basis::Points &points, bool is_center_pose = false)
{
    float pose_left_x = 0;
    float pose_top_y = 0;
    float pose_right_x = 0;
    float pose_bottom_y = 0;
    if (is_center_pose)
    {
        pose_left_x = pose.x - width * 0.5f;
        pose_bottom_y = pose.y - height * 0.5f;
        pose_right_x = pose.x + width * 0.5f;
        pose_top_y = pose.y + height * 0.5f;
    }
    else
    {
        pose_left_x = pose.x;
        pose_bottom_y = pose.y;
        pose_right_x = pose.x + width;
        pose_top_y = pose.y + height;
    }

    GenRectangle(pose_left_x, pose_top_y, pose_right_x, pose_bottom_y, points);
}

inline void GenRectangle(const basis::Point &pose, const float angle, const float width, const float height, basis::Points &points, bool is_center_pose = false)
{
    float pose_left_x = 0;
    float pose_top_y = 0;
    float pose_right_x = 0;
    float pose_bottom_y = 0;
    if (is_center_pose)
    {
        pose_left_x = pose.x - width * 0.5f;
        pose_bottom_y = pose.y - height * 0.5f;
        pose_right_x = pose.x + width * 0.5f;
        pose_top_y = pose.y + height * 0.5f;
    }
    else
    {
        pose_left_x = pose.x;
        pose_bottom_y = pose.y;
        pose_right_x = pose.x + width;
        pose_top_y = pose.y + height;
    }

    GenRectangle(pose_left_x, pose_top_y, pose_right_x, pose_bottom_y, points);
}

template <typename Path>
inline void GetPointsFromPath(const Path &path_in, const int pt_num, basis::Points &points, const float ratio = 1.0f)
{
    points.clear();
    points.resize(pt_num);
    for (int i = 0; i < pt_num; i++)
    {
        const float x = path_in[i].x * ratio;
        const float y = path_in[i].y * ratio;
        points[i] = basis::Point(x, y);
    }
}

#endif /* __DRAW_UTILS_H__ */
