#pragma once
typedef unsigned char uint8;

class Color
{
public:
	Color() = default;
	Color(uint8 r, uint8 g, uint8 b);
	Color(uint8 r, uint8 g, uint8 b, uint8 a);

	uint8 r;
	uint8 g;
	uint8 b;
	uint8 a;
};

