#pragma once
#include "Color.h"
class Ball
{
public:
	double r;
	Color color;
	double posX,posY;
	double moveX,moveY;

	Ball();
	Ball(double radius, float red, float gleen, float blue);
	Ball(double radius, double x, double y, float red, float gleen, float blue);

	~Ball();
	void draw();
	void draw(double posX, double posY);
	void draw(double posX, double posY, float red, float gleen, float blue);
	void moveBall();
};

