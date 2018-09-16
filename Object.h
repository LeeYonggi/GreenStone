#pragma once


struct Circle
{
	float radius;
	D3DXVECTOR2 center;
};

class Effect;
class Object
{
protected:
	enum CHARACTERSKILL
	{
		NO = 0,
		FIRST = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4
	};
	int skillkind;
	D3DXVECTOR2  pos;
	D3DXVECTOR2  size;
	Texture *texture;
	EFFECT_NUM ekind;
	Circle circle;
	bool active;

public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	bool IsCollision(Object *obj);
	bool IntersectCircle(Object *obj);
	bool GetActive() { return active; }
	void Inputskill(int temp) { skillkind = temp; }
	void InputPos(D3DXVECTOR2 temp) { pos = temp; }
	int Getskill() { return skillkind; }

	Object();
	virtual ~Object();

	D3DXVECTOR2 GetPos() { return pos; }
	D3DXVECTOR2 GetSize() { return size; }
	D3DXVECTOR2 CalculateDirection(const Object *cap)
	{
		D3DXVECTOR2 temp;
		temp.x = cap->pos.x - pos.x;
		temp.y = cap->pos.y - pos.y;
		D3DXVec2Normalize(&temp, &temp);
		temp *= 20.0f;
		return temp;
	}
	float CalculateRadian(const Object *cap)
	{
		D3DXVECTOR2 c_pos = cap->pos;
		D3DXVECTOR2 t_pos = pos;
		D3DXVECTOR2 *t_temp = D3DXVec2Normalize(&t_pos, &t_pos);
		D3DXVECTOR2 *c_temp = D3DXVec2Normalize(&c_pos, &c_pos);
		float angle = acosf(D3DXVec2Dot(t_temp, c_temp));
		return D3DXToRadian(angle);
	}
};

float VecLengthsq(D3DXVECTOR2 *vec1, D3DXVECTOR2 *vec2);