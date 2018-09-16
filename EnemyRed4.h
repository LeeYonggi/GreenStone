#pragma once
#include "Enemy.h"

class EnemyRed4 : public Enemy
{
private:
	Texture *ctexture[2];
	bool angleactive;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	EnemyRed4();
	virtual ~EnemyRed4();
};

