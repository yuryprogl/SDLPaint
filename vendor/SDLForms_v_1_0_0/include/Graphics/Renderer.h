#ifndef SDLFORMS_RENDERER_H
#define SDLFORMS_RENDERER_H

#pragma once
#include <SDL.h>
#include "../Containers/Vector2.h"
#include "../Graphics/ColorManager.h"

namespace Graphics
{
    class Renderer
    {
        public:
            /*
             * Draws simple line from point pos1 to point pos2.
             */
            void DrawLine(Containers::Vector2* pos1, Containers::Vector2* pos2);

            /*
             *  Draws a rectangles' border from start point (TopLeft point), with a spec size.
             */
            void DrawRect(Containers::Vector2* position, Containers::Vector2* size);

            /*
             *  Fills spec zone, in border of rectangle with start point (TopLeft point), with a spec size.
             */
            void FillRect(Containers::Vector2* position, Containers::Vector2* size);

            /*
             *  Fills spec zone, in border of circle with start center point, with a spec radius.
             */
            void FillCircle(Containers::Vector2* centre, int radius);

            /*
             *  Draws a circles' border with start center point, with a spec radius.
             */
            void DrawCircle(Containers::Vector2* centre, int radius);

            /*
             *  Switch buffers in order, use at the end of rendering. Standard replacement.
             */
            void CompleteRender();

            /*
             *  Clears buffer. standard replacement
             */
            void ClearRenderer();

            /*
             *  Basic Renderer constructor
             */
            Renderer(SDL_Renderer *sdlRenderer, SDL_Window *window);

            /*
             *  Changes Renderer color. Standard replacement with extension.
             */
            void SetColor(Graphics::Color* color);

            /*
             *  Changes Renderer color on already defined colors.
             */
            void SetColor(Graphics::ColorEnum ecolor);

            SDL_Renderer* GetSDLRenderer();

        private:
            SDL_Window *parentWindow;
            SDL_Renderer *sdlRenderer;
    };
}

#endif