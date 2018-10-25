#include "../../include/EnemyTypes/GiantBat.h"

GiantBat::GiantBat() {
	name = "Giant Bat";
	ExperienceAmount = 100;
	CoinsDrop = rand() % 100;
}

EnemyType GiantBat::GetType() {
	return etGiantBat;
}

int GiantBat::ReturnDamage() {
	return 7 + rand() % 10;
}

int GiantBat::ReturnRiskAttackDamage() {
	int selector = rand() % 7;
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

int GiantBat::ReturnHealAmount() {
	return 5 + rand() % 11;
}


std::string GiantBat::GetIntro()
{
	return "A powerful wind comes from somewhere nearby...";
}
