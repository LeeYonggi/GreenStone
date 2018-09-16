#include "stdafx.h"
#include "Item.h"


void Item::Init()
{
	pos = epos;
	active = true;
	activeinit = false;
	move.x = rand() % 5 + 5;
	move.y = rand() % 5 + 5;
	int num = rand() % 2;
	if (num == 1)
		move = -move;
	circle.radius = 10;
	int num2 = rand() % 4;
	if (num2 != 0)
		active = false;
	int num3 = rand() % 10;
	if (num3 < 3)
	{
		texture = OBJECTMANAGER->FindTexture("powerupBlue_bolt");
		kind = POWER_UP;
	}
	if (num3 >= 3 && num3 < 6)
	{
		texture = OBJECTMANAGER->FindTexture("pill_red");
		kind = HP_UP;
	}
	if(num3 >= 6)
	{
		texture = OBJECTMANAGER->FindTexture("powerupGreen_shield");
		kind = SHIELD;
	}
}

void Item::Update()
{
	if (active)
	{
		circle.center = pos;
		if (pos.x < 10)
			move.x = -move.x;
		if(pos.x > 690)
			move.x = -move.x;
		if (pos.y < -30)
			move.y = -move.y;
		if (pos.y > 690)
			move.y = -move.y;
		pos += move;
		if (IntersectCircle(character))
		{
			switch (kind)
			{
			case POWER_UP:
				character->Inputboom(1);
				break;
			case HP_UP:
				character->InputDamage(-1);
				break;
			case SHIELD:
				character->Inputshield(true);
				break;
			}
			active = false;
		}
	}
}

void Item::Render()
{
	if(active)
		IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
}

void Item::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

Item::Item()
{
	active = false;
}


Item::~Item()
{
}
