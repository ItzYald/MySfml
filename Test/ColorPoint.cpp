#include "ColorPoint.h"

ColorPoint::ColorPoint(Vector2f position)
{
	this->position = position;
	color = Color();
}

ColorPoint::ColorPoint(Vector2f position, Color color)
{
	this->position = position;
	this->color = color;
}
