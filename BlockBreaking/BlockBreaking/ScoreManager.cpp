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
		isGameOver = 1;
}

void ScoreManager::reset()
{
	s_score = 0;
	breakBlockNum = 0;
	ballNum = 0;
	isGameClear = 0;
	isGameOver = 0;

}