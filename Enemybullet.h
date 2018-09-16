#pragma once
#include "Object.h"

class Enemybullet : public Object
{
private:
	enum ENEMY_KIND
	{
		ENEMYBLUE3 = 0,
		ENEMYGREEN1,
		ENEMYGREEN1_L,
		ENEMYGREEN1_R,
		ENEMYGREENMODE1,
		ENEMYRED4,
		BOSSGREENMODE1,
		BOSSGREENMODE1_SECOND,
		BOSSGREENMODE1_THIRD
	};
	enum ENEMY_SIN
	{
		ONE = 0,
		TWO,
		THREE,
		FOUR
	};

	ENEMY_KIND kind;
	ENEMY_SIN skind;
	D3DXVECTOR2 temp;
	D3DXVECTOR2 e_temp;
	double sinx[90] =
	{
		0.0175, 0.0349, 0.0523, 0.0698, 0.0872,
		0.1045, 0.1219, 0.1392, 0.1564, 0.1736, 0.1908,
		0.2079, 0.2250, 0.2419, 0.2588, 0.2756, 0.2924,
		0.3090, 0.3256, 0.3420, 0.3584, 0.3746, 0.3907,
		0.4067, 0.4226, 0.4384, 0.4540, 0.4695, 0.4848,
		0.5000, 0.5150, 0.5299, 0.5446, 0.5592, 0.5736, 0.5878,
		0.6018, 0.6157,	0.6293,	0.6428,	0.6561,	0.6691,	0.6820,	0.6947,
		0.7071,	0.7193,	0.7314,	0.7431,	0.7547,	0.7660,	0.7771,	0.7880,	0.7986,
		0.8090,	0.8192,	0.8290,	0.8387,	0.8480,	0.8572,	0.8660,	0.8746,	0.8829,	0.8910,	0.8988,
		0.9063,	0.9135,	0.9205,	0.9272,	0.9336,	0.9397,	0.9455,	0.9511,	0.9563,	0.9613,	0.9659,
		0.9703,	0.9744, 0.9781,	0.9816, 0.9848, 0.9877, 0.9903, 0.9925, 0.9945, 0.9962, 0.9976,
		0.9986, 0.9994, 0.9998, 1.0000
	};

	float angle;
	int alpha;
	int v_alpha;
	int frame;
	bool a_active;
	bool exactive;

public:
	void Initenemyblue3(D3DXVECTOR2 e_pos);
	void InitenemyGreen1(D3DXVECTOR2 e_pos);
	void InitenemyGreen1_L(D3DXVECTOR2 e_pos);
	void InitenemyGreen1_R(D3DXVECTOR2 e_pos);
	void InitenemyGreenmode1(D3DXVECTOR2 e_pos);
	void InitenemyGreenmode1_R(D3DXVECTOR2 e_pos);
	void InitenemyRed4(D3DXVECTOR2 e_pos, float angle);
	void InitBossGreenmode1(D3DXVECTOR2 e_pos, float angle);
	void InitBossGreenmode1second(D3DXVECTOR2 e_pos, float angle);
	void InitBossGreenmode1third(D3DXVECTOR2 e_pos, float angle);
	void Update(Airplane *c_pos);
	void Init();
	void Update();
	void Render();
	void Release();
	void GetEnemypos(D3DXVECTOR2 e_pos) { e_temp = e_pos; }
	void changemode() { exactive = false; }
	void Deathtrue(Airplane *c_pos);


	Enemybullet();
	virtual ~Enemybullet();
};

