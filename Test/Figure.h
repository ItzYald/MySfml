#pragma once
#include "Drawable.h"
#include "Transformable.h"
#include "Color.h"

class Figure : public Drawable, public Transformable
{
private:
	Color fillColor;
	Color borderColor;
	int borderThickness;

protected:
	Figure() = default;

public:
	Color getFillColor();
	void setFillColor(Color color);
	Color getBorderColor();
	void setBorderColor(Color color);
	int getBorderThickness();
	void setBorderThickness(int thickness);

};

