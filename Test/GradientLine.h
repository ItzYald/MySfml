#pragma once
#include "Drawable.h"
#include "ColorPoint.h"

class GradientLine : public Drawable
{
private:
	ColorPoint firstPoint;
	ColorPoint secondPoint;

public:

	GradientLine() = default;
	GradientLine(Vector2f firstPointPosition, Vector2f secondPointPosition);
	GradientLine(ColorPoint firstPoint, ColorPoint secondPointPosition);

	void setFirstPointPosition(Vector2f position);
	Vector2f getFirstPointPosition();
	void setSecondPointPosition(Vector2f position);
	Vector2f getSecondPointPosition();
	void setFirstPointColor(Color color);
	Color getFirstPointColor();
	void setSecondPointColor(Color color);
	Color getSecondPointColor();

	void draw(AbstractWindow& window) override;
};

