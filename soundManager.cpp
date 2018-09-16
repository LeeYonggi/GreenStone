#include "stdafx.h"
#include "soundManager.h"


soundManager::soundManager()
	: _system(NULL),
	_channel(NULL)
{
}


soundManager::~soundManager()
{
}

HRESULT soundManager::init()
{
	//���� �ý��� ����
	System_Create(&_system);

	//ä�μ� �ʱ�ȭ(����)
	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, 0);

	//ä��, ���� �����Ҵ�(�ʼ�)
	_channel = new Channel*[TOTALSOUNDBUFFER];

	//���ø޸� �о��ش�
	memset(_channel, 0, sizeof(Channel*) * (TOTALSOUNDBUFFER));


	return S_OK;
}

void soundManager::release()
{

}

void soundManager::update()
{

}

void soundManager::render()
{

}

void soundManager::addSound(string keyName, char* soundName, bool bgm, bool loop)
{
	Sound* sound;
	//���� ����
	if (loop)
	{
		if (bgm)
		{
			_system->createStream(soundName, FMOD_LOOP_NORMAL, 0, &sound);
		}
		else
		{
			_system->createSound(soundName, FMOD_LOOP_NORMAL, 0, &sound);
		}
	}
	else
	{
		_system->createStream(soundName, FMOD_DEFAULT, 0, &sound);
	}

	//�ʿ� ���带 Ű���� �Բ� �־���
	_mTotalSounds.insert(make_pair(keyName, sound));
}

void soundManager::play(string keyName, float volume) //0.0 ~ 1.0 0 ~ 255
{
	//arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	auto iter = _mTotalSounds.find(keyName);
	if (iter != _mTotalSounds.end())
	{
		//���� �÷��� ����
		_system->playSound(FMOD_CHANNEL_FREE, iter->second, false, &_channel[count]);

		//���� ����
		_channel[count]->setVolume(volume);
	}
}

void soundManager::stop(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}

void soundManager::pause(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}

void soundManager::setVolume(string keyName, float volume)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setVolume(volume);
			break;
		}
	}
}

//���������?
bool soundManager::isPlaySound(string keyName)
{
	bool isPlay;
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

//�Ͻ�����������?
bool soundManager::isPauseSound(string keyName)
{
	bool isPause;

	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}