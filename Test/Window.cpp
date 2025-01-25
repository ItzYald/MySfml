#include "Window.h"

Window::Window(Vector2i size)
{
	window = NULL;
	renderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("MySfml",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_SHOWN);

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

	for (size_t i = 0; i < rectangle.getBorderThickness(); i++)
	{
		sdlRect->x -= 1;
		sdlRect->y -= 1;
		sdlRect->w += 2;
		sdlRect->h += 2;
		SDL_RenderDrawRect(renderer, sdlRect);
	}
}

void Window::drawCircle(Circle& circle)
{
	Color fillColor = circle.getFillColor();
	Color borderColor = circle.getBorderColor();

	const int radius = circle.getRadius();

	const Vector2i center = Vector2i(
		circle.getPosition().x + radius,
		circle.getPosition().y + radius);

	SDL_SetRenderDrawColor(renderer,
		borderColor.r, borderColor.g, borderColor.b, borderColor.a);

	for (float x = -radius; x < radius; x += 0.5f)
	{
		float y;
		for (size_t borderThickness = 0; borderThickness < circle.getBorderThickness(); borderThickness++)
		{
			int radiusAndBorder = borderThickness + radius;
			y = sqrtf(radiusAndBorder * radiusAndBorder - x * x);
			SDL_RenderDrawPoint(renderer, center.x + x, center.y + y);
			SDL_RenderDrawPoint(renderer, center.x + x, center.y - y);
		}
	}

	for (float y = -radius; y < radius; y += 0.5f)
	{
		float x = sqrtf(radius * radius - y * y);
		for (size_t borderThickness = 0; borderThickness < circle.getBorderThickness(); borderThickness++)
		{
			int radiusAndBorder = borderThickness + radius;
			x = sqrtf(radiusAndBorder * radiusAndBorder - y * y);
			SDL_RenderDrawPoint(renderer, center.x + x, center.y + y);
			SDL_RenderDrawPoint(renderer, center.x - x, center.y + y);
		}
	}

	SDL_SetRenderDrawColor(renderer,
		fillColor.r, fillColor.g, fillColor.b, fillColor.a);
	for (float x = -radius; x < radius; x += 0.5f)
	{
		float y = sqrtf(radius * radius - x * x);
		for (float fillY = -y; fillY < y; fillY++)
		{
			SDL_RenderDrawPoint(renderer, center.x + x, center.y + fillY);
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
			rectangle = nullptr;
			drawablePtr = nullptr;
			return;
		}
	}
	{
		Circle* circle = dynamic_cast<Circle*>(drawablePtr);
		if (circle != nullptr)
		{
			drawCircle(*circle);
			circle = nullptr;
			drawablePtr = nullptr;
			return;
		}
	}
	drawableObject.draw(*this);
}

