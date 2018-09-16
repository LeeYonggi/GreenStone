#include "stdafx.h"
#include "Rock.h"


void Rock::Init()
{
	if (activeinit)
	{
		score = 0;
		pos.x = rand() % 500 + 100;
		pos.y = -100;
		hp = rand() % 300 + 100;
		AllInit();

		color = rand() % 2;
		move.y = rand() % 3 + 1;
		int num = rand() % 4;
		if (color)
		{
			switch (num)
			{
			case 0:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorBrown_big1");
				break;
			case 1:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorBrown_big2");
				break;
			case 2:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorBrown_big3");
				break;
			case 3:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorBrown_big4");
				break;
			}
		}
		else
		{
			switch (num)
			{
			case 0:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorGrey_big1");
				break;
			case 1:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorGrey_big2");
				break;
			case 2:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorGrey_big3");
				break;
			case 3:
				eTexture[0] = OBJECTMANAGER->FindTexture("meteorGrey_big4");
				break;
			}
		}
		num = rand() % 2;
		if (color)
		{
			switch (num)
			{
			case 0:
				eTexture[1] = OBJECTMANAGER->FindTexture("meteorBrown_med1");
				break;
			case 1:
				eTexture[1] = OBJECTMANAGER->FindTexture("meteorBrown_med3");
				break;
			}
		}
		else
		{
			switch (num)
			{
			case 0:
				eTexture[1] = OBJECTMANAGER->FindTexture("meteorGrey_med1");
				break;
			case 1:
				eTexture[1] = OBJECTMANAGER->FindTexture("meteorGrey_med2");
				break;
			}
		}
		num = rand() % 2;
		if (color)
		{
			switch (num)
			{
			case 0:
				eTexture[2] = OBJECTMANAGER->FindTexture("meteorBrown_small1");
				break;
			case 1:
				eTexture[2] = OBJECTMANAGER->FindTexture("meteorBrown_small2");
				break;
			}
		}
		else
		{
			switch (num)
			{
			case 0:
				eTexture[2] = OBJECTMANAGER->FindTexture("meteorGrey_small1");
				break;
			case 1:
				eTexture[2] = OBJECTMANAGER->FindTexture("meteorGrey_small2");
				break;
			}
		}
		num = rand() % 2;
		if (color)
		{
			switch (num)
			{
			case 0:
				eTexture[3] = OBJECTMANAGER->FindTexture("meteorBrown_tiny1");
				break;
			case 1:
				eTexture[3] = OBJECTMANAGER->FindTexture("meteorBrown_tiny2");
				break;
			}
		}
		else
		{
			switch (num)
			{
			case 0:
				eTexture[3] = OBJECTMANAGER->FindTexture("meteorGrey_tiny1");
				break;
			case 1:
				eTexture[3] = OBJECTMANAGER->FindTexture("meteorGrey_tiny1");
				break;
			}
		}
	}
}

void Rock::Update(Bullet *cap, Score *mscore)
{
	if (active)
	{
		if (300 <= hp && active)
		{
			circle.radius = 50;
			texture = eTexture[0];
		}
		if (hp < 300 && 200 <= hp && active)
		{
			circle.radius = 40;
			texture = eTexture[1];
		}
		if (hp < 200 && 100 <= hp && active)
		{
			circle.radius = 30;
			texture = eTexture[2];
		}
		if (hp < 100 && active)
		{
			circle.radius = 20;
			texture = eTexture[3];
		}
		if (IntersectCircle(character))
		{
			if (!character->Gethit())
				active = false;
			if (IntersectCircle(character))
			{
				if (!character->Gethit())
				{
					if (character->Gethp() != 0)
						character->InputDamage(1);
					character->Inputhit(true);
				}
				character->Inputshield(false);
			}
		}
		pos.y += move.y;
	}
	Gethurt(cap, mscore);
}

void Rock::Render()
{
	if (active || effectCheck)
		IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
}

void Rock::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

Rock::Rock()
{
	deathcheck = false;
	effectCheck = false;
	activeinit = false;
	active = false;
	b_active = false;
	scorepoint = false;
	diskind = 0;
}


Rock::~Rock()
{
}
