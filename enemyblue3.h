#pragma once
#include "Enemy.h"

class Enemybullet;
class Enemyblue3 : public Enemy
{
private:
	float angle;

public:
	void Init();
	void Update();
	void Render();
	void Release();


	Enemyblue3();
	virtual ~Enemyblue3();
};