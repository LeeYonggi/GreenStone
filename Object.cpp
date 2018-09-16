#include "stdafx.h"
#include "Effect.h"

bool Object::IsCollision(Object * obj)
{
	RECT thisRect = { pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x, pos.y + size.y };
	RECT objRect = { obj->GetPos().x - obj->GetSize().x / 2, obj->GetPos().y - obj->GetSize().y / 2,
		obj->GetPos().x + obj->GetSize().x, obj->GetPos().y + obj->GetSize().y};
	RECT temp;
	if (IntersectRect(&temp, &thisRect, &objRect))
	{
		return true;
	}
	return false;
}

bool Object::IntersectCircle(Object * obj)
{
	circle.center = (pos);
	obj->circle.center = (obj->pos);
	float d(D3DXVec2Length(&(circle.center - obj->circle.center)));
	float r1(circle.radius);
	float r2(obj->circle.radius);
	return (d <= (r1 + r2));
}

Object::Object()
{
}

Object::~Object()
{
}

float VecLengthsq(D3DXVECTOR2 *vec1, D3DXVECTOR2 *vec2)
{
	D3DXVECTOR2 temp((vec1->x - vec2->x) * (vec1->x - vec2->x), (vec1->y - vec2->y) * (vec1->y - vec2->y));
	return (temp.x - temp.y);
}
