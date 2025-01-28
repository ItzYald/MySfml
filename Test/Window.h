#pragma once
#include <iostream>

#include "SDL.h"

#include "AbstractWindow.h"
#include "Rectangle.h"
#include "Circle.h"
#include "GradientLine.h"
#include "SimpleLine.h"
#include "GradientPolyline.h"


class Window : public AbstractWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect* sdlRect;
    SDL_Event e;

    void drawRect(Rectangle& rectangle);
    void drawCircle(Circle& circle);
    void drawGradientLine(GradientLine& line);
    void drawSimpleLine(SimpleLine& line);
    void drawGradientPolyline(GradientPolyline& line);

public:
    Window(Vector2i size);

    void dispatchEvents();

    void draw(Drawable& drawableObject);

    bool isOpen();

    void display();

    void quit();

};

