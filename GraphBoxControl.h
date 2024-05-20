//
// Created by SPlaysYT on 20.05.2024.
//

#ifndef GRAPHBOXCONTROL_H
#define GRAPHBOXCONTROL_H
#pragma once
#include <Enums/FormEnums.h>
#include <Forms/Interfaces/IControl.h>
#include <Graphics/ColorManager.h>
#include <Graphics/Renderer.h>
#include <vector>

#include "CirclePoint.h"

class GraphBoxControl : public Forms::IControl {
public:
    void Draw() override;

    void EventCheckup(Uint32 type, SDL_Event *event) override;

    bool IsMouseInside(Containers::Vector2 *position) override;

public:
    Graphics::ColorEnum currentColor;
    std::pmr::vector<CirclePoint*> *points;
    Containers::Vector2 *Location;
    Containers::Vector2 *Size;
    Graphics::Color *BackgroundColor;
    Graphics::Color *ForegroundColor;
    bool *isMouseDown;
    bool *isMouseInside;

    void DoCleanUp();

    void (*OnMove) (IControl*, SDL_MouseMotionEvent) { };

    void (*OnLeft) (IControl*, SDL_MouseMotionEvent) { };

    void (*OnMouseDown) (IControl*, SDL_MouseButtonEvent) { };

    void (*OnMouseUp) (IControl*, SDL_MouseButtonEvent) { };

    GraphBoxControl(Graphics::Renderer *renderer);

    ~GraphBoxControl();

private:
    Graphics::Renderer *assignedRenderer;
};

#endif //GRAPHBOXCONTROL_H
