#include "stdafx.h"
#include "EffectManager.h"
#include "Effect.h"


void EffectManager::Init()
{
	cTexture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Effects/fire04.png");
	OBJECTMANAGER->Init("fire04", cTexture);
	cTexture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Effects/fire05.png");
	OBJECTMANAGER->Init("fire05", cTexture);
	cTexture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed08.png");
	OBJECTMANAGER->Init("laserRed08", cTexture);
	cTexture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed09.png");
	OBJECTMANAGER->Init("laserRed09", cTexture);
	cTexture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed10.png");
	OBJECTMANAGER->Init("laserRed10", cTexture);
	cTexture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed11.png");
	OBJECTMANAGER->Init("laserRed11", cTexture);
	ex.x = 10;
	ex.y = 10;
	redDelay = 0;
	for (int i = 0; i < 1; i++)
	{
		effect.push_back(new Effect());
	}
	for (int i = 0; i < 1; i++)
	{
		switch (i)
		{
		case 0:
			effect[i]->InitFireNine();
			break;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		leffect.push_back(new Effect());
	}
	for (int i = 0; i < 100; i++)
	{
		leffect[i]->InitLaserred();
	}
}

void EffectManager::EffectUpdate(D3DXVECTOR2 pos, EFFECT_NUM kind)
{
	switch (kind)
	{
	case FIRENINE:
		effect[FIRENINE]->Update(pos);
		break;
	case LASERRED:
		leffect[redDelay]->ActiveOn(pos);
		redDelay++;
		if (redDelay >= 99)
			redDelay = 0;
		break;
	}
}

void EffectManager::LaserUpdate()
{
	for (int i = 0; i < 100; i++)
	{
		leffect[i]->Update(ex);
	}
}

void EffectManager::Render(EFFECT_NUM kind)
{
	switch (kind)
	{
	case FIRENINE:
		effect[FIRENINE]->Render();
		break;
	case LASERRED:
		for (int i = 0; i < 100; i++)
		{
			leffect[i]->Render();
		}
		break;
	}
}

void EffectManager::Release()
{
	for (int i = 0; i < effect.size(); i++)
	{
		effect[i]->Release();
		delete effect[i];
	}
	for (int i = 0; i < leffect.size(); i++)
	{
		leffect[i]->Release();
		delete effect[i];
	}
}


EffectManager::EffectManager()
{
}


EffectManager::~EffectManager()
{
}
