#include "stdafx.h"
#include "EnemyGreen1.h"


void EnemyGreen1::Init()
{
	if (activeinit)
	{
		texture = OBJECTMANAGER->FindTexture("enemyGreen1");
		texture2 = OBJECTMANAGER->FindTexture("enemyGreen2");
		texture3 = OBJECTMANAGER->FindTexture("enemyGreen3");
		hp = 400;
		circle.radius = 40;
		pos.y = rand() % 150 + 100;
		p_change = rand() % 2;
		if (p_change == 0)
		{
			pos.x = -100;
		}
		else if (p_change == 1)
		{
			pos.x = 800;
		}
		score = 150;
		e_anime = FLY;
		diskind = ENEMYGREEN1;
		AllInit();
	}
}

void EnemyGreen1::Update()
{
	if (active)
	{
		if (p_change == 0)
		{
			pos.x += 4;
		}
		else if (p_change == 1)
		{
			pos.x -= 4;
		}
		if (frame <= 50)
			texture = texture2;
		else if (frame > 50 && frame < 70)
			texture = texture3;
		else if (frame >= 70 && frame < 150)
		{
			e_anime = ATTACK;
			if (frame % 15 == 0)
			{
				bullet[bulletdelay]->InitenemyGreen1(pos);
				bulletdelay++;
				if (bulletdelay > 14)
					bulletdelay = 0;
				bullet[bulletdelay]->InitenemyGreen1_L(pos);
				bulletdelay++;
				if (bulletdelay > 14)
					bulletdelay = 0;
				bullet[bulletdelay]->InitenemyGreen1_R(pos);
				bulletdelay++;
				if (bulletdelay > 14)
					bulletdelay = 0;
			}
		}
		else if (frame >= 150)
			frame = 0;
		frame++;
	}
	if (b_active)
	{
		for (int i = 0; i < 15; i++)
		{
			bullet[i]->Update(character);
		}
	}
}

void EnemyGreen1::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Release();
		delete bullet[i];
	}
}

void EnemyGreen1::Render()
{
	if (active || effectCheck)
	{
		IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
	}
	if (b_active)
	{
		for (int i = 0; i < 15; i++)
		{
			bullet[i]->Render();
		}
	}
}

EnemyGreen1::EnemyGreen1()
{
	active = false;
	activeinit = false;
	bulletdelay = 0;
	b_active = false;
	scorepoint = false;
	for (int i = 0; i < 15; i++)
	{
		bullet.push_back(new Enemybullet);
	}
}


EnemyGreen1::~EnemyGreen1()
{
}
