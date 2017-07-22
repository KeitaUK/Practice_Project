#pragma once
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();
	int s_score = 0;
	int breakBlockNum = 0;
	int ballNum = 0;
	bool isGameClear = false;
	bool isGameOver = false;
	
	void decreaseBallNum();
};

