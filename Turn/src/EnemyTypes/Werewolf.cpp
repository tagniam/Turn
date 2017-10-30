#include "../../include/EnemyTypes/Werewolf.h"

Werewolf::Werewolf() {
	name = "Werewolf";
	ExperienceAmount = 100;
	CoinsDrop = 50 + rand() % 100;
}

EnemyType Werewolf::GetType() {
    return etWerewolf;
}

int Werewolf::ReturnDamage() {
	return 5 + rand() % 20;
}

int Werewolf::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 20;
		break;
	default:
		return 0;
		break;
	}
}

int Werewolf::ReturnHealAmount() {
	return 4 + rand() % 15;
}

std::string Werewolf::GetIntro()
{
	std::string IntroText = "Smells like wet dog.";
	return IntroText;
}