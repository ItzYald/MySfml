#pragma once
#include <vector>

#include "Drawable.h"
#include "Vector2.h"
#include "Color.h"


class SimplePolyline : public Drawable
{
private:
	std::vector<Vector2f> pointsPositions;
	Color color;

public:
	SimplePolyline(Color color);

	Vector2f getPointPosition(int index);
	void setPointPosition(int index, Vector2f position);
	Color getColor();
	void setColor(Color color);
	
	void draw(AbstractWindow& window) override;

};

