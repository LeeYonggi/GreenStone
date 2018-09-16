#include "stdafx.h"
#include "Enemybullet.h"
#define COLLISION 3


void Enemybullet::Initenemyblue3(D3DXVECTOR2 e_pos)
{
	texture = OBJECTMANAGER->FindTexture("laserBlue08");
	kind = ENEMYBLUE3;
	pos = e_pos;
	active = true;
	a_active = true;
	alpha = 255;
	v_alpha = -20;
	circle.radius = 20;
}

void Enemybullet::InitenemyGreen1(D3DXVECTOR2 e_pos)
{
	texture = OBJECTMANAGER->FindTexture("laserGreen02");
	kind = ENEMYGREEN1;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
}

void Enemybullet::InitenemyGreen1_L(D3DXVECTOR2 e_pos)
{
	texture = OBJECTMANAGER->FindTexture("laserGreen02");
	kind = ENEMYGREEN1_L;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
}

void Enemybullet::InitenemyGreen1_R(D3DXVECTOR2 e_pos)
{
	texture = OBJECTMANAGER->FindTexture("laserGreen02");
	kind = ENEMYGREEN1_R;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
}

void Enemybullet::InitenemyGreenmode1(D3DXVECTOR2 e_pos)
{
	texture = OBJECTMANAGER->FindTexture("laserRed02");
	kind = ENEMYGREENMODE1;
	pos.x = e_pos.x - 34;
	pos.y = e_pos.y + 65;
	active = true;
	circle.radius = COLLISION;
	frame = 90;
	skind = TWO;
}

void Enemybullet::InitenemyGreenmode1_R(D3DXVECTOR2 e_pos)
{
	texture = OBJECTMANAGER->FindTexture("laserRed02");
	kind = ENEMYGREENMODE1;
	pos.x = e_pos.x + 34;
	pos.y = e_pos.y + 65;
	active = true;
	circle.radius = COLLISION;
	frame = 90;
	skind = FOUR;
}

void Enemybullet::InitenemyRed4(D3DXVECTOR2 e_pos, float angle)
{
	texture = OBJECTMANAGER->FindTexture("laserGreen04");
	kind = ENEMYRED4;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
	this->angle = angle;
	exactive = true;
}

void Enemybullet::InitBossGreenmode1(D3DXVECTOR2 e_pos, float angle)
{
	texture = OBJECTMANAGER->FindTexture("laserBlue02");
	kind = BOSSGREENMODE1;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
	this->angle = angle;
	exactive = true;
	a_active = true;
	frame = 0;
}

void Enemybullet::InitBossGreenmode1second(D3DXVECTOR2 e_pos, float angle)
{
	texture = OBJECTMANAGER->FindTexture("laserBlue05");
	kind = BOSSGREENMODE1_SECOND;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
	this->angle = angle;
	a_active = true;
	frame = 0;
}

void Enemybullet::InitBossGreenmode1third(D3DXVECTOR2 e_pos, float angle)
{
	texture = OBJECTMANAGER->FindTexture("laserGreen04");
	kind = BOSSGREENMODE1_THIRD;
	pos = e_pos;
	active = true;
	circle.radius = COLLISION;
	this->angle = angle;
	frame = 0;
}

