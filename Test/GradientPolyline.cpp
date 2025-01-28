#include "GradientPolyline.h"

GradientPolyline::GradientPolyline()
{
	points = std::vector<ColorPoint>();
}

void GradientPolyline::add(Vector2f position)
{
	points.push_back(ColorPoint(position));
}

void GradientPolyline::add(Vector2f position, Color color)
{
	points.push_back(ColorPoint(position, color));
}

void GradientPolyline::add(ColorPoint point)
{
	points.push_back(point);
}

void GradientPolyline::setPoint(int index, Vector2f position, Color color)
{
	if (index >= points.size() || index < 0) return;
	points[index] = ColorPoint(position, color);
}

ColorPoint GradientPolyline::getPoint(int index)
{
	if (index >= points.size() || index < 0) return ColorPoint();
	return points[index];
}

void GradientPolyline::setPointPosition(int index, Vector2f position)
{
	if (index >= points.size() || index < 0) return;
	points[index].position = position;
}

Vector2f GradientPolyline::getPointPosition(int index)
{
	if (index >= points.size() || index < 0) return Vector2f();
	return points[index].position;
}

void GradientPolyline::setPointColor(int index, Color color)
{
	if (index >= points.size() || index < 0) return;
	points[index].color = color;
}

Color GradientPolyline::getPointColor(int index)
{
	if (index >= points.size() || index < 0) return Color();
	return points[index].color;
}

int GradientPolyline::getPointsQuantity()
{
	return points.size();
}

std::vector<ColorPoint> GradientPolyline::getVector()
{
	return points;
}

void GradientPolyline::draw(AbstractWindow& window)
{
}
