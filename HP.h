#pragma once
class HP
{
private:
	Number *number[10];
	Texture *texture[3];
	int hp;
	int boom;
public:
	void Init();
	void Update();
	void Render();
	void Release();

	void Inputboom(int temp) { boom = temp; }
	void Inputhp(int hp) { this->hp = hp; }
	HP();
	virtual ~HP();
};