void Enemybullet::Update(Airplane *c_pos)
{
	if (active)
	{
		circle.center = pos;
		switch (kind)
		{
		case ENEMYBLUE3:
			if (a_active)
			{
				temp = CalculateDirection(c_pos);
				a_active = false;
			}
			pos += temp;
			alpha += v_alpha;
			if (alpha < 0)
			{
				alpha = 0;
				v_alpha = -v_alpha;
			}
			if (alpha > 255)
			{
				alpha = 255;
				v_alpha = -v_alpha;
			}
			break;
		case ENEMYGREEN1:
			pos.y += 25;
			break;
		case ENEMYGREEN1_L:
			pos.x -= 10;
			pos.y += 25;
			break;
		case ENEMYGREEN1_R:
			pos.x += 10;
			pos.y += 25;
			break;
		case ENEMYGREENMODE1:
			if (skind == ONE)
			{
				frame += 5;
				pos.x -= sinx[frame] * 15;
				if (frame >= 85)
					skind = FOUR;
			}
			if(skind == TWO)
			{
				frame -= 5;
				pos.x += sinx[frame] * 15;
				if (frame <= 0)
					skind = ONE;
			}
			if (skind == THREE)
			{
				frame += 5;
				pos.x += sinx[frame] * 15;
				if (frame >= 85)
					skind = TWO;
			}
			if(skind == FOUR)
			{
				frame -= 5;
				pos.x -= sinx[frame] * 15;
				if (frame <= 0)
					skind = THREE;
			}

			pos.y += 15;

			break;
		case ENEMYRED4:
			if (exactive)
			{ 
				pos.y += sin(D3DXToRadian(angle)) * 10;
				pos.x += cos(D3DXToRadian(angle)) * 10;
			}
			else
				pos.y += 40;
			break;
		case BOSSGREENMODE1:
			if (exactive)
			{
				pos.y += sin(D3DXToRadian(angle)) * 10;
				pos.x += cos(D3DXToRadian(angle)) * 10;
			}
			else
			{
				if (a_active)
				{
					temp = CalculateDirection(c_pos);
					a_active = false;
				}
				pos += temp * 1.2;
			}
			if (frame > 13)
				exactive = false;
			else
				exactive = true;
			frame++;
			break;
		case BOSSGREENMODE1_SECOND:
			pos.y += sin(D3DXToRadian(angle)) * 5;
			pos.x += cos(D3DXToRadian(angle)) * 5;
			angle += 0.5;
			break;
		case BOSSGREENMODE1_THIRD:
			pos.y += sin(D3DXToRadian(angle)) * 10;
			pos.x += cos(D3DXToRadian(angle)) * 10;
			break;
		}
		if (IntersectCircle(c_pos)
			|| pos.x < -100 || pos.x > 800 || pos.y < -100 || pos.y > 800)
		{
			if(!c_pos->Gethit())
				active = false;
			if (IntersectCircle(c_pos))
			{
				if (c_pos->Getshield())
					c_pos->Inputshield(false);
				else if (!c_pos->Gethit())
				{
					if(c_pos->Gethp() != 0)
						c_pos->InputDamage(1);
					c_pos->Inputhit(true);
				}
			}
		}
	}
}

void Enemybullet::Init()
{
}

void Enemybullet::Update()
{
}

void Enemybullet::Render()
{
	if (active)
	{
		switch (kind)
		{
		case ENEMYRED4:
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y, angle - 90, alpha);
			break;
		case BOSSGREENMODE1:
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y, angle - 90, alpha);
			break;
		case BOSSGREENMODE1_SECOND:
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y, angle - 90, alpha);
			break;
		case BOSSGREENMODE1_THIRD:
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y, angle - 90, alpha);
			break;
		default:
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y, angle, alpha);
			break;
		}
	}
}

void Enemybullet::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

void Enemybullet::Deathtrue(Airplane * c_pos)
{
	if (active)
	{
		circle.center = pos;
		switch (kind)
		{
		case BOSSGREENMODE1:
			alpha = 50;
			break;
		case BOSSGREENMODE1_SECOND:
			alpha = 100;
			break;
		}
		pos += temp;
		temp = CalculateDirection(c_pos);
		if (IntersectCircle(c_pos)
			|| pos.x < -100 || pos.x > 800 || pos.y < -100 || pos.y > 800)
		{
			active = false;
		}
	}
}

Enemybullet::Enemybullet()
{
	active = false;
	a_active = false;
	angle = 0;
	alpha = 255;
}


Enemybullet::~Enemybullet()
{
}
