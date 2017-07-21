#pragma once
#ifndef INCLUDE_COLOR
#define INCLUDE_COLOR

class Color
{
public:
	Color();
	Color(float red,float gleen,float blue);
	~Color();

	float r;
	float g;
	float b;
};

#endif // !INCLUDE_COLOR
