#pragma once

class MainTitle : public BaseScene
{
private:
	Texture *texture[4];
	D3DXVECTOR2 pos[4];
	D3DXVECTOR2 cursorpos;
	POINT mouse;
	bool mactive;
	bool qactive;
	bool sceneactive;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	MainTitle();
	virtual ~MainTitle();
};

