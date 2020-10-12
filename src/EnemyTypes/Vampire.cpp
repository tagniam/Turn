#include "../../include/Common.h"
#include "../../include/EnemyTypes/Vampire.h"

Vampire::Vampire() {
	name = "Vampire";
	ExperienceAmount = 100;
	CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Vampire::GetType() {
    return etVampire;
}

int Vampire::ReturnDamage() {
	return Common::RandomInt(5, 24);
}

int Vampire::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 5);
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

int Vampire::ReturnHealAmount() {
	return Common::RandomInt(8, 22);
}

std::string Vampire::GetIntro()
{
	return "A dark presence...";
}
