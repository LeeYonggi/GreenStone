#pragma once
#include "Singleton.h"
enum EFFECT_NUM
{
	FIRENINE = 0,
	LASERRED
};

class Effect;
class EffectManager : public Singleton<EffectManager>
{
private:
	vector<Effect*> effect;
	vector<Effect*> leffect;
	Texture *cTexture;
	D3DXVECTOR2 ex;
	int redDelay;

public:
	void Init();
	void EffectUpdate(D3DXVECTOR2 pos, EFFECT_NUM kind);
	void LaserUpdate();
	void Render(EFFECT_NUM kind);
	void Release();

	EffectManager();
	virtual ~EffectManager();
};

#define EFFECTMANAGER EffectManager::GetSingleton()