#include "GradientLine.h"

GradientLine::GradientLine(Vector2f firstPointPosition, Vector2f secondPointPosition)
{
	firstPoint = ColorPoint(firstPointPosition);
	secondPoint = ColorPoint(secondPointPosition);
}

GradientLine::GradientLine(ColorPoint firstPoint, ColorPoint secondPoint)
{
	this->firstPoint = firstPoint;
	this->secondPoint = secondPoint;
}

void GradientLine::setFirstPointPosition(Vector2f position)
{
	firstPoint.position = position;
}

Vector2f GradientLine::getFirstPointPosition()
{
	return firstPoint.position;
}

void GradientLine::setSecondPointPosition(Vector2f position)
{
	secondPoint.position = position;
}

Vector2f GradientLine::getSecondPointPosition()
{
	return secondPoint.position;
}

void GradientLine::setFirstPointColor(Color color)
{
	firstPoint.color = color;
}

Color GradientLine::getFirstPointColor()
{
	return firstPoint.color;
}

void GradientLine::setSecondPointColor(Color color)
{
	secondPoint.color = color;
}

Color GradientLine::getSecondPointColor()
{
	return secondPoint.color;
}

void GradientLine::draw(AbstractWindow& window)
{
}
