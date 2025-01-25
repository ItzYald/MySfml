#include "Figure.h"

Color Figure::getFillColor()
{
	return fillColor;
}

void Figure::setFillColor(Color color)
{
	fillColor = color;
}

Color Figure::getBorderColor()
{
	return borderColor;
}

void Figure::setBorderColor(Color color)
{
	borderColor = color;
}

int Figure::getBorderThickness()
{
	return borderThickness;
}

void Figure::setBorderThickness(int thickness)
{
	borderThickness = thickness;
}
