#include "Block.h"
#include <gl/freeglut.h>
#include <stdio.h>

Block::Block()
{
	color.r = 0.7;
	color.g = 0.2;
	color.b = 0.2;
	posX = posY = 0;
	width = 60;
	height = 20;
}

Block::Block(float x, float y, float w, float h)
{
	color.r = 0.7;
	color.g = 0.2;
	color.b = 0.2;
	posX = x;
	posY = y;
	width = w;
	height = h;
}



Block::~Block()
{
}

void Block::draw()
{
	if (isBroken)
		return;

	glColor4f(color.r,color.g,color.b,0.0);

	glRectf(posX - width/2, posY - height / 2,posX + width/2,posY + height/2);
	

}


void Block::collisionWithBall(Ball& ball,ObjectManager& objectMgr, ScoreManager& scoreMgr)
{
	if (isBroken)
		return;

	//ボールが右側から触れたら反射
	if ((ball.posX > posX) && ((ball.posX - ball.r * 2) <= (posX + (width / 2))) && ((ball.posY - ball.r) <= (posY + (height / 2))) && ((ball.posY + ball.r) >= (posY - (height / 2))))
	{
		ball.moveX = ball.moveSize;
		isBroken = true;
	}

	//ボールが左側から触れたら反射
	if ((ball.posX < posX) && ((ball.posX + ball.r * 2) >= (posX - (width / 2))) && ((ball.posY - ball.r) <= (posY + (height / 2))) && ((ball.posY + ball.r) >= (posY - (height / 2))))
	{
		ball.moveX = -ball.moveSize;
		isBroken = true;
	}

	//ボールが下側から触れたら反射
	if ((ball.posY < posY) && ((ball.posY + ball.r * 2) >= (posY - (height / 2))) && ((ball.posX - ball.r) <= (posX + (width / 2))) && ((ball.posX + ball.r) >= (posX - (width / 2))))
	{
		ball.moveY = -ball.moveSize;
		isBroken = true;
	}

	//ボールが上から触れたら反射
	if ((ball.posY > posY) && ((ball.posY - ball.r * 2) <= (posY + (height / 2))) && ((ball.posX - ball.r) <= (posX + (width / 2))) && ((ball.posX + ball.r) >= (posX - (width / 2))))
	{
		ball.moveY = ball.moveSize;
		isBroken = true;
	}

	if (isBroken)
	{
		scoreMgr.s_score++;
		srand((unsigned int)time(NULL));
		int num = rand() % 3;
		if (num == 0)
			return;
		objectMgr.CreateItem(posX,posY);
	}
}