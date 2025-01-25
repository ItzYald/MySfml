#pragma once
#include "Drawable.h"
#include "Vector2.h"
#include "Color.h"

class SimpleLine : public Drawable
{
	Vector2f firstPosition;
	Vector2f secondPosition;
	Color color;
public:
	SimpleLine() = default;
	SimpleLine(Vector2f firstPosition, Vector2f secondPosition);
	SimpleLine(Vector2f firstPosition, Vector2f secondPosition, Color color);

	void setFirstPosition(Vector2f position);
	Vector2f getFirstPosition();
	void setSecondPosition(Vector2f position);
	Vector2f getSecondPosition();
	void setColor(Color color);
	Color getColor();

	void draw(AbstractWindow& window) override;

};

