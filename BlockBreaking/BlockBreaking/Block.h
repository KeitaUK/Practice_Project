#pragma once
#ifndef INCLUDE_BLOCK
#define INCLUDE_BLOCK

#include "Color.h"
#include "Ball.h"
#include "ObjectManager.h"
#include "ScoreManager.h"
#include <time.h>
#include "Texture.h"


class Block
{
public:
	Block();
	Block(float x,float y,float w,float h);
	~Block();
	Texture texture;
	float posX, posY;
	float width,height;
	Color color;
	bool isBroken = false;

	void draw();
	void collisionWithBall(Ball& ball, ObjectManager& objectMgr, ScoreManager& scoreMgr);
	void init(float x, float y, Color col, bool isBreak);

};

#endif // !
