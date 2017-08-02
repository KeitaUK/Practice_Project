#pragma once
struct Vec2
{
	double x;
	double y;
	Vec2() = default;
	Vec2(double posX, double posY)
	{
		x = posX;
		y = posY;
	}
}; 