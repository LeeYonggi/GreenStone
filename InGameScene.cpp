#include "stdafx.h"
#include "Effect.h"

void InGameScene::Init()
{
	srand((unsigned int)time(NULL));
	imap = new Map;
	airplane = new Airplane;
	bullet = new Bullet;
	score = new Score;
	hp = new HP;
	STAGEMANAGER->Initialize();
	SOUNDMANAGER->play("Electroman", 0.1);
	EFFECTMANAGER->Init();
	bullet->VectorInit();
	imap->Init();
	airplane->Init();
	score->Init();
	hp->Init();
}

void InGameScene::Update()
{
	imap->Update();
	airplane->Update();
	bullet->InputEnemy(STAGEMANAGER->GetEnemy());
	bullet->VectorUpdate(airplane);
	STAGEMANAGER->MakeEnemy(bullet, score, airplane);
	score->Update();
	hp->Inputhp(airplane->Gethp());
	hp->Inputboom(airplane->Getboom());
	hp->Update();
	EFFECTMANAGER->LaserUpdate();
}

void InGameScene::Render()
{
	imap->Render();
	airplane->Render();
	STAGEMANAGER->Render();
	bullet->VectorRender();
	EFFECTMANAGER->Render(LASERRED);
	score->DrawPoint();
	hp->Render();
}

void InGameScene::Release()
{
	hp->Release();
	delete hp;
	score->Release();
	delete score;
	airplane->Release();
	bullet->VectorRelease();
	STAGEMANAGER->Release();
	OBJECTMANAGER->Release();
	delete airplane;
	delete bullet;
	imap->Release();
	delete imap;
}

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}
