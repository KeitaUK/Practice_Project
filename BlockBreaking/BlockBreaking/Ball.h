#pragma once
#ifndef INCLUDED_BALL
#define INCLUDED_BALL

#include "Color.h"
#include "Constants.h"
#include "ScoreManager.h"
#include "Texture.h"

class Ball
{
public:
	float r;	//îºåaÅH
	Color color;
	float posX,posY;
	float moveX,moveY;
	float moveSize = 10;
	bool isDeleted = false;
	Texture texture;
	Ball();
	Ball(float radius, float x, float y, Color& col);
	~Ball();
	void loadImage();
	void draw();
	void draw(float posX, float posY);
	void draw(float posX, float posY, float red, float gleen, float blue);
	void moveBall(ScoreManager& scoreMgr);
};

#endif