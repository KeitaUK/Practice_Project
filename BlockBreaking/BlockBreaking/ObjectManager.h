#pragma once

#ifndef INCLUDED_ObjectManager_h
#define INCLUDED_ObjectManager_h

#include "Ball.h"
#include "Bar.h"
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
	Bar bar;

	void CreateItem(float posX,float poxY);
	void CreateBall(float posX,float posY, ScoreManager& scoreMgr);
	void CreateBall(int scale,float posX, float posY, ScoreManager& scoreMgr);

	void drawBalls();
	void moveBalls(ScoreManager& scoreMgr);
	void drawBars();
	void scaleChangeBar(float deltaX);
	void scaleChangeBarRand();
	void initialize();
};

#endif // !INCLUDED_ObjectManager_h
