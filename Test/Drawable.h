#pragma once

#include "AbstractWindow.h"

class Drawable
{
public:
	virtual void draw(AbstractWindow& window) = 0;
};

