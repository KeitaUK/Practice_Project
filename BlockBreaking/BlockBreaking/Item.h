#pragma once
#ifndef INCLUDED_Item_h
#define INCLUDED_Item_h

#include "Bar.h"
#include <time.h>
#include "ScoreManager.h"
#include <gl/freeglut.h>
#include "ObjectManager.h"

class ObjectManager;

class Item
{
public:
	Item();
	Item(float posX,float posY);
	~Item();
	void draw();
	void move();
	void collisionWithBar(Bar& bar, ScoreManager& scoreMgr, ObjectManager& objectMgr);
	float posX,posY;
	float deltaX, deltaY;
	float width, height;
	bool isDeleted = false;
};

#endif // !INCLUDED_ITEM_H
