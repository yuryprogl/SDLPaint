#ifndef CIRCLEPOINT_H
#define CIRCLEPOINT_H

#pragma once
#include "Graphics/ColorManager.h"

struct CirclePoint {
    int x, y;
    Graphics::ColorEnum color;

    CirclePoint();
    CirclePoint(int x, int y, Graphics::ColorEnum color);
};

#endif //CIRCLEPOINT_H
