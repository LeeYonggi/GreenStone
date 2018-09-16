#include "stdafx.h"
#include "MainTitle.h"


void MainTitle::Init()
{
	texture[0] = IMAGEMANAGER->AddImage("./NewResourse/UI/Background.png");
	texture[1] = IMAGEMANAGER->AddImage("./NewResourse/UI/GreenStone.png");
	texture[2] = IMAGEMANAGER->AddImage("./NewResourse/UI/GameStart.png");
	texture[3] = IMAGEMANAGER->AddImage("./NewResourse/UI/Quit.png");

	pos[0].x = 350;
	pos[0].y = 350;
	pos[1].x = 350;
	pos[1].y = 400;
	pos[2].x = 350;
	pos[2].y = 400;
	pos[3].x = 350;
	pos[3].y = 480;
	mactive = false;
	qactive = false;
	sceneactive = false;
}

void MainTitle::Update()
{
	GetCursorPos(&mouse);
	ScreenToClient(hWnd, &mouse);
	float width = (float)texture[2]->info.Width;
	float height = (float)texture[2]->info.Height;
	float x = pos[2].x - (texture[2]->info.Width / 2);
	float y = pos[2].y - (texture[2]->info.Height / 2);
	RECT image = { x, y, x + width, y + height };
	if (mouse.x < image.right && mouse.x > image.left && mouse.y < image.bottom && mouse.y > image.top)
	{
		mactive = true;
		if (GetAsyncKeyState(VK_LBUTTON))
			sceneactive = true;
	}
	else
		mactive = false;
	float w = (float)texture[3]->info.Width;
	float h = (float)texture[3]->info.Height;
	float r = pos[3].x - (texture[3]->info.Width / 2);
	float l = pos[3].y - (texture[3]->info.Height / 2);
	RECT images = { r, l, r + w, l + h };
	if (mouse.x < images.right && mouse.x > images.left && mouse.y < images.bottom && mouse.y > images.top)
	{
		qactive = true;
		if(GetAsyncKeyState(VK_LBUTTON))
			exit(0);
	}
	else
		qactive = false;
	if(sceneactive)
		SCENEMANAGER->ChangerScene("InGame");
}

void MainTitle::Render()
{
	IMAGEMANAGER->DrawImage(texture[0], pos[0].x, pos[0].y);
	IMAGEMANAGER->DrawImage(texture[1], pos[1].x, pos[1].y);
	if(mactive)
		IMAGEMANAGER->DrawImage(texture[2], pos[2].x, pos[2].y, 0, 100);
	else
		IMAGEMANAGER->DrawImage(texture[2], pos[2].x, pos[2].y);
	if(qactive)
		IMAGEMANAGER->DrawImage(texture[3], pos[3].x, pos[3].y, 0, 100);
	else
		IMAGEMANAGER->DrawImage(texture[3], pos[3].x, pos[3].y);
}

void MainTitle::Release()
{
	for (int i = 0; i < 4; i++)
	{
		texture[i]->lpd3dTex->Release();
		SAFE_DELETE(texture[i]);
	}
}

MainTitle::MainTitle()
{
}


MainTitle::~MainTitle()
{
}
