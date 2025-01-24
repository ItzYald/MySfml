#include "Window.h"

Window::Window()
{
    window = NULL;
    renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

    renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    sdlRect = new SDL_Rect();
}

void Window::dispatchEvents()
{
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            quit();
        }
    }
}

void Window::draw(Drawable& drawableObject)
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

bool Window::isOpen()
{
    if (window == NULL)
    {
        return false;
    }
    return true;
}

void Window::display()
{
    SDL_RenderPresent(renderer);
}

void Window::quit()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
}

void Window::drawRect(Rectangle& rectangle)
{
    sdlRect->x = rectangle.getPosition().x;
    sdlRect->y = rectangle.getPosition().y;
    sdlRect->w = rectangle.getSize().x;
    sdlRect->h = rectangle.getSize().y;

    Color fillColor = rectangle.getFillColor();
    SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    
    SDL_RenderFillRect(renderer, sdlRect);

    Color borderColor = rectangle.getBorderColor();
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);

    SDL_RenderDrawRect(renderer, sdlRect);
}

void Window::drawCircle(Circle& circle)
{

}
