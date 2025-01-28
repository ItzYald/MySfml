#pragma once
#include <vector>

#include "Drawable.h"
#include "ColorPoint.h"

class GradientPolyline : public Drawable
{
private:
	std::vector<ColorPoint> points;

public:
	GradientPolyline();

	void add(Vector2f position);
	void add(Vector2f position, Color color);
	void add(ColorPoint point);

	void setPoint(int index, Vector2f position, Color color);
	ColorPoint getPoint(int index);
	void setPointPosition(int index, Vector2f position);
	Vector2f getPointPosition(int index);
	void setPointColor(int index, Color color);
	Color getPointColor(int index);

	int getPointsQuantity();

	std::vector<ColorPoint> getVector();
	
	void draw(AbstractWindow& window) override;

};

