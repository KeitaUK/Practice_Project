#pragma once
#include "Color.h"
#include "Ball.h"

class Block
{
public:
	Block();
	Block(float x,float y,float w,float h);
	~Block();
	float posX, posY;
	float width,height;
	Color color;
	bool isBroken = false;

	void draw();
	void collisionWithBall(Ball& ball);
};

