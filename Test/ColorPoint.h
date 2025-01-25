#pragma once
#include "Vector2.h"
#include "Color.h"

class ColorPoint
{
public:
	ColorPoint() = default;
	ColorPoint(Vector2f position);
	ColorPoint(Vector2f position, Color color);

	Vector2f position;
	Color color;
};

