#pragma once
#ifndef INCLUDED_BALL
#define INCLUDED_BALL

#include "Color.h"
#include "Constants.h"

class Ball
{
public:
	float r;
	Color color;
	float posX,posY;
	float moveX,moveY;
	float moveSize = 10;

	Ball();
	Ball(float radius, float x, float y, float red, float gleen, float blue);

	~Ball();
	void draw();
	void draw(float posX, float posY);
	void draw(float posX, float posY, float red, float gleen, float blue);
	void moveBall();
};

#endif