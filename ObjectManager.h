#pragma once


class ObjectManager : public Singleton<ObjectManager>
{
private:
	map<string, Texture*> m_texture;

public:
	void Init(const string &key, Texture *texture);
	Texture *FindTexture(const string &key);
	void Release();

	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()