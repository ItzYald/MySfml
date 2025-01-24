#include "Color.h"

Color::Color(uint8 R, uint8 G, uint8 B) : 
	r(R), g(G), b(B)
{
	a = 255;
}

Color::Color(uint8 R, uint8 G, uint8 B, uint8 A) :
	r(R), g(G), b(B), a(A)
{
}
