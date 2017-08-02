#include "Item.h"


Item::Item()
{
	posX = posY = 0;
	width = height = 10;
	deltaX = 0;
	deltaY = 5;

}

Item::Item(float x, float y)
{
	posX = x;
	posY = y;
	
	width = height = 15;
	deltaX = 0;
	deltaY =  5;
}


Item::~Item()
{
}

void Item::draw()
{
	if (isDeleted)
	{
		return;
	}

//	glColor4f(1,0,0,0.01f);
//	glRectf(posX - width/2 , posY - height/2 , posX + width /2,posY + height/2);
	texture.draw(posX,posY);
}
void Item::move()
{

	if (isDeleted)
		return;

	posX += deltaX;
	posY += deltaY;
	if (posY < -1)
	{
		isDeleted = true;
	}
}

void Item::collisionWithBar(Bar& bar,ScoreManager& scoreMgr,ObjectManager& objectMgr)
{
	if (isDeleted)
		return;

	if (bar.posX + bar.width / 2 > posX - width / 2 &&
		bar.posX - bar.width / 2 < posX + width / 2 &&
		bar.posY + bar.height / 2 > posY - height / 2 &&
		bar.posY - bar.height / 2 < posY + height / 2)
	{
		scoreMgr.s_score++;
		isDeleted = true;

		if (rand() % 2 == 0)
			objectMgr.CreateBall(posX, posY,scoreMgr);
		else
			objectMgr.scaleChangeBarRand();
	}
}

void Item::loadImage()
{
	texture.load("Images/item.png");
	texture.scale.x = width;
	texture.scale.y = height;
	texture.vec.x = posX;
	texture.vec.y = posY;
}


