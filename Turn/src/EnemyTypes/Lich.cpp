#include "Turn/EnemyTypes/Lich.h"

Lich::Lich() {
	name = "Lich";
	ExperienceAmount = 100;
	CoinsDrop = 50 + rand() % 100;
}

EnemyType Lich::GetType() {
    return etLich;
}

int Lich::ReturnDamage() {
	return 5 + rand() % 20;
}

int Lich::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 30;
		break;
	default:
		return 0;
		break;
	}
}

int Lich::ReturnHealAmount() {
	return 5 + rand() % 25;
}
