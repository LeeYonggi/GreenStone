#include "stdafx.h"
#include "BossGreenmode1.h"
#define MAX_BULLET 36
#define MAX_BULLET_A 24
#define MAX_PATTERN 3


void BossGreenmode1::Init()
{
	if (activeinit)
	{
		texture = OBJECTMANAGER->FindTexture("EnemyGreenmode2");
		texture2[1] = OBJECTMANAGER->FindTexture("arm");
		texture2[0] = OBJECTMANAGER->FindTexture("arm2");
		apoint = false;
		angleactive = true;
		storage = 4;
		eframe = 0;
		bulletdelay = 200;
		pos.x = 350;
		pos.y = -200;
		circle.radius = 100;
		angle = 0;
		hp = 6000;
		score = 3000;
		patternact = true;
		ChangeKind();
		diskind = character->Getskill();
		AllInit();
	}
}

void BossGreenmode1::Update()
{
	if (active)
	{
		circle.center = pos;
		if (pos.y < 100)
			pos.y += 5;
		else
		{
			if (angle <= -15)
				apoint = true;
			else if (angle > 20)
				apoint = false;
			if (apoint)
				angle++;
			else
				angle--;
			switch (kind)
			{
			case NORMAL_ONE:

				if (frame % 30 == 0)
					angleactive = true;
				if (angleactive)
				{
					for (int i = MAX_BULLET * eframe; i < (eframe * MAX_BULLET) + MAX_BULLET; i++)
					{
						bullet[i]->InitBossGreenmode1(pos, i * 10);
					}
					eframe++;
					if (eframe > 2)
						eframe = 0;
					angleactive = false;
				}
				if (frame > 140)
				{
					ChangeKind();
					frame = 0;
				}
				frame++;
				break;
			case NORMAL_TWO:

				if (frame % 20 == 0)
					angleactive = true;
				PatternSet();
				if (frame > 220)
				{
					ChangeKind();
					frame = 0;
				}
				frame++;
				break;
			case NORMAL_THREE:

				if (frame % 2 == 0)
				{
					bullet[eframe]->InitBossGreenmode1third(pos, eframe * 10);
					bullet[bulletdelay]->InitBossGreenmode1third(pos, eframe * 10 - 180);
					eframe++;
					bulletdelay++;
					if (bulletdelay > 395)
						bulletdelay = 0;
					if (eframe > 395)
						eframe = 0;
				}
				frame++;
				if (frame > 200)
				{
					bulletdelay = 200;
					eframe = 0;
					ChangeKind();
					frame = 0;
				}
				break;
			}
		}
	}
	if (b_active)
	{
		for (int i = 0; i < bullet.size(); i++)
		{
			bullet[i]->GetEnemypos(pos);
			if (!active)
				bullet[i]->Deathtrue(character);
			else
				bullet[i]->Update(character);
		}
	}
}

void BossGreenmode1::Render()
{
	if (active || effectCheck)
	{
		if (active)
		{
			IMAGEMANAGER->DrawImage(texture2[0], pos.x - 95, pos.y + 75, angle);
			IMAGEMANAGER->DrawImage(texture2[1], pos.x + 95, pos.y + 75, -angle);
		}
		IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
	}
	if (b_active)
	{
		for (int i = 0; i < bullet.size(); i++)
		{
			bullet[i]->Render();
		}
	}
}

void BossGreenmode1::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Release();
	}
}

void BossGreenmode1::ChangeKind()
{
	int num;
	while (true)
	{
		num = rand() % MAX_PATTERN;
		if (num != storage)
		{
			break;
		}
	}
	storage = num;
	switch (num)
	{
	case 0:
		kind = NORMAL_ONE;
		break;
	case 1:
		kind = NORMAL_TWO;
		break;
	case 2:
		kind = NORMAL_THREE;
		break;
	}
}

void BossGreenmode1::PatternSet()
{
	int a = 24;
	if (angleactive)
	{
		for (int i = a * eframe; i < (a * eframe) + MAX_BULLET_A; i++)
		{
			if(patternact)
				bullet[i]->InitBossGreenmode1second(pos, i * 15);
			else
				bullet[i]->InitBossGreenmode1second(pos, i * 15 + 7.5);
		}
		eframe++;
		if (eframe > 9)
			eframe = 0;
		patternact = !patternact;
		angleactive = false;
	}
}

BossGreenmode1::BossGreenmode1()
{
	activeinit = false;
	active = false;
	b_active = false;
	scorepoint = false;
	for (int i = 0; i < 400; i++)
	{
		bullet.push_back(new Enemybullet);
	}
}


BossGreenmode1::~BossGreenmode1()
{
}
