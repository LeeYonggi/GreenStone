#pragma once


class Number
{
private:
	D3DXVECTOR2 pos;
	Texture *texture;

public:
	void Init(int num);
	void Render(int x, int y);
	void Release();

	Number();
	virtual ~Number();
};