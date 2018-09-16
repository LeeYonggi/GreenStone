#pragma once
#include "Object.h"
#include "Airplane.h"
#include "Bullet.h"
#include "Map.h"
#include "enemyblue3.h"
#include "Score.h"
#include "Number.h"

class Effect;
class InGameScene : public BaseScene
{
private:
	Airplane *airplane;
	Bullet *bullet;
	Map *imap;
	Score *score;
	HP *hp;
	
public:
	void Init();
	void Update();
	void Render();
	void Release();

	InGameScene();
	virtual ~InGameScene();
};