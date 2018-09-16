#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN

// Windows
#include <windows.h>
#include <crtdbg.h>

// C++
#include <map>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <timeapi.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

// DirectX9
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "./x86/d3d9.lib")
#pragma comment(lib, "./x86/d3dx9.lib")

//FrameWork
#include "ImageManager.h"
#include "SceneManager.h"
#include "EffectManager.h"
#include "ObjectManager.h"
#include "soundManager.h"

//custom
#include "SimpleFunction.h"
#include "Singleton.h"
#include "Airplane.h"
#include "BaseScene.h"
#include "Item.h"
#include "Bullet.h"
//#include "Enemy.h"
#include "EnemyRed4.h"
#include "enemyblue3.h"
#include "Enemybullet.h"
#include "EnemyGreen1.h"
#include "EnemyGreenmode1.h"
#include "BossGreenmode1.h"
#include "KeyManager.h"
#include "Map.h"
#include "Number.h"
#include "Object.h"
#include "Score.h"
#include "HP.h"
#include "InGameScene.h"
#include "MainProc.h"
#include "WinMain.h"

//stage
#include "StageManager.h"

extern HWND hWnd;
extern LPDIRECT3DDEVICE9 lpd3dDevice;