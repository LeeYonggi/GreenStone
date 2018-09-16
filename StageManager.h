#pragma once

class Enemy;
class Bullet;
class Score;
class Object;
class Rock;
class StageManager : public Singleton<StageManager>
{
private:
	Texture *texture;
	vector<Enemy*> enemy;
	vector<Item*> item;
	vector<Rock*> rock;
	int frame;
	int rframe;
	int enemycheck;
	int activecount;
	int rockcount;
	int enemydelay;
	
public:
	void Initialize();
	void pattern();
	void MakeEnemy(Bullet *bullet, Score *score, Airplane *obj);
	void Render();
	void Release();

	vector<Enemy*> GetEnemy() { return enemy; }
	StageManager();

	virtual ~StageManager();
};

#define STAGEMANAGER StageManager::GetSingleton() 