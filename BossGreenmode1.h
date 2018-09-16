#pragma once
#include "Enemy.h"

class BossGreenmode1 : public Enemy
{
private:
	enum SKILL_PATTERN
	{
		NORMAL_ONE = 0,
		NORMAL_TWO,
		NORMAL_THREE
	};

	SKILL_PATTERN kind;
	Texture *texture2[2];
	int eframe;
	int storage;
	float angle;
	bool patternact;
	bool apoint;
	bool angleactive;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void ChangeKind();
	void PatternSet();

	BossGreenmode1();
	virtual ~BossGreenmode1();
};

