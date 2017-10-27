#include "../../include/EnemyTypes/Rat.h"

Rat::Rat() {
	name = "Rat";
	ExperienceAmount = 25;
	CoinsDrop = 3 + rand() % 48;
}

EnemyType Rat::GetType() {
	return etRat;
}

int Rat::ReturnDamage() {
	return 3 + rand() % 5;
}

int Rat::ReturnRiskAttackDamage() {
	int selector = rand() % 10;
	switch (selector){
	case 0: 
		return 0;
		break;
	case 1: case 2: case 3:
		return 1;
		break;
	case 4: case 5: case 6: case 7: case 8:
		return 3;
		break;
	case 9: 
		return 5;
		break;
	case 10:
		return 20;
		break;
	default:
		return 0;
		break;
	}
}

int Rat::ReturnHealAmount() {
	return 1 + rand() % 15;
}
