#include "../../include/EnemyTypes/Murloc.h"

Murloc::Murloc() {
	name = "Murloc";
	ExperienceAmount = 35;
	CoinsDrop = rand() % 40;
}

EnemyType Murloc::GetType() {
    return etMurloc;
}

int Murloc::ReturnDamage() {
	return 5 + rand() % 5;
}

int Murloc::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 12;
		break;
	default:
		return 0;
		break;
	}
}

int Murloc::ReturnHealAmount() {
	return 5 + rand() % 35;
}

std::string Murloc::GetIntro()
{
	return "The sound of wet footsteps approaches...";
}