#pragma once
#include "iostream"

#include "Figure.h"

class Rectangle : public Figure
{
private:
	Vector2f size;

public:
	Rectangle();

	void setSize(Vector2f size);
	Vector2f getSize();

	void draw(AbstractWindow& window) override{}
};

