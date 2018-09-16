#include "stdafx.h"

void Map::Init()
{
	texture = OBJECTMANAGER->FindTexture("purple_1");
	texture2 = OBJECTMANAGER->FindTexture("purple_1");
	pos.x =	350;
	pos.y = 350;
	pos2.x = 350;
	pos2.y = -350;
}

void Map::Update()
{
	if (pos.y >= 1050)
		pos.y = -700;
	if (pos2.y >= 1050)
		pos2.y = -700;
	pos.y += 15;
	pos2.y += 15;
}

void Map::Render()
{
	IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
	IMAGEMANAGER->DrawImage(texture2, pos2.x, pos2.y);
}

void Map::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
	texture2->lpd3dTex->Release();
	SAFE_DELETE(texture2);
}
