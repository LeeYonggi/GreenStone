#include "stdafx.h"

void Number::Init(int num)
{
	switch (num)
	{
	case 0:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral0.png");
		break;
	case 1:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral1.png");
		break;
	case 2:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral2.png");
		break;
	case 3:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral3.png");
		break;
	case 4:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral4.png");
		break;
	case 5:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral5.png");
		break;
	case 6:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral6.png");
		break;
	case 7:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral7.png");
		break;
	case 8:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral8.png");
		break;
	case 9:
		texture = IMAGEMANAGER->AddImage("./NewResourse/numeral9.png");
		break;
	}
}

void Number::Render(int x, int y)
{
	pos.x = x;
	pos.y = y;
	IMAGEMANAGER->DrawImage(texture, pos.x, pos.y);
}

void Number::Release()
{
	texture->lpd3dTex->Release();
	SAFE_DELETE(texture);
}

Number::Number()
{
	pos.x = 0;
	pos.y = 0;
}

Number::~Number()
{
}
