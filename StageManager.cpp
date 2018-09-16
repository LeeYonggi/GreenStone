#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Rock.h"

void StageManager::Initialize()
{
	//Image
	//Character
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/playerShip2_orange.png");
	OBJECTMANAGER->Init("playerShip2_orange", texture);

	//UI & Background
	texture = IMAGEMANAGER->AddImage("./NewResourse/purple_1.png");
	OBJECTMANAGER->Init("purple_1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/UI/playerLife2_orange.png"); 
	OBJECTMANAGER->Init("playerLife2_orange", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/UI/numeralX.png");
	OBJECTMANAGER->Init("numeralX", texture);

	//Enemy
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Enemies/enemyBlue3.png");
	OBJECTMANAGER->Init("enemyBlue3", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Enemies/enemyGreen1.png");
	OBJECTMANAGER->Init("enemyGreen1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Enemies/enemyGreen2.png");
	OBJECTMANAGER->Init("enemyGreen2", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Enemies/enemyGreen3.png");
	OBJECTMANAGER->Init("enemyGreen3", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Enemy/EnemyGreenmode1.png");
	OBJECTMANAGER->Init("EnemyGreenmode1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Enemies/enemyRed4.png");
	OBJECTMANAGER->Init("enemyRed4", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Enemies/enemyRed5.png");
	OBJECTMANAGER->Init("enemyRed5", texture); 
	texture = IMAGEMANAGER->AddImage("./NewResourse/Enemy/EnemyGreenmode2.png");
	OBJECTMANAGER->Init("EnemyGreenmode2", texture);

	//Rock
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_big1.png");
	OBJECTMANAGER->Init("meteorBrown_big1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_big2.png");
	OBJECTMANAGER->Init("meteorBrown_big2", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_big3.png");
	OBJECTMANAGER->Init("meteorBrown_big3", texture); 
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_big1.png");
	OBJECTMANAGER->Init("meteorBrown_big4", texture); 
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png");
	OBJECTMANAGER->Init("meteorBrown_med1", texture); 
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_med3.png");
	OBJECTMANAGER->Init("meteorBrown_med3", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_small1.png");
	OBJECTMANAGER->Init("meteorBrown_small1", texture); 
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_small2.png");
	OBJECTMANAGER->Init("meteorBrown_small2", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny1.png");
	OBJECTMANAGER->Init("meteorBrown_tiny1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny2.png");
	OBJECTMANAGER->Init("meteorBrown_tiny2", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_big1.png");
	OBJECTMANAGER->Init("meteorGrey_big1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_big2.png");
	OBJECTMANAGER->Init("meteorGrey_big2", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_big3.png");
	OBJECTMANAGER->Init("meteorGrey_big3", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_big1.png");
	OBJECTMANAGER->Init("meteorGrey_big4", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_med1.png");
	OBJECTMANAGER->Init("meteorGrey_med1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_med2.png");
	OBJECTMANAGER->Init("meteorGrey_med3", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_small1.png");
	OBJECTMANAGER->Init("meteorGrey_small1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_small2.png");
	OBJECTMANAGER->Init("meteorGrey_small2", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_tiny1.png");
	OBJECTMANAGER->Init("meteorGrey_tiny1", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Meteors/meteorGrey_tiny2.png");
	OBJECTMANAGER->Init("meteorGrey_tiny2", texture);


	//Bullet
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserBlue08.png");
	OBJECTMANAGER->Init("laserBlue08", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed01.png");
	OBJECTMANAGER->Init("laserRed01", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed02.png");
	OBJECTMANAGER->Init("laserRed02", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserGreen02.png");
	OBJECTMANAGER->Init("laserGreen02", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserGreen04.png");
	OBJECTMANAGER->Init("laserGreen04", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserBlue02.png");
	OBJECTMANAGER->Init("laserBlue02", texture); 
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserBlue05.png");
	OBJECTMANAGER->Init("laserBlue05", texture); 
	texture = IMAGEMANAGER->AddImage("./NewResourse/Skillboom/laserRed.png");
	OBJECTMANAGER->Init("laserRed", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed10.png");
	OBJECTMANAGER->Init("laserRed10", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Lasers/laserRed03.png");
	OBJECTMANAGER->Init("laserRed03", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Skillboom/spaceBuilding_008.png");
	OBJECTMANAGER->Init("spaceBuilding_008", texture);

	
	//Parts
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Parts/wingBlue_4.png");
	OBJECTMANAGER->Init("wingBlue_4", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Enemy/wingBlue_4.png");
	OBJECTMANAGER->Init("lwingBlue_4", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Enemy/arm.png");
	OBJECTMANAGER->Init("arm", texture); 
	texture = IMAGEMANAGER->AddImage("./NewResourse/Enemy/arm2.png");
	OBJECTMANAGER->Init("arm2", texture);


	//item
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Power-ups/powerupBlue_bolt.png"); 
	OBJECTMANAGER->Init("powerupBlue_bolt", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Power-ups/pill_red.png"); 
	OBJECTMANAGER->Init("pill_red", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Power-ups/powerupGreen_shield.png");
	OBJECTMANAGER->Init("powerupGreen_shield", texture);

	//Effect
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire1.png");
	OBJECTMANAGER->Init("Fire1", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire2.png");
	OBJECTMANAGER->Init("Fire2", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire3.png");
	OBJECTMANAGER->Init("Fire3", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire4.png");
	OBJECTMANAGER->Init("Fire4", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire5.png");
	OBJECTMANAGER->Init("Fire5", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire6.png");
	OBJECTMANAGER->Init("Fire6", texture);
	texture = IMAGEMANAGER->AddImage("./NewResourse/Effect/Fire7.png");
	OBJECTMANAGER->Init("Fire7", texture);
	texture = IMAGEMANAGER->AddImage("./SpaceShooterRedux/PNG/Effects/shield3.png");
	OBJECTMANAGER->Init("shield3", texture);

	//sound 
	SOUNDMANAGER->addSound("laser3", "./Digital_SFX_Set/laser3.mp3", false, false); 
	SOUNDMANAGER->addSound("laser5", "./Digital_SFX_Set/laser5.mp3", false, false);
	SOUNDMANAGER->addSound("8bit_bomb_explosion", "./Digital_SFX_Set/8bit_bomb_explosion.wav", false, false);
	SOUNDMANAGER->addSound("Electroman", "./Digital_SFX_Set/Electroman.mp3", false, true);

	enemycheck = 0;
	frame = 0;
	rframe = 0;
	activecount = 0;
	rockcount = 0;
	enemydelay = 70;
	/*
	for (int i = 0; i < 10; i++)
	{
		enemy.push_back(new Enemyblue3);
		enemy.push_back(new EnemyGreen1);
		enemy.push_back(new EnemyGreenmode1);
		enemy.push_back(new EnemyRed4);
	}
	*/
	//EnemyBossGreen1
	for (int i = 0; i < 45; i++)
	{
		if (i == 24 || i == 40)
			enemy.push_back(new EnemyGreenmode1);
		else if (i == 44)
			enemy.push_back(new BossGreenmode1);
		else
			pattern();
	}

	for (int i = 0; i < 50; i++)
	{
		item.push_back(new Item);
	}
	for (int i = 0; i < 50; i++)
	{
		rock.push_back(new Rock);
	}
}

void StageManager::pattern()
{
	int num = rand() % 3;
	switch (num)
	{
	case 0:
		enemy.push_back(new Enemyblue3);
		break;
	case 1:
		enemy.push_back(new EnemyGreen1);
		break;
	case 2:
		enemy.push_back(new EnemyRed4);
		break;
	}
}

void StageManager::MakeEnemy(Bullet * bullet, Score * score, Airplane * obj)
{
	if (activecount != 41)
	{
		if (frame % enemydelay == 0)
		{
			enemy[activecount]->ActiveOn();
			activecount++;
		}
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->Init();
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->GetPlayerinfo(obj);
		enemy[i]->Update();
		enemy[i]->Gethurt(bullet, score);
		if (enemy[i]->GetDeath())
		{
			if (item[i]->GetItemInit())
			{
				item[i]->InputEpos(enemy[i]->GetPos());
				item[i]->Init();
				item[i]->InputInit();
			}
			item[i]->InputOb(obj);
			item[i]->Update();
		}
	}
	frame++;
	if (frame > 200000)
		frame = 0;
	if (rframe % 70 == 0)
	{
		if (rockcount < 49)
			rockcount++;
		else
			rockcount = 0;
		rock[rockcount]->ActiveOn();
	}
	for (int i = 0; i < rock.size(); i++)
	{
		rock[i]->Init();
	}
	for (int i = 0; i < rock.size(); i++)
	{
		rock[i]->GetPlayerinfo(obj);
		rock[i]->Update(bullet, score);
	}
	rframe++;
}

void StageManager::Render()
{
	for (int i = 0; i < rock.size(); i++)
		rock[i]->Render();
	for (int i = 0; i < enemy.size(); i++)
		enemy[i]->Render();
	for (int i = 0; i < item.size(); i++)
		item[i]->Render();
}

void StageManager::Release()
{
	for (int i = 0; i < rock.size(); i++)
	{
		rock[i]->Release();
		delete rock[i];
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->Release();
		delete enemy[i];
	}
	for (int i = 0; i < item.size(); i++)
	{
		item[i]->Release();
		delete item[i];
	}
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

StageManager::StageManager()
{
}

StageManager::~StageManager()
{
}