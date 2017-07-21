#pragma once
#ifndef INCLUDE_BAR
#define INCLUDE_BAR

#include "Color.h"
#include "Ball.h"
#include "Constants.h"
class Bar
{
public:
	Bar();
	~Bar();
	float width,height;
	float posX, posY;
	Color color;

	void draw();
	void collisionWithBall(Ball& ball);
	void move(float deltaX);
};


#endif