#include "stdafx.h"
#include "EnemyRed4.h"
#define MAX_BULLET 24

//*milkalice*//

void EnemyRed4::Init()
{
	if (activeinit)
	{
		ctexture[0] = OBJECTMANAGER->FindTexture("enemyRed4");
		ctexture[1] = OBJECTMANAGER->FindTexture("enemyRed5");
		pos.x = rand() % 600 + 100;
		pos.y = -100;
		hp = 400;
		score = 200;
		circle.radius = 40;
		angleactive = true;
		texture = ctexture[0];
		diskind = ENEMYRED4;
		AllInit();
	}
}

void EnemyRed4::Update()
{
	if (active)
	{
		if (frame < 30)
		{
			D3DXVECTOR2 temp;
			pos.y += 6;
			temp = character->GetPos();
			pos.x = temp.x;
			texture = ctexture[0];
		}
		else
		{
			if (angleactive)
			{
				for (int i = 0; i < MAX_BULLET; i ++)
				{
					bullet[i]->InitenemyRed4(pos, i * 15);
				}
				angleactive = false;
			}
			pos.y += 40;
			texture = ctexture[1];
		}
		frame++;
	}
	if (b_active)
	{
		for (int i = 0; i < MAX_BULLET; i++)
		{
			bullet[i]->GetEnemypos(pos);
			bullet[i]->Update(character);
		}
	}
}

void EnemyRed4::Render()
{
	if (active || effectCheck)
	{
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

void EnemyRed4::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet[i]->Release();
	}
}

EnemyRed4::EnemyRed4()
{
	activeinit = false;
	active = false;
	b_active = false;
	scorepoint = false;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet.push_back(new Enemybullet);
	}
}


EnemyRed4::~EnemyRed4()
{
}
