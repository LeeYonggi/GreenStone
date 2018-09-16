#pragma once
#include "Object.h"
#include "Score.h"

class Bullet;
class Enemybullet;
class Enemy : public Object
{
protected:
	enum distintion
	{
		ENEMYGREEN1 = 1,
		ENEMYBLUE3 = 2,
		ENEMYGREENMODE1 = 3,
		ENEMYRED4 = 4
	};
	int diskind;
	vector<Enemybullet*> bullet;
	vector<Bullet*> vbullet;
	Airplane *character;
	int hp;
	int score;
	int frame;
	int edelay;
	int bulletdelay;
	
	bool deathcheck;
	bool activeinit;
	bool scorepoint;
	bool b_active;
	bool effectCheck;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

	void AllInit();
	void GetPlayerinfo(Airplane *cap);
	void Gethurt(Bullet *cap, Score *mscore);
	void ActiveOn() { activeinit = true; }
	bool GetDeath() { return deathcheck; }

	Enemy();
	virtual ~Enemy();
};