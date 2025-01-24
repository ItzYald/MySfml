#pragma once
#include "iostream"

#include "Drawable.h"

class Rectangle : public Drawable
{
public:
	Rectangle();

	void draw(AbstractWindow& window) override{}
};

