#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	float radius;

public:
	void draw(AbstractWindow& window){}

	float getRadius();
	void setFadius(float radius);

};

