#include "Transformable.h"

Transformable::Transformable(Vector2f position)
{
    setPosition(position);
}

Vector2f Transformable::getPosition()
{
    return position;
}

void Transformable::setPosition(Vector2f position)
{
    this->position = position;
}
