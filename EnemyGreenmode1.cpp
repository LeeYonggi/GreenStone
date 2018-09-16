#include "stdafx.h"
#include "EnemyGreenmode1.h"
#define MAX_BULLET 60

void EnemyGreenmode1::Init()
{
	if (activeinit)
	{
		texture = OBJECTMANAGER->FindTexture("EnemyGreenmode1");
		r_TextureWing = OBJECTMANAGER->FindTexture("wingBlue_4");
		l_TextureWing = OBJECTMANAGER->FindTexture("lwingBlue_4");
		apoint = false;
		angle = 0;
		int num = rand() % 2;
		if (num == 0)
			pos.x = 500;
		else
			pos.x = 200;
		pos.y = -200;
		circle.radius = 60;
		hp = 600;
		score = 400;
		diskind = ENEMYGREENMODE1;
		AllInit();
	}
}

void EnemyGreenmode1::Update()
{
	if (active)
	{
		circle.center = pos;
		pos.y += 3;
		if (angle <= -15)
			apoint = true;
		else if (angle > 20)
			apoint = false;
		if (apoint)
			angle++;
		else
			angle--;
		
		if (frame % 3 == 0)
		{
			bullet[bulletdelay]->InitenemyGreenmode1(pos);
			bulletdelay++;
			bullet[bulletdelay]->InitenemyGreenmode1_R(pos);
			bulletdelay++;
			if (bulletdelay >= MAX_BULLET)
				bulletdelay = 0;
		}
		frame++;
		if (frame > 20000)
			frame = 0;
	}
	if (b_active)
	{
		for (int i = 0; i < MAX_BULLET; i++)
		{
			bullet[i]->Update(character);
		}
	}
}

void EnemyGreenmode1::Render()
{
	if (active || effectCheck)
	{
		if (active)
		{
			IMAGEMANAGER->DrawImage(r_TextureWing, pos.x + 65, pos.y + 15, angle);
			IMAGEMANAGER->DrawImage(l_TextureWing, pos.x - 65, pos.y + 15, -angle);
		}
		IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
	}
	if (b_active)
	{
		for (int i = 0; i < MAX_BULLET; i++)
		{
			bullet[i]->Render();
		}
	}
}

void EnemyGreenmode1::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet[i]->Release();
	}
}

EnemyGreenmode1::EnemyGreenmode1()
{
	active = false;
	activeinit = false;
	scorepoint = false;
	bulletdelay = 0;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet.push_back(new Enemybullet);
	}
}


EnemyGreenmode1::~EnemyGreenmode1()
{
}
