/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-15 10:32:34
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-17 16:39:57
 */

#ifndef __XVIZ_COLOR_H__
#define __XVIZ_COLOR_H__
namespace basis
{
    struct Color
    {
        Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255) : R(r), G(g), B(b), A(a) {}
        uint8_t R; // RED 0-255
        uint8_t G; // GREEN 0-255
        uint8_t B; // BLUE 0-255
        uint8_t A; // 透明度 0-255
    };

    const Color XVIZ_WHITE = Color(255, 255, 255, 255);               // 白色
    const Color XVIZ_YELLOW = Color(255, 255, 0, 255);                // 黄色
    const Color XVIZ_GREEN = Color(0, 255, 0, 255);                   // 绿色
    const Color XVIZ_BLUE = Color(0, 0, 255, 255);                    // 蓝色
    const Color XVIZ_RED = Color(255, 0, 0, 255);                     // 红色
    const Color XVIZ_BLACK = Color(0, 0, 0, 255);                     // 黑色
    const Color XVIZ_ORANGE = Color(255, 165, 0, 255);                // 橙色
    const Color XVIZ_PURPLE = Color(128, 0, 128, 255);                // 紫色
    const Color XVIZ_PINK = Color(255, 192, 203, 255);                // 粉色
    const Color XVIZ_CYAN = Color(0, 255, 255, 255);                  // 青色
    const Color XVIZ_MAGENTA = Color(255, 0, 255, 255);               // 品红色
    const Color XVIZ_GRAY = Color(128, 128, 128, 255);                // 灰色
    const Color XVIZ_BROWN = Color(165, 42, 42, 255);                 // 棕色
    const Color XVIZ_LIGHT_GRAY = Color(211, 211, 211, 255);          // 浅灰色
    const Color XVIZ_LIGHT_YELLOW = Color(255, 255, 191, 255);        // 浅黄色
    const Color XVIZ_LIGHT_GREEN = Color(144, 238, 144, 255);         // 浅绿色
    const Color XVIZ_LIGHT_BLUE = Color(135, 206, 235, 255);          // 浅蓝色
    const Color XVIZ_LIGHT_RED = Color(255, 165, 0, 255);             // 浅红色
    const Color XVIZ_LIGHT_ORANGE = Color(255, 165, 0, 255);          // 浅橙色
    const Color XVIZ_LIGHT_PURPLE = Color(173, 111, 133, 255);        // 浅紫色
    const Color XVIZ_LIGHT_PINK = Color(255, 192, 203, 255);          // 浅粉色
    const Color XVIZ_LIGHT_CYAN = Color(224, 255, 255, 255);          // 浅青色
    const Color XVIZ_LIGHT_MAGENTA = Color(255, 192, 224, 255);       // 浅品红色
    const Color XVIZ_LIGHT_BROWN = Color(153, 102, 51, 255);          // 浅棕色
    const Color XVIZ_LIGHT_LIGHT_YELLOW = Color(255, 255, 224, 255);  //淡黄色
    const Color XVIZ_LIGHT_LIGHT_GREEN = Color(152, 251, 152, 255);   // 淡绿色
    const Color XVIZ_LIGHT_LIGHT_BLUE = Color(147, 197, 224, 255);    //淡蓝色
    const Color XVIZ_LIGHT_LIGHT_RED = Color(255, 204, 153, 255);     // 淡红色
    const Color XVIZ_LIGHT_LIGHT_ORANGE = Color(255, 204, 153, 255);  // 淡橙色
    const Color XVIZ_LIGHT_LIGHT_PURPLE = Color(191, 148, 224, 255);  // 淡紫色
    const Color XVIZ_LIGHT_LIGHT_PINK = Color(255, 229, 204, 255);    //淡粉色
    const Color XVIZ_LIGHT_LIGHT_CYAN = Color(237, 255, 255, 255);    // 淡青色
    const Color XVIZ_LIGHT_LIGHT_MAGENTA = Color(255, 229, 238, 255); // 淡品红色
    const Color XVIZ_LIGHT_LIGHT_GRAY = Color(230, 230, 230, 255);    // 淡灰色
    const Color XVIZ_LIGHT_LIGHT_BROWN = Color(189, 147, 112, 255);   // 淡棕色
    const Color XVIZ_TRANSLUCENCY_YELLOW = Color(255, 255, 0, 100);   // 半透明黄色
    const Color XVIZ_TRANSLUCENCY_GREEN = Color(0, 255, 0, 100);      // 半透明绿色
    const Color XVIZ_TRANSLUCENCY_BLUE = Color(0, 0, 255, 100);       // 半透明蓝色
    const Color XVIZ_TRANSLUCENCY_RED = Color(255, 0, 0, 100);        // 半透明红色
    const Color XVIZ_TRANSLUCENCY_BLACK = Color(0, 0, 0, 100);        // 半透明黑色
    const Color XVIZ_TRANSLUCENCY_ORANGE = Color(255, 165, 0, 100);   // 半透明橙色
    const Color XVIZ_TRANSLUCENCY_PURPLE = Color(128, 0, 128, 100);   // 半透明紫色
    const Color XVIZ_TRANSLUCENCY_PINK = Color(255, 192, 203, 100);   // 半透明粉色
    const Color XVIZ_TRANSLUCENCY_CYAN = Color(0, 255, 255, 100);     // 半透明青色
    const Color XVIZ_TRANSLUCENCY_MAGENTA = Color(255, 0, 255, 100);  // 半透明品红色
    const Color XVIZ_TRANSLUCENCY_GRAY = Color(128, 128, 128, 100);   // 半透明灰色
    const Color XVIZ_TRANSLUCENCY_BROWN = Color(165, 42, 42, 100);    // 半透明棕色

}

#endif /* __XVIZ_COLOR_H__ */
