#pragma once


class Effect
{
private:
	EFFECT_NUM kind;
	D3DXVECTOR2 pos;
	vector<Texture*> texture;
	Texture *ctexture;
	int frame;
	int alpha;
	bool active;

public:
	void InitFireNine();
	void InitLaserred();
	void Update(D3DXVECTOR2 cpos);
	void Render();
	void Release();
	void ActiveOn(D3DXVECTOR2 cpos) { active = true; pos = cpos; }

	Effect();
	virtual ~Effect();
};

