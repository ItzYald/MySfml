#pragma once
#include "Vector2.h"

class Transformable
{
protected:
	Vector2f position;
	Transformable() = default;
	Transformable(Vector2f position);
public:
	Vector2f getPosition();
	void setPosition(Vector2f position);

};

