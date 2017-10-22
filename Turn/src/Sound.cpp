#include "../include/Sound.h"

#include <Windows.h>
#include <MMSystem.h>

SoundMaker::SoundMaker(void):attackFileName("sounds/attack.wav"),
							 attack2FileName("sounds/arrow.wav"),
							 healFileName("sounds/heal.wav"){
}
void SoundMaker::PlayPrimaryAttack(void) {
	PlaySound(attackFileName.c_str(), NULL, SND_ASYNC);
}
void SoundMaker::PlaySecondaryAttack(void){
	PlaySound(attack2FileName.c_str(), NULL, SND_ASYNC);
}
void SoundMaker::PlayHeal(void) {
	PlaySound(healFileName.c_str(), NULL, SND_ASYNC);
}