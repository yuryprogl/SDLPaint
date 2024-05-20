#include "GraphBoxControl.h"

#include "BasicFunctions.h"

void GraphBoxControl::Draw() {
    assignedRenderer->SetColor(BackgroundColor);
    assignedRenderer->FillRect(Location, Size);
    Containers::Vector2 vect(100,100);
    for (int i = 0; i < points->size(); i++) {
         vect.Fill(points->at(i)->x, points->at(i)->y);
         assignedRenderer->SetColor(points->at(i)->color);
         assignedRenderer->FillCircle(&vect, 9);
    }
}

void GraphBoxControl::EventCheckup(Uint32 type, SDL_Event *event) {
    switch (type) {
        case 0:
            switch (event->type) {
                case SDL_MOUSEMOTION:
                    if(*isMouseInside) {
                        *isMouseInside = false;
                        OnLeft(this, event->motion);
                    }
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            *isMouseDown = true;
            OnMouseDown(this, event->button);
        break;
        case SDL_MOUSEBUTTONUP:
            OnMouseUp(this, event->button);
            *isMouseDown = false;
        case SDL_MOUSEMOTION:
            if (*isMouseInside) {
                OnMove(this, event->motion);
            }
            else {
                *isMouseInside = true;
            }
        break;
    }
}

bool GraphBoxControl::IsMouseInside(Containers::Vector2 *position) {
    if (*position->x > *Location->x && *position->x < *Location->x + *Size->x)
       if (*position->y > *Location->y && *position->y < *Location->y + *Size->y) {
           return true;
       }
    return false;
}

void GraphBoxControl::DoCleanUp() {
    for (int i = 0; i < points->size(); i++) {
        delete points->at(i);
    }
    points->clear();
    delete points;
    points = new std::pmr::vector<CirclePoint*>();
}

GraphBoxControl::GraphBoxControl(Graphics::Renderer *renderer) {
    currentColor = Graphics::ColorEnum::Black;
    points = new std::pmr::vector<CirclePoint*>();
    assignedRenderer = renderer;
    Location = new Containers::Vector2(0,0);
    Size = new Containers::Vector2(0,0);
    BackgroundColor = new Graphics::Color(0,0,0,0);
    ForegroundColor = new Graphics::Color(0,0,0,0);
    OnLeft = BasicMoveEvent;
    OnMove = BasicMoveEvent;
    OnMouseDown = BasicClickEvent;
    OnMouseUp = BasicClickEvent;
    isMouseInside = new bool(); *isMouseInside = false;
    isMouseDown = new bool(); *isMouseDown = false;
}

GraphBoxControl::~GraphBoxControl() {
    delete Location;
    delete Size;
    delete BackgroundColor;
    delete ForegroundColor;
}




