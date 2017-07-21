#pragma once

#ifndef INCLUDED_ObjectManager_h
#define INCLUDED_ObjectManager_h

#include "Ball.h"
#include "Item.h"
#include <vector>
using namespace std;

class Item;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	vector<Ball> balls;
	vector<Item> items;
	void CreateItem(float posX,float poxY);
	void CreateBall(float posX,float posY);
	int getArrayNumBall();
	void drawBalls();
	void moveBalls();
};

#endif // !INCLUDED_ObjectManager_h
