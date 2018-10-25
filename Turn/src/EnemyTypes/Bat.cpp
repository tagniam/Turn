#include "../../include/EnemyTypes/Bat.h"

Bat::Bat() {
	name = "Bat";
	ExperienceAmount = 20;
	CoinsDrop = rand() % 51;
}

EnemyType Bat::GetType() {
	return etBat;
}

int Bat::ReturnDamage() {
	return 1+rand()%10;
}

int Bat::ReturnRiskAttackDamage() {
	int selector = rand() % 7;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 15;
		break;
	case 7:
		return 20;
		break;
	default:
		return 0;
		break;
	}
}

int Bat::ReturnHealAmount() {
	return 2 + rand() % 11;
}


std::string Bat::GetIntro()
{
	return "Eeeeeeeeeeeeee...";
}
