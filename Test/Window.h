#pragma once
#include <iostream>

#include "SDL.h"

#include "AbstractWindow.h"
#include "Rectangle.h"
#include "Circle.h"


class Window : public AbstractWindow
{
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
	Window()
	{
        window = NULL;
        renderer = NULL;
	}

    bool init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            return false;
        }

        window = SDL_CreateWindow("SDL Tutorial",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            SDL_Quit();
            return false;
        }

        renderer =
            SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
        {
            return false;
        }

        return true;
    }

    void drawRect(Rectangle& rectangle)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawLine(renderer, 10, 70, 640 - 10, 70);
        std::cout << "rectangle";
    }

    void drawCircle(Circle& circle)
    {
        std::cout << "circle";
    }

    void draw(Drawable& drawableObject)
    {
        Drawable* drawablePtr = &drawableObject;
        {
            Rectangle* rectangle = dynamic_cast<Rectangle*>(drawablePtr);
            if (rectangle != nullptr)
            {
                drawRect(*rectangle);
            }
            rectangle = NULL;
            drawablePtr = NULL;
            return;
        }
        {
            Circle* circle = dynamic_cast<Circle*>(drawablePtr);
            if (circle != nullptr)
            {
                drawCircle(*circle);
            }
            circle = NULL;
            drawablePtr = NULL;
            return;
        }
        drawableObject.draw(*this);
    }

    bool isOpen()
    {
        if (window == NULL)
        {
            return false;
        }
        return true;
    }

    void display()
    {
        SDL_RenderPresent(renderer);
    }

    void quit()
    {
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
        SDL_Quit();
    }

};

