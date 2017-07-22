#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
}


ScoreManager::~ScoreManager()
{
}


void ScoreManager::decreaseBallNum()
{
	ballNum--;
	if (ballNum == 0)
		isGameOver = true;
}