#include "SimplePolyline.h"

SimplePolyline::SimplePolyline(Color color)
{
	this->color = color;
}

Vector2f SimplePolyline::getPointPosition(int index)
{
	if (index >= pointsPositions.size() || index < 0) return;
	return pointsPositions[index];
}

void SimplePolyline::setPointPosition(int index, Vector2f position)
{
	if (index >= pointsPositions.size() || index < 0) return;
	pointsPositions[index] = position;
}

Color SimplePolyline::getColor()
{
	return color;
}

void SimplePolyline::setColor(Color color)
{
	this->color = color;
}

void SimplePolyline::draw(AbstractWindow& window)
{
}
