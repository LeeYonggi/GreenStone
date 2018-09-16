#include "stdafx.h"
#include "Enemy.h"

#include "Bullet.h"

void Enemy::Init()
{
}

void Enemy::Update()
{
}

void Enemy::Render()
{
}

void Enemy::Release()
{
}

void Enemy::AllInit()
{
	frame = 0;
	edelay = 0;
	effectCheck = true;
	scorepoint = true;
	deathcheck = false;
	active = true;
	b_active = true;
	activeinit = false;
}

void Enemy::GetPlayerinfo(Airplane *cap)
{
	character = cap;
}

void Enemy::Gethurt(Bullet *cap, Score *mscore)
{
	RECT lpcDst;
	vbullet = cap->Re_vector();
	circle.center = pos;
	if (active)
	{
		for (int i = 0; i < vbullet.size(); i++)
		{
			if (IntersectCircle(vbullet[i]))
			{
				if (vbullet[i]->Getboom())
					character->Inputskill(diskind);
				hp -= vbullet[i]->Re_damage();
				vbullet[i]->C_Pos();
				EFFECTMANAGER->EffectUpdate(vbullet[i]->GetPos(), LASERRED);
				vbullet[i]->TurnActive();
			}
		}
		if (hp < 1 || pos.y > 800 || pos.x > 850 || pos.x < -100)
		{
			active = false;
			deathcheck = true;
			if (scorepoint)
			{
				mscore->GetPoint(score);
				scorepoint = false;
			}
		}
	}
	if (!active && effectCheck)
	{
		switch (edelay)
		{
		case 0:
			SOUNDMANAGER->play("8bit_bomb_explosion", 255);
			texture = OBJECTMANAGER->FindTexture("Fire1");
			break;
		case 2:
			texture = OBJECTMANAGER->FindTexture("Fire2");
			break;
		case 4:
			texture = OBJECTMANAGER->FindTexture("Fire3");
			break;
		case 6:
			texture = OBJECTMANAGER->FindTexture("Fire4");
			break;
		case 8:
			texture = OBJECTMANAGER->FindTexture("Fire5");
			break;
		case 10:
			texture = OBJECTMANAGER->FindTexture("Fire6");
			break;
		case 12:
			texture = OBJECTMANAGER->FindTexture("Fire7");
			break;
		case 13:
			effectCheck = false;
			break;
		}
		edelay++;
	}
}


Enemy::Enemy()
{
	frame = 0;
	deathcheck = false;
	effectCheck = false;
}

Enemy::~Enemy()
{
}
