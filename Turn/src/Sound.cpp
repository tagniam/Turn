#include "../include/Sound.h"

#include <Windows.h>
#include <MMSystem.h>


// Sounds found online at:
//  https://freesound.org/people/XxChr0nosxX/sounds/268227/ attack miss
//  https://freesound.org/people/Taira%20Komori/sounds/213696/ attack crit
//  https://freesound.org/people/lostchocolatelab/sounds/1468/ attack0
//  https://freesound.org/people/JohnBuhr/sounds/326868/ attack1
//  https://freesound.org/people/loudernoises/sounds/334169/ attack2
//  https://freesound.org/people/Ali_6868/sounds/384915/ arrow
//  https://opengameart.org/content/spell-sounds-starter-pack heal
//  https://freesound.org/people/LittleRobotSoundFactory/sounds/270404/ level up
//  https://freesound.org/people/Anthousai/sounds/336590/ whetstone
//  https://freesound.org/people/Sancho82/sounds/78457/ bomb
//  https://freesound.org/people/Jamius/sounds/41529/ potion


SoundMaker::SoundMaker():mInfo(),
						altAttackFileName("sounds/arrow.wav"),
						healFileName("sounds/heal.wav"),
						bombFileName("sounds/bomb.wav"),
						whetstoneFileName("sounds/whetstone.wav"),
						potionFileName("sounds/potion.wav"),
						levelUpFileName("sounds/levelup.wav")
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
	PlaySound(attackFileNames[index].c_str(), NULL, SND_ASYNC);
}


void SoundMaker::PlaySecondaryAttack(void)
{
	PlaySound(altAttackFileName.c_str(), NULL, SND_ASYNC);
}


void SoundMaker::PlayHeal(void) 
{
	PlaySound(healFileName.c_str(), NULL, SND_ASYNC);
}


void SoundMaker::PlayBomb(void)
{
	PlaySound(bombFileName.c_str(), NULL, SND_ASYNC);
}


void SoundMaker::PlayWhetstone(void)
{
	PlaySound(whetstoneFileName.c_str(), NULL, SND_ASYNC);
}


void SoundMaker::PlayPotion(void)
{
	PlaySound(potionFileName.c_str(), NULL, SND_ASYNC);
}


void SoundMaker::PlayLevelUp(void)
{
	PlaySound(levelUpFileName.c_str(), NULL, SND_ASYNC);
}