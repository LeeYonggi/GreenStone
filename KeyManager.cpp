#include "stdafx.h"
#include "KeyManager.h"

int KeyManager::GetKey(int Key)
{
	if (GetAsyncKeyState(Key) & 0x8000)
		return true;
	else
		false;
}
