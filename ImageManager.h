#pragma once
#include "Singleton.h"

class Texture
{
public:
	LPDIRECT3DTEXTURE9 lpd3dTex;
	D3DXIMAGE_INFO info;

	void DrawImage(float x, float y, float angle = 0.0f, int alpha = 255.0f);
};

class ImageManager : public Singleton<ImageManager>
{
private:
	LPD3DXSPRITE lpd3dSprite;
	
	int Init();
	int Release();

public:
	ImageManager();
	virtual ~ImageManager();

	HRESULT Begin();
	void End();

	Texture *AddImage(LPCSTR lpPath);
	void DrawRGBImage(Texture *pTexture, float x, float y, float angle = 0.0f, int alpha = 255);
	void DrawImage(Texture *pTexture, float x, float y, float angle = 0.0f, int alpha = 255);
	void DrawFrameImage(Texture *pTexture, int wc, int hc, int wi, int hi, float x, float y, float angle, int alpha);
};

#define IMAGEMANAGER ImageManager::GetSingleton()