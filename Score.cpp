#include "stdafx.h"

void Score::Init()
{
	for (int i = 0; i < 10; i++)
	{
		number[i] = new Number;
	}
	for (int i = 0; i < 10; i++)
	{
		number[i]->Init(i);
	}
}

void Score::DrawPoint()
{
	number[vscore % 10]->Render(675, 10);
	vscore /= 10;
	number[vscore % 10]->Render(650, 10);
	vscore /= 10;
	number[vscore % 10]->Render(625, 10);
	vscore /= 10;
	number[vscore % 10]->Render(600, 10);
	vscore /= 10;
	number[vscore % 10]->Render(575, 10);
	vscore /= 10;
	number[vscore % 10]->Render(550, 10);
	vscore /= 10;
}

void Score::Update()
{
	vscore = score;
}

void Score::Release()
{
	for (int i = 0; i < 10; i++)
	{
		number[i]->Release();
		delete number[i];
	}
}

void Score::GetPoint(int num)
{
	score += num;
}

Score::Score()
{
	score = 000000;
	vscore = score;
	spos = 625;
}

Score::~Score()
{
}
