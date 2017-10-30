#include "../../include/EnemyTypes/Vampire.h"

Vampire::Vampire() {
	name = "Vampire";
	ExperienceAmount = 100;
	CoinsDrop = 50 + rand() % 100;
}

EnemyType Vampire::GetType() {
    return etVampire;
}

int Vampire::ReturnDamage() {
	return 5 + rand() % 20;
}

int Vampire::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 25;
		break;
	default:
		return 0;
		break;
	}
}

int Vampire::ReturnHealAmount() {
	return 8 + rand() % 15;
}

std::string Vampire::GetIntro()
{
	std::string IntroText = "A dark presence...";
	return IntroText;
}
