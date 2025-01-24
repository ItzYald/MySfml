#pragma once

class Drawable;

class AbstractWindow
{
    virtual void draw(Drawable& drawableObject) = 0;
};
