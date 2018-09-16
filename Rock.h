#pragma once
#include "Enemy.h"

class Rock : public Enemy
{
private:
	enum SIZE
	{
		TINY = 0,
		SMALL,
		MED,
		BIG
	};
	D3DXVECTOR2 move;
	Texture *eTexture[4];
	bool color;
public:
	void Init();
	void Update(Bullet *cap, Score *mscore);
	void Render();
	void Release();

	Rock();
	virtual ~Rock();
};

