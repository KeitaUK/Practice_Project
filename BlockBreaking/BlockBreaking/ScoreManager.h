#pragma once
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();
	int s_score = 0;
	int breakBlockNum = 0;
	int ballNum = 0;
	int isGameClear = 0;
	int isGameOver = 0;
	
	void decreaseBallNum();
	void reset();
};

