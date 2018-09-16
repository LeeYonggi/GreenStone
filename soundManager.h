#pragma once
#include <map>
#include <string>
#include "singleton.h"
using namespace std;

//fmod.hpp
#include "inc/fmod.hpp"

//lib��ũ
#pragma comment (lib, "lib/fmodex_vc.lib")

//���� ����
#define SOUNDBUFFER 10
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER EXTRACHANNELBUFFER + SOUNDBUFFER

using namespace FMOD;

class soundManager : public Singleton<soundManager>
{
private:
	typedef map<string, Sound*> arrSounds;
	typedef map<string, Sound*>::iterator arrSoundsIter;
	typedef map<string, Channel**> arrChannels;
	typedef map<string, Channel**>::iterator arrChannelsIter;

private:
	System* _system;
	//Sound** _sound;
	Channel** _channel;

	arrSounds _mTotalSounds;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void addSound(string keyName, char* soundName, bool bgm, bool loop);
	void play(string keyName, float volume = 1.0f); //0.0 ~ 1.0 0 ~ 255
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);
	void setVolume(string keyName, float volume = 1.0f);

	//���������?
	bool isPlaySound(string keyName);

	//�Ͻ�����������?
	bool isPauseSound(string keyName);


	soundManager();
	~soundManager();
};

#define SOUNDMANAGER soundManager::GetSingleton()