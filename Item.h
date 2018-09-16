#pragma once
#include "Object.h"


class Item : public Object
{
private:
	enum ITEMTYPE
	{
		POWER_UP,
		HP_UP,
		SHIELD
	};
	ITEMTYPE kind;
	D3DXVECTOR2 epos;
	D3DXVECTOR2 move;
	Airplane *character;
	bool activeinit;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void InputEpos(D3DXVECTOR2 pos) { epos = pos; }
	void InputOb(Airplane *temp) { character = temp; }
	void InputInit() { activeinit = false; }
	bool GetItemActive() { return active; }
	bool GetItemInit() { return activeinit; }
	Item();
	virtual ~Item();
};

