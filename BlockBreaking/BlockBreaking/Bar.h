#pragma once
#include "Color.h"
#include "Ball.h"

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

