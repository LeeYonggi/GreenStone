#include "stdafx.h"


void Enemyblue3::Init()
{
	if (activeinit)
	{
		texture = OBJECTMANAGER->FindTexture("enemyBlue3");
		pos.x = (rand() % 550);
		pos.y = -150;
		size.x = 100;
		size.y = 80;
		hp = 400;
		score = 100;
		circle.radius = 40;
		diskind = ENEMYBLUE3;
		AllInit();
	}
}

void Enemyblue3::Update()
{
	if (active)
	{
		if (pos.y > 180)
			pos.y += 1;
		else
		{
			pos.y += 8;
			pos.x += 3;
		}
		if (frame % 20 == 0)
		{
			bullet[bulletdelay]->Initenemyblue3(pos);
			bulletdelay++;
			if (bulletdelay > 14)
				bulletdelay = 0;
		}
		//angle = CalculateRadian(character);
		frame++;
		if (frame > 20000)
			frame = 0;
	}
	if (b_active)
	{
		for (int i = 0; i < 15; i++)
		{
			bullet[i]->Update(character);
		}
	}
}

void Enemyblue3::Render()
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

void Enemyblue3::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Release();
		delete bullet[i];
	}
}


Enemyblue3::Enemyblue3()
{
	bulletdelay = 0;
	activeinit = false;
	active = false;
	b_active = false;
	scorepoint = false;
	for (int i = 0; i < 15; i++)
	{
		bullet.push_back(new Enemybullet);
	}
}

Enemyblue3::~Enemyblue3()
{
}
