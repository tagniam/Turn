#include "../include/Sound.h"

#include <Windows.h>
#include <MMSystem.h>


// Sounds found online at:
//  https://freesound.org/people/Ali_6868/sounds/384915/ arrow
//  https://freesound.org/people/TreyHolton/sounds/238307/ heal
//  https://freesound.org/people/Taira%20Komori/sounds/213696/ attack

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