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

Color Color::operator+(const Color& rightColor)
{
	return Color(
		(unsigned char)std::min(r + rightColor.r, 255), 
		(unsigned char)std::min(g + rightColor.g, 255),
		(unsigned char)std::min(b + rightColor.b, 255));
}
