#pragma once


class Map : public Object
{
private:
	Texture *texture2;
	D3DXVECTOR2 pos2;

public:
	void Init();
	void Update();
	void Render();
	void Release();
};