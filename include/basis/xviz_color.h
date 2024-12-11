/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-15 10:32:34
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-07-20 22:40:58
 */


#ifndef __XVIZ_COLOR_H__
#define __XVIZ_COLOR_H__
namespace basis
{
    struct Color
    {
        Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255) : R(r), G(g), B(b), A(a) {}
        uint8_t R;
        uint8_t G;
        uint8_t B;
        uint8_t A;
    };

    const Color XVIZ_WHITE = Color(255, 255, 255, 255);
    const Color XVIZ_YELLOW = Color(255, 255, 0, 255);
    const Color XVIZ_GREEN = Color(0, 255, 0, 255);
    const Color XVIZ_BLUE = Color(0, 0, 255, 255);
    const Color XVIZ_RED = Color(255, 0, 0, 255);
    const Color XVIZ_BLACK = Color(0, 0, 0, 255);
    const Color XVIZ_ORANGE = Color(255, 165, 0, 255);
    const Color XVIZ_PURPLE = Color(128, 0, 128, 255);
    const Color XVIZ_PINK = Color(255, 192, 203, 255);
    const Color XVIZ_CYAN = Color(0, 255, 255, 255);
    const Color XVIZ_MAGENTA = Color(255, 0, 255, 255);
    const Color XVIZ_GRAY = Color(128, 128, 128, 255);
    const Color XVIZ_BROWN = Color(165, 42, 42, 255);
    const Color XVIZ_LIGHT_GRAY = Color(211, 211, 211, 255);
    const Color XVIZ_LIGHT_YELLOW = Color(255, 255, 191, 255);
    const Color XVIZ_LIGHT_GREEN = Color(144, 238, 144, 255);
    const Color XVIZ_LIGHT_BLUE = Color(135, 206, 235, 255);
    const Color XVIZ_LIGHT_RED = Color(255, 165, 0, 255);
    const Color XVIZ_LIGHT_ORANGE = Color(255, 165, 0, 255);
    const Color XVIZ_LIGHT_PURPLE = Color(173, 111, 133, 255);
    const Color XVIZ_LIGHT_PINK = Color(255, 192, 203, 255);
    const Color XVIZ_LIGHT_CYAN = Color(224, 255, 255, 255);
    const Color XVIZ_LIGHT_MAGENTA = Color(255, 192, 224, 255);
    const Color XVIZ_LIGHT_BROWN = Color(153, 102, 51, 255);
    const Color XVIZ_LIGHT_LIGHT_YELLOW = Color(255, 255, 224, 255);
    const Color XVIZ_LIGHT_LIGHT_GREEN = Color(152, 251, 152, 255);
    const Color XVIZ_LIGHT_LIGHT_BLUE = Color(147, 197, 224, 255);
    const Color XVIZ_LIGHT_LIGHT_RED = Color(255, 204, 153, 255);
    const Color XVIZ_LIGHT_LIGHT_ORANGE = Color(255, 204, 153, 255);
    const Color XVIZ_LIGHT_LIGHT_PURPLE = Color(191, 148, 224, 255);
    const Color XVIZ_LIGHT_LIGHT_PINK = Color(255, 229, 204, 255);
    const Color XVIZ_LIGHT_LIGHT_CYAN = Color(237, 255, 255, 255);
    const Color XVIZ_LIGHT_LIGHT_MAGENTA = Color(255, 229, 238, 255);
    const Color XVIZ_LIGHT_LIGHT_GRAY = Color(230, 230, 230, 255);
    const Color XVIZ_LIGHT_LIGHT_BROWN = Color(189, 147, 112, 255);

}

#endif /* __XVIZ_COLOR_H__ */
