//
// Created by SPlaysYT on 20.05.2024.
//

#include "CirclePoint.h"

CirclePoint::CirclePoint() {
    x = 0;
    y = 0;
    color = Graphics::ColorEnum::Black;
}

CirclePoint::CirclePoint(int x, int y, Graphics::ColorEnum color) {
    this->x = x;
    this->y = y;
    this->color = color;
}



