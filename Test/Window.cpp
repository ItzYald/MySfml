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

	// Draw border circle Y
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
	// Draw border circle X
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
	// Draw fill circle
	for (float x = -radius; x < radius; x += 0.5f)
	{
		float y = sqrtf(radius * radius - x * x);
		for (float fillY = -y; fillY < y; fillY++)
		{
			SDL_RenderDrawPoint(renderer, center.x + x, center.y + fillY);
		}
	}

}

void Window::drawGradientLine(GradientLine& line)
{
	Vector2f delta = line.getSecondPointPosition() - line.getFirstPointPosition();
	Vector2f firstPosition = line.getFirstPointPosition();
	Vector2f secondPosition = line.getSecondPointPosition();
	
	Color firstColor = line.getFirstPointColor();
	Color secondColor = line.getSecondPointColor();
	Vector2f normalizeVector = delta.normalize();
	if (delta.x > 0)
	{
		for (float x = 0; x < delta.x; x++)
		{
			float offsetK = x / delta.x;
			Color gradientColor = Color(
				firstColor.r * (1 - offsetK) + secondColor.r * offsetK,
				firstColor.g * (1 - offsetK) + secondColor.g * offsetK,
				firstColor.b * (1 - offsetK) + secondColor.b * offsetK,
				firstColor.a * (1 - offsetK) + secondColor.a * offsetK
			);
			SDL_SetRenderDrawColor(renderer,
				gradientColor.r, gradientColor.g, gradientColor.b, gradientColor.a);
			SDL_RenderDrawPoint(renderer, 
				firstPosition.x + x,
				firstPosition.y + (firstPosition.x + x) * normalizeVector.y / normalizeVector.x);
		}
	}
	else
	{
		for (float y = 0; y < delta.y; y++)
		{
			float offsetK = y / delta.x;
			Color gradientColor = Color(
				firstColor.r * (1 - offsetK) + secondColor.r * offsetK,
				firstColor.g * (1 - offsetK) + secondColor.g * offsetK,
				firstColor.b * (1 - offsetK) + secondColor.b * offsetK,
				firstColor.a * (1 - offsetK) + secondColor.a * offsetK
			);
			SDL_SetRenderDrawColor(renderer,
				gradientColor.r, gradientColor.g, gradientColor.b, gradientColor.a);
			SDL_RenderDrawPoint(renderer,
				firstPosition.x + (firstPosition.y + y) * normalizeVector.x / normalizeVector.y,
				firstPosition.y + y
				);
		}
	}
	
}

void Window::drawSimpleLine(SimpleLine& line)
{
	Color color = line.getColor();
	SDL_SetRenderDrawColor(renderer,
		color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer,
		line.getFirstPosition().x, line.getFirstPosition().y,
		line.getSecondPosition().x, line.getSecondPosition().y);
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
	{
		GradientLine* line = dynamic_cast<GradientLine*>(drawablePtr);
		if (line != nullptr)
		{
			drawGradientLine(*line);
			line = nullptr;
			drawablePtr = nullptr;
			return;
		}
	}
	{
		SimpleLine* line = dynamic_cast<SimpleLine*>(drawablePtr);
		if (line != nullptr)
		{
			drawSimpleLine(*line);
			line = nullptr;
			drawablePtr = nullptr;
			return;
		}
	}
	drawableObject.draw(*this);
}

