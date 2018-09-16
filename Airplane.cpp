#include "stdafx.h"
#include "Airplane.h"
#include "Effect.h"


void Airplane::Init()
{
	texture = OBJECTMANAGER->FindTexture("playerShip2_orange");
	texture2 = OBJECTMANAGER->FindTexture("shield3");
	pos.x = 350;
	pos.y = 600;
	size.x = 112;
	size.y = 75;
	circle.radius = 15;
	ekind = FIRENINE;
	skillkind = NO;
	hp = 3;
	sframe = 0;
	shieldcheck = false;
	hit = false;
	hframe = 0;
	boomhp = 3;
}

void Airplane::Update()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		pos.y -= 15;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		pos.y += 15;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		pos.x -= 15;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		pos.x += 15;

	
	if (pos.x < size.x / 2)
		pos.x = size.x / 2;
	if (pos.x > 700 - size.x / 2)
		pos.x = 700 - size.x / 2;
	if (pos.y < size.y / 2)
		pos.y = size.y / 2;
	if (pos.y > 700 - size.y / 2)
		pos.y = 700 - size.y / 2;

	if (shieldcheck)
	{
		sframe++;
		if (sframe > 300)
			shieldcheck = false;
	}
	else
		sframe = 0;

	if (hit)
	{
		hframe++;
		if (hframe > 20)
			hit = false;
	}
	else
		hframe = 0;

	EFFECTMANAGER->EffectUpdate(pos, ekind);
}

void Airplane::Render()
{
	EFFECTMANAGER->Render(ekind);
	if(!hit)
		IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
	if(shieldcheck)
		IMAGEMANAGER->DrawImage(texture2, pos.x, pos.y);
	if (hit)
	{
		if(hframe % 20 == 0)
			IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
		else if(hframe % 20 == 10)
			IMAGEMANAGER->DrawRGBImage(texture, pos.x, pos.y);
	}
}

void Airplane::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

Airplane::Airplane()
{
}


Airplane::~Airplane()
{
}