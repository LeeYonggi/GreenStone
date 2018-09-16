#pragma once
#include "BaseScene.h"
#include "Singleton.h"

class SceneManager : public Singleton<SceneManager>
{
private:
	BaseScene *activeScene;
	std::map<std::string, BaseScene*> m_mapScene;

public:
	SceneManager();
	virtual ~SceneManager();

	void Update();
	void Render();
	void Release();
	void AddScene(const std::string &key, BaseScene *value);
	void ChangerScene(const std::string &key);
};

#define SCENEMANAGER SceneManager::GetSingleton()