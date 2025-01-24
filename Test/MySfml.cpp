#include <iostream>
#include "Window.h"

int SDL_main(int argc, char* argv[])
{
    Window window = Window();
    window.init();

	SDL_Event e;

    while (window.isOpen())
    {
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				window.quit();
			}
		}

		Rectangle rect = Rectangle();
		Circle circle = Circle();

		window.draw(rect);
		//window.draw(circle);

		window.display();
    }

    window.quit();
    return 0;
}
