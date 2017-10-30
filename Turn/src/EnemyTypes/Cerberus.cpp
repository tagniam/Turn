#include "../../include/EnemyTypes/Cerberus.h"

Cerberus::Cerberus() {
	name = "Cerberus";
	ExperienceAmount = 120;
	CoinsDrop = 40 + rand() % 21;
}

EnemyType Cerberus::GetType() {
	return etCerberus;
}

int Cerberus::ReturnDamage() {
	return 15 + rand() % 11;
}

int Cerberus::ReturnRiskAttackDamage() {
	int selector = rand() % 7;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 25;
		break;
	case 7:
		return 30;
		break;
	default:
		return 0;
		break;
	}
}

int Cerberus::ReturnHealAmount() {
	return 5 + rand() % 6;
}


std::string Cerberus::GetIntro()
{
	std::string IntroText = "Something is growling behind you...";
	return IntroText;
}