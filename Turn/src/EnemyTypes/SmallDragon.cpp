#include "../../include/EnemyTypes/SmallDragon.h"

SmallDragon::SmallDragon() {
	name = "Small Dragon";
	ExperienceAmount = 135;
	CoinsDrop = 50 + rand() % 30;
}

EnemyType SmallDragon::GetType() {
    return etSmallDragon;
}

int SmallDragon::ReturnDamage() {
	return 15 + rand() % 15;
}

int SmallDragon::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 5;
		break;
	case 4: case 5:
		return 30;
		break;
	default:
		return 0;
		break;
	}
}

int SmallDragon::ReturnHealAmount() {
	return 15 + rand() % 10;
}

std::string SmallDragon::GetIntro() {
	return "You hope there isn't a bigger version of this monster...";
}