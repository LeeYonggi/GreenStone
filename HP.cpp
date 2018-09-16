#include "stdafx.h"
#include "HP.h"


void HP::Init()
{
	for (int i = 0; i < 10; i++)
	{
		number[i] = new Number;
	}
	for (int i = 0; i < 10; i++)
	{
		number[i]->Init(i);
	}
	texture[0] = OBJECTMANAGER->FindTexture("playerLife2_orange");
	texture[1] = OBJECTMANAGER->FindTexture("numeralX"); 
	texture[2] = OBJECTMANAGER->FindTexture("spaceBuilding_008");
	hp = 3;
	boom = 3;
}

void HP::Update()
{

}

void HP::Render()
{
	number[hp % 10]->Render(130, 670);
	hp /= 10;
	number[hp % 10]->Render(105, 670);
	IMAGEMANAGER->DrawImage(texture[0], 55, 670);
	IMAGEMANAGER->DrawImage(texture[1], 80, 670);
	number[boom % 10]->Render(130, 640);
	boom /= 10;
	number[hp % 10]->Render(105, 640);
	IMAGEMANAGER->DrawImage(texture[2], 55, 640);
	IMAGEMANAGER->DrawImage(texture[1], 80, 640);
}

void HP::Release()
{
	for (int i = 0; i < 10; i++)
	{
		number[i]->Release();
		delete number[i];
	}
}

HP::HP()
{
}


HP::~HP()
{
}
