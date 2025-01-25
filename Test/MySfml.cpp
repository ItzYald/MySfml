﻿#include <iostream>
#include "Window.h"

int SDL_main(int argc, char* argv[])
{
    Window window = Window(Vector2i(1280, 720));

	Rectangle rect = Rectangle();
	rect.setPosition(Vector2f(100.f, 200.f));
	rect.setSize(Vector2f(100, 50));
    rect.setFillColor(Color(255, 0, 0));
    rect.setBorderColor(Color(255, 255, 0));
    rect.setBorderThickness(5);

    Circle circle = Circle();
    circle.setPosition(Vector2f(200, 100));
    circle.setRadius(50);
    circle.setFillColor(Color(0, 0, 255));
    circle.setBorderColor(Color(10, 255, 10));
    circle.setBorderThickness(10);

    GradientLine gradientLine = GradientLine(Vector2f(10, 300), Vector2f(400, 420));
    gradientLine.setFirstPointColor(Color(10, 255, 10));
    gradientLine.setSecondPointColor(Color(10, 10, 255));

    SimpleLine simpleLine = SimpleLine(
        Vector2f(400, 200), Vector2f(500, 250), Color(255, 255, 255));

    while (window.isOpen())
    {
        window.dispatchEvents();

		window.draw(rect);
		window.draw(circle);
		window.draw(gradientLine);
		window.draw(simpleLine);

		window.display();
    }

    return 0;
}
