#include "stdafx.h"

void ObjectManager::Init(const string &key, Texture *texture)
{
	if (texture)
	{
		auto iter = m_texture.find(key);
		if (iter == m_texture.end())
		{
			m_texture.insert(make_pair(key, texture));
		}
	}
}

Texture * ObjectManager::FindTexture(const string & key)
{
	auto iter = m_texture.find(key);
	if (iter != m_texture.end())
	{
		return iter->second;
	}
}

void ObjectManager::Release()
{
	m_texture.clear();
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}
