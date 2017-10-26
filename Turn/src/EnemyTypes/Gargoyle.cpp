#include "../../include/EnemyTypes/Gargoyle.h"

Gargoyle::Gargoyle() {
	name = "Gargoyle";
	ExperienceAmount = 100;
	CoinsDrop = 50 + rand() % 100;
}

EnemyType Gargoyle::GetType() {
    return etGargoyle;
}

int Gargoyle::ReturnDamage() {
	return 5 + rand() % 20;
}

int Gargoyle::ReturnRiskAttackDamage() {
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

int Gargoyle::ReturnHealAmount() {
	return 6 + rand() % 15;
}
