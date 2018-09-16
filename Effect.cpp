#include "stdafx.h"
#include "Effect.h"


void Effect::InitFireNine()
{
	kind = FIRENINE;
	for (int i = 0; i < 2; i++)
	{
		texture.push_back(new Texture);
	}
	texture[0] = OBJECTMANAGER->FindTexture("fire04");
	texture[1] = OBJECTMANAGER->FindTexture("fire05");
	ctexture = texture[0];
	frame = 0;
	alpha = 255;
	active = true;
}

void Effect::InitLaserred()
{
	kind = LASERRED;
	for (int i = 0; i < 4; i++)
	{
		texture.push_back(new Texture);
	}
	texture[0] = OBJECTMANAGER->FindTexture("laserRed08");
	texture[1] = OBJECTMANAGER->FindTexture("laserRed09");
	ctexture = texture[0];
	frame = 0;
	alpha = 255;
	active = false;
}

void Effect::Update(D3DXVECTOR2 cpos)
{
	switch (kind)
	{
	case FIRENINE:
		pos.x = cpos.x;
		pos.y = cpos.y + 45;
		if (frame < 2)
			ctexture = texture[0];
		if (frame >= 2 && frame < 4)
			ctexture = texture[1];
		if (frame >= 4)
			frame = 0;
		frame++;
		break;
	case LASERRED:
		if (active)
		{
			switch (frame)
			{
			case 0:
			case 10:
				ctexture = texture[0];
				break;
			case 11:
				active = false;
				frame = 0;
				break;
			}
			frame++;
		}
		break;
	}
}

void Effect::Render()
{
	if(active)
		IMAGEMANAGER->DrawImage(ctexture, pos.x, pos.y, 0, alpha);
}

void Effect::Release()
{
	for (int i = 0; i < texture.size(); i++)
	{
		texture[i]->lpd3dTex->Release();
		SAFE_DELETE(texture[i]);
	}
}

Effect::Effect()
{
}


Effect::~Effect()
{
}
