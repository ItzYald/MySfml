#include "SimpleLine.h"

SimpleLine::SimpleLine(Vector2f firstPosition, Vector2f secondPosition)
{
	this->firstPosition = firstPosition;
	this->secondPosition = secondPosition;
}

SimpleLine::SimpleLine(Vector2f firstPosition, Vector2f secondPosition, Color color)
{
	this->firstPosition = firstPosition;
	this->secondPosition = secondPosition;
	this->color = color;
}

void SimpleLine::setFirstPosition(Vector2f position)
{
	firstPosition = position;
}

Vector2f SimpleLine::getFirstPosition()
{
	return firstPosition;
}

void SimpleLine::setSecondPosition(Vector2f position)
{
	secondPosition = position;
}

Vector2f SimpleLine::getSecondPosition()
{
	return secondPosition;
}

void SimpleLine::setColor(Color color)
{
	this->color = color;
}

Color SimpleLine::getColor()
{
	return color;
}

void SimpleLine::draw(AbstractWindow& window)
{
}
