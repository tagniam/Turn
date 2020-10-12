#include "../../include/Common.h"
#include "../../include/EnemyTypes/Cerberus.h"

Cerberus::Cerberus() {
	name = "Cerberus";
	ExperienceAmount = 120;
	CoinsDrop = Common::RandomInt(40, 60);
}

EnemyType Cerberus::GetType() {
	return etCerberus;
}

int Cerberus::ReturnDamage() {
	return Common::RandomInt(15, 25);
}

int Cerberus::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 6);
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
	return Common::RandomInt(5, 10);
}


std::string Cerberus::GetIntro()
{
	return "Something is growling behind you...";
}
