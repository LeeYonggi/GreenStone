#pragma once
#include "Number.h"


class Score
{
private:
	Number *number[10];
	int score;
	int vscore;
	int spos;

public:
	void Init();
	void DrawPoint();
	void Update();
	void Release();
	void GetPoint(int num);

	Score();
	virtual ~Score();
};