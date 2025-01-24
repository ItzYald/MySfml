#include "Rectangle.h"

Rectangle::Rectangle()
{
	position = Vector2f();
	size = Vector2f();
}

void Rectangle::setSize(Vector2f size)
{
	this->size = size;
}

Vector2f Rectangle::getSize()
{
	return size;
}
