#include "stdafx.h"

SceneManager::SceneManager()
	:activeScene(nullptr)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	if(activeScene)
		activeScene->Update();
}

void SceneManager::Render()
{
	if(activeScene)
		activeScene->Render();
}

void SceneManager::Release()
{
	if(activeScene)
		activeScene->Release();
	for (auto temp : m_mapScene)
		SAFE_DELETE(temp.second);
	m_mapScene.clear();
}

void SceneManager::AddScene(const std::string & key, BaseScene * value)
{
	if (value)
	{
		auto iter = m_mapScene.find(key);
		if (iter == m_mapScene.end())
			m_mapScene.insert(make_pair(key, value));
	}
}

void SceneManager::ChangerScene(const std::string & key)
{
	auto iter = m_mapScene.find(key);
	if (iter != m_mapScene.end())
	{
		if (activeScene)
		{
			activeScene->Release();
		}
		activeScene = iter->second;
		activeScene->Init();
	}
}
