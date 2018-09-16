#pragma once
class EnemyGreen1 : public Enemy
{
private:
	enum ENEMY_ANIME
	{
		FLY = 0,
		READY,
		ATTACK
	};

	ENEMY_ANIME e_anime;
	Texture *texture2;
	Texture *texture3;
	int p_change;

public:
	void Init();
	void Update();
	void Release();
	void Render();

	EnemyGreen1();
	virtual ~EnemyGreen1();
};

