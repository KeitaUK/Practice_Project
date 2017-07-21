#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
	CreateBall(400, 400);

}


ObjectManager::~ObjectManager()
{
	delete[] this;
}


void ObjectManager::CreateItem(float posX,float posY)
{
	Item newItem(posX,posY);
	items.insert(items.end(),newItem);
}

void ObjectManager::CreateBall(float posX, float posY) 
{
	//Ball ball(10,400 ,400 ,0.945f, 0.537f, 0);
	Ball newBall(10,posX,posY,0.925f,0.537f,0);
	
	balls.insert(balls.end(),newBall);
}


void ObjectManager::drawBalls()
{
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
	}
}

void ObjectManager::moveBalls()
{
	for (int i = 0; i < sizeof(balls); i++)
	{
		balls[i].moveBall();
	}
}

