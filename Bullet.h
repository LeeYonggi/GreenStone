#pragma once
#include "Object.h"

class Enemy;
class Bullet : public Object
{
private:
	enum ENEMYSKILL
	{
		NO_SKILL,
		LEVEL_ONE_R,
		LEVEL_ONE_L,
		LEVEL_TWO,
		LEVEL_THREE_R,
		LEVEL_THREE_L,
		LEVEL_FOUR
	};

	ENEMYSKILL kind;
	Texture *texture;
	D3DXVECTOR2 playerPos;
	D3DXVECTOR2 echeck;
	D3DXVECTOR2 temp;
	vector<Bullet*> bullet;
	vector<Enemy*> enemy;
	int bulletspeed;
	int bulletdelay;
	int bulletpost;
	int damage;
	int bframe;
	int boomdelay;
	float angle;
	bool check;
	bool a_active;
	bool initPoint;
	bool boom;


public:
	void NO_Init();
	void ONE_R_Init();
	void ONE_L_Init();
	void TWO_Init();
	void THREE_R_Init();
	void THREE_L_Init();
	void FOUR_Init(float angle);
	void BoomInit();

	void Init();
	void Update();
	void Render();
	void Release();
	void VectorInit();
	void VectorUpdate(Airplane *airplane);
	void VectorRender();
	void VectorRelease();

	bool Getboom() { return boom; }
	int Re_damage() { return damage; }
	void Inputvector(vector<Enemy*> enemy) { this->enemy = enemy; }
	void SetPlayerPos(D3DXVECTOR2 cpos) { playerPos = cpos; }
	void Inittrue() { initPoint = true; }
	void TurnActive();
	void C_Pos() { active = false; }
	void InputEnemy(vector<Enemy*> enemy) { this->enemy = enemy; }
	vector<Bullet*> Re_vector() { return bullet; }

	Bullet();
	virtual ~Bullet();
};