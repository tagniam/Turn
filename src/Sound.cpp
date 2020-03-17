#include "../include/Sound.h"

#ifdef _WIN32
#include <Windows.h>
#include <MMSystem.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <thread>
#endif

// Sounds found online at:
//  https://freesound.org/people/XxChr0nosxX/sounds/268227/ attack miss
//  https://freesound.org/people/Taira%20Komori/sounds/213696/ attack crit
//  https://freesound.org/people/lostchocolatelab/sounds/1468/ attack0
//  https://freesound.org/people/JohnBuhr/sounds/326868/ attack1
//  https://freesound.org/people/loudernoises/sounds/334169/ attack2
//  https://freesound.org/people/Ali_6868/sounds/384915/ arrow
//  https://opengameart.org/content/spell-sounds-starter-pack heal

PlatformSoundHelper SoundMaker::ms_SoundHelper;

PlatformSoundHelper::PlatformSoundHelper() {
#ifndef _WIN32
	m_resourceMutex.lock();
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
	m_resourceMutex.unlock();
#endif
}

PlatformSoundHelper::~PlatformSoundHelper() {
#ifndef _WIN32
	m_resourceMutex.lock();
	Mix_CloseAudio();
	SDL_Quit();
	m_resourceMutex.unlock();
#endif
}

void PlatformSoundHelper::PlaySoundFile(std::string const& filename) {
#ifdef _WIN32
	PlaySound(filename.c_str(), NULL, SND_ASYNC);
#else
	// It would be possible to pre-cache the sounds for SDL_mixer, however instead
	// this simply loads plays and unloads them. This closer emulates how PlaySound
	// works on Windows and should be fine for this scenario. If, however, it happens
	// to give poor results, it should be changed to cache the sounds and take care of
	// unloading them properly
	std::thread t([=]() {
			m_resourceMutex.lock();
			Mix_Chunk* waveSound = Mix_LoadWAV(filename.c_str());
			if (waveSound)
			{
				int channel = Mix_PlayChannel(-1, waveSound, 0);
				while (Mix_Playing(channel))
				{
					// Sleep for a tiny amount of time to avoid maxing out the CPU in an idle loop
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				}
				Mix_FreeChunk(waveSound);
			}
			m_resourceMutex.unlock();
		});
	t.detach();
#endif
}

SoundMaker::SoundMaker():mInfo(),
						altAttackFileName("sounds/arrow.wav"),
						healFileName("sounds/heal.wav")
{
	//
	// Initialize file name array to names of files for attacks
	//
	std::string FileName = SNDDIRECTORY;
	if (!mInfo.fileNamePrefix.empty())
	{
		FileName += mInfo.fileNamePrefix + std::string("_");
	}
	attackFileNames.push_back(FileName + ATACKFILENAMEMISS);
	attackFileNames.push_back(FileName + ATTACKFILENAME1);
	attackFileNames.push_back(FileName + ATTACKFILENAME2);
	attackFileNames.push_back(FileName + ATTACKFILENAME3);
	attackFileNames.push_back(FileName + ATTACKFILENAMECRIT);
}

void SoundMaker::PlayPrimaryAttack(int damageDealt)
{
	//
	// play attack sound based on damage delt. 0 is miss, top is
	// crit, all other are ramdomized
	//
	int index = 0;
	if (damageDealt > 0  && damageDealt < mInfo.attackRange.second)
	{
		index = 1+rand()%3;
	}
	else if (damageDealt >= mInfo.attackRange.second)
	{
		index = 4;
	}
	PlaySoundFile(attackFileNames[index]);
}

void SoundMaker::PlaySecondaryAttack(void)
{
	PlaySoundFile(altAttackFileName.c_str());
}

void SoundMaker::PlayHeal(void) {
	PlaySoundFile(healFileName.c_str());
}

void SoundMaker::PlaySoundFile(std::string const& filename){
	ms_SoundHelper.PlaySoundFile(filename);
}
