#pragma once

class MainTitle;
class MainProc
{
private:
	Texture *mouseCuser;
	BOOL bAct;
	POINT mouse;

public:
	int Init();
	int Update();
	int Render();
	int Release();

	BOOL GetAct();

	MainProc();
	virtual ~MainProc();
};