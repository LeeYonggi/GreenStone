#include "stdafx.h"
#include "MainTitle.h"


MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}


int MainProc::Init() 
{
	bAct = true;
	SetCursor(NULL);
	ShowCursor(FALSE);
	SCENEMANAGER->AddScene("Title", new MainTitle);
	SCENEMANAGER->AddScene("InGame", new InGameScene);
	SCENEMANAGER->ChangerScene("Title"); 
	mouseCuser = IMAGEMANAGER->AddImage("./NewResourse/UI/crossair_redOutline.png");
	return 0;
}


int MainProc::Update()
{
	GetCursorPos(&mouse);
	ScreenToClient(hWnd, &mouse);
	SCENEMANAGER->Update();
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		exit(0);
	return 0;
}


int MainProc::Render()
{
	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();
	IMAGEMANAGER->DrawImage(mouseCuser, mouse.x, mouse.y);

	IMAGEMANAGER->End();
	return 0;
}


int MainProc::Release()
{
	bAct = false;
	SCENEMANAGER->Release();
	IMAGEMANAGER->ReleaseSingleton();
	SCENEMANAGER->ReleaseSingleton();

	PostQuitMessage(0);
	ImageManager::ReleaseSingleton();
	return 0;
}


// Get

BOOL MainProc::GetAct()
{
	return bAct;
}