#include "ObjectManager.h"



ObjectManager::ObjectManager()
{

}


ObjectManager::~ObjectManager()
{
}


void ObjectManager::CreateItem(float posX,float posY)
{
	Item newItem(posX,posY);
	items.push_back(newItem);
}

void ObjectManager::CreateBall(float posX, float posY,ScoreManager& scoreMgr) 
{
	//Ball ball(10,400 ,400 ,0.945f, 0.537f, 0);
	
	Color col((double)rand()/RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
	int scale = rand() %10 +4;

	Ball newBall(scale,posX,posY,col);
	balls.push_back(newBall);
	scoreMgr.ballNum++;
}

void ObjectManager::CreateBall(int scale,float posX, float posY, ScoreManager& scoreMgr)
{
	//Ball ball(10,400 ,400 ,0.945f, 0.537f, 0);

	Color col((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);

	Ball newBall(scale, posX, posY, col);
	balls.push_back(newBall);
	scoreMgr.ballNum++;
}


void ObjectManager::drawBalls()
{
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
	}
}

void ObjectManager::moveBalls(ScoreManager& scoreMgr)
{
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].moveBall(scoreMgr);
	}
}

void ObjectManager::drawBars()
{
	bar.draw();
}

void ObjectManager::scaleChangeBar(float deltaX)
{
	bar.width += deltaX;
}

void ObjectManager::scaleChangeBarRand()
{
	int deltaX = rand() % 50 + 30;
	if (rand() % 2 == 0)
	{
		deltaX = -deltaX;
	}
	bar.width += deltaX;
}