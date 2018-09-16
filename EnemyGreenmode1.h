#pragma once

class EnemyGreenmode1 : public Enemy
{
private:
	Texture *l_TextureWing;
	Texture *r_TextureWing;
	float angle;
	bool apoint;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	EnemyGreenmode1();
	virtual ~EnemyGreenmode1();
};
