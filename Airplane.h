#pragma once
#include "Object.h"

class Effect;
class Airplane : public Object
{
private:
	Texture *texture2;
	int hp;
	int sframe;
	int hframe;
	int boomhp;
	bool hit;
	bool shieldcheck;
public:
	void Init();
	void Update();
	void Render();
	void Release();
	
	int Gethp() { return hp; }
	int Getboom() { return boomhp; }
	bool Gethit() { return hit; }
	bool Getshield() { return shieldcheck; }
	void Inputboom(int temp) { boomhp += temp; }
	void Inputhit(bool colhit) { hit = colhit; }
	void InputDamage(int a) { hp -= a; }
	void Inputshield(bool shield) { shieldcheck = shield; }
	Airplane();
	virtual ~Airplane();
};

