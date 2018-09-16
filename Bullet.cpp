#include "stdafx.h"
#include "Enemy.h"
#define MAX_BULLET 100

void Bullet::Init()
{	
	
}

void Bullet::NO_Init()
{
	SOUNDMANAGER->play("laser3", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed01");
	active = true;
	pos.x = playerPos.x;
	pos.y = playerPos.y - 10;
	kind = NO_SKILL;
	boom = false;
	damage = 50;
}

void Bullet::ONE_R_Init()
{
	SOUNDMANAGER->play("laser3", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed01");
	active = true;
	pos.x = playerPos.x;
	pos.y = playerPos.y - 10;
	kind = LEVEL_ONE_R;
	boom = false;
	damage = 20;
}

void Bullet::ONE_L_Init()
{
	SOUNDMANAGER->play("laser3", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed01");
	active = true;
	pos.x = playerPos.x;
	pos.y = playerPos.y - 10;
	kind = LEVEL_ONE_L;
	boom = false;
	damage = 20;
}

void Bullet::TWO_Init()
{
	check = false;
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i]->GetActive())
		{
			if (!check)
			{
				echeck = enemy[i]->GetPos();
				check = true;
			}
			else
			{
				float num((playerPos.x - echeck.x) * (playerPos.x - echeck.x) + (playerPos.y - echeck.y) * (playerPos.y - echeck.y));
				D3DXVECTOR2 a = enemy[i]->GetPos();
				float num2((playerPos.x - a.x) * (playerPos.x - a.x) + (playerPos.y - a.y) * (playerPos.y - a.y));
				if (num > num2)
					echeck = a;
			}
		}
	}
	if (check)
	{
		SOUNDMANAGER->play("laser3", 255);
		Object *object = new Airplane;
		object->InputPos(echeck);
		pos = playerPos;
		temp = CalculateDirection(object);
		texture = OBJECTMANAGER->FindTexture("laserRed10");
		active = true;
		pos.x = playerPos.x;
		pos.y = playerPos.y - 10;
		boom = false;
		delete object;
	}
	kind = LEVEL_TWO;
	damage = 90;
}

void Bullet::THREE_R_Init()
{
	SOUNDMANAGER->play("laser3", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed02");
	active = true;
	pos.x = playerPos.x + 20;
	pos.y = playerPos.y - 10;
	kind = LEVEL_THREE_L;
	boom = false;
	bframe = 0;
	damage = 50;
}

void Bullet::THREE_L_Init()
{
	SOUNDMANAGER->play("laser3", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed02");
	active = true;
	pos.x = playerPos.x - 20;
	pos.y = playerPos.y - 10;
	kind = LEVEL_THREE_L;
	boom = false;
	bframe = 180;
	damage = 50;
}

void Bullet::FOUR_Init(float angle)
{
	SOUNDMANAGER->play("laser3", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed03");
	active = true;
	pos.x = playerPos.x;
	pos.y = playerPos.y - 10;
	kind = LEVEL_FOUR;
	boom = false;
	this->angle = angle;
	damage = 40;
}

void Bullet::BoomInit()
{
	SOUNDMANAGER->play("laser5", 255);
	texture = OBJECTMANAGER->FindTexture("laserRed");
	active = true;
	pos.x = playerPos.x;
	pos.y = playerPos.y - 10;
	kind = NO_SKILL;
	boom = true;
	damage = 40;
}

void Bullet::Update()
{
	if (active)
	{
		switch (kind)
		{
		case NO_SKILL:
			pos.y -= 30;
			break;
		case LEVEL_ONE_R:
			pos.y -= 30;
			pos.x += 7;
			break;
		case LEVEL_ONE_L:
			pos.y -= 30;
			pos.x -= 7;
			break;
		case LEVEL_TWO:
			if(check)
				pos += temp;
			break;
		case LEVEL_THREE_L:
			pos.x -= cos(D3DXToRadian(bframe)) * 30;
			bframe += 20;
			pos.y -= 20;
			break;
		case LEVEL_THREE_R:
			pos.x -= cos(D3DXToRadian(bframe)) * 30;
			bframe += 20;
			pos.y -= 20;
			break;
		case LEVEL_FOUR:
			pos.y += sin(D3DXToRadian(angle)) * 10;
			pos.x += cos(D3DXToRadian(angle)) * 10;
			break;
		}
	}
}

void Bullet::Render()
{
	if (active)
	{
		if(kind == LEVEL_FOUR)
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y, angle + 90);
		else
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
	}
}

void Bullet::Release()
{
   	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

void Bullet::VectorInit()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet.push_back(new Bullet());
	}
	skillkind = NO;
}

int Cframe(int frame)
{
	if (frame < MAX_BULLET - 1)
		frame++;
	else
		frame = 0;
	return frame;
}

void Bullet::VectorUpdate(Airplane *airplane)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->SetPlayerPos(airplane->GetPos());
	}
	if (KEYMANAGER->GetKey(VK_SPACE))
	{
		if (bulletdelay == 0)
		{
			if (skillkind == NO)
			{
				bframe = Cframe(bframe);
				bullet[bframe]->NO_Init();
				bulletspeed = 5;
			}
			if (skillkind == FIRST)
			{
				bframe = Cframe(bframe);
				bullet[bframe]->NO_Init();
				bframe = Cframe(bframe);
				bullet[bframe]->ONE_R_Init();
				bframe = Cframe(bframe);
				bullet[bframe]->ONE_L_Init();
				bulletspeed = 5;
			}
			if (skillkind == TWO)
			{
				bframe = Cframe(bframe);
				bullet[bframe]->InputEnemy(enemy);
				bullet[bframe]->TWO_Init();
				bulletspeed = 5;
			}
			if (skillkind == THREE)
			{
				bframe = Cframe(bframe);
				bullet[bframe]->THREE_R_Init();
				bframe = Cframe(bframe);
				bullet[bframe]->THREE_L_Init();
				bulletspeed = 4;
			}
			if (skillkind == FOUR)
			{
				for (int i = 0; i < 24; i++)
				{
					bframe = Cframe(bframe);
					bullet[bframe]->FOUR_Init(i * 15);
				}
				bulletspeed = 20;
			}
			skillkind = airplane->Getskill();
			bulletdelay = bulletspeed;
		}
	}
	if (GetAsyncKeyState(0x41) & 0x8000)
	{
		if (airplane->Getboom() > 0)
		{
			if (boomdelay == 0)
			{
				bframe = Cframe(bframe);
				bullet[bframe]->BoomInit();
				airplane->Inputboom(-1);
			}
			boomdelay = 20;
		}
	}
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Update();
	}
	if (boomdelay > 0)
		boomdelay--;
	if(bulletdelay > 0)
		bulletdelay--;
} 

void Bullet::VectorRender()
{
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Render();
	}
}

void Bullet::VectorRelease()
{
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Release();
		delete bullet[i];
	}
}


void Bullet::TurnActive()
{
	if (!active)
	{
		pos.x = -1000;
		pos.y = -1000;
	}
}


Bullet::Bullet()
{
	initPoint = false;
	active = false;
	bframe = NULL;
	damage = 70;
	bulletdelay = 0;
	bulletpost = 0;
	boomdelay = 0;
	size.x = 9;
	size.y = 50;
	circle.radius = 20;
}

Bullet::~Bullet()
{
}
