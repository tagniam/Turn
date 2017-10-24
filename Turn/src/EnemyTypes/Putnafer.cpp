#include "..\..\include\EnemyTypes\Putnafer.h"

Putnafer::Putnafer() {
	name = "Putnafer";
	ExperienceAmount = 150;
	CoinsDrop = 90 + rand() % 20;
}

EnemyType Putnafer::GetType() {
    return etPutnafer;
}

int Putnafer::ReturnDamage() {
	return 10 + rand() % 22;
}

int Putnafer::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2:
		return 5;
		break;
  case 3:
    return 1;
    break;
	case 4: case 5:
		return 25;
		break;
	default:
		return 0;
		break;
	}
}

int Putnafer::ReturnHealAmount() {
	return 2 + rand() % 12;
}
