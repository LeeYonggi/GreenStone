#include "stdafx.h"

MainProc main;
LPDIRECT3DDEVICE9 lpd3dDevice = NULL;
HWND hWnd;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(836);

	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass";

	RegisterClassEx(&wc);

	SOUNDMANAGER->init();

	hWnd = CreateWindowEx(NULL,
		"WindowClass",
		"DirectX9 FrameWork Base",
		WS_OVERLAPPEDWINDOW,
		GetSystemMetrics(SM_CXSCREEN)/2 - SCREEN_WIDTH / 2, 0,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	RECT rc = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	SetWindowPos(hWnd, NULL, 0, 0, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);

	LPDIRECT3D9 d3d9;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;

	d3d9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp,
		&lpd3dDevice);
	d3d9->Release();
	d3d9 = NULL;

	main.Init();
	ShowWindow(hWnd, nCmdShow);

	MSG msg;

	const float timeScale = 0.001f;
	const float frame = 1.0f / 30.0f;

	__int64 curTime;
	__int64 lastTime = timeGetTime();
	float mainTime = 0.0f;

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return (int)msg.wParam;
			}
		}
		else if (main.GetAct())
		{
			curTime = timeGetTime();
			mainTime += (curTime - lastTime) * timeScale;
			lastTime = curTime;

			while (mainTime >= frame)
			{
				mainTime -= frame;

				main.Update();

				lpd3dDevice->Clear(0, NULL, D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xff0000ff, 1.0f, 0);
				lpd3dDevice->BeginScene();
				main.Render();
				lpd3dDevice->EndScene();
				lpd3dDevice->Present(0, 0, 0, 0);
			}
		}

		if (msg.message == WM_QUIT)
			break;
	}

	if (lpd3dDevice)
		lpd3dDevice->Release();
	lpd3dDevice = nullptr;

	main.Release();
	SOUNDMANAGER->release();
	SOUNDMANAGER->ReleaseSingleton();
	STAGEMANAGER->ReleaseSingleton();
	OBJECTMANAGER->ReleaseSingleton();
	KEYMANAGER->ReleaseSingleton();
	EFFECTMANAGER->ReleaseSingleton();
	return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}