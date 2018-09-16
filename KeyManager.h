#pragma once
#include "Singleton.h"


class KeyManager : public Singleton<KeyManager>
{
public:
	int GetKey(int Key);
};

#define KEYMANAGER KeyManager::GetSingleton()