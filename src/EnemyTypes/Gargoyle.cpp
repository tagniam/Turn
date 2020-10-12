#include "../../include/Common.h"
#include "../../include/EnemyTypes/Gargoyle.h"

Gargoyle::Gargoyle() {
	name = "Gargoyle";
	ExperienceAmount = 100;
	CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Gargoyle::GetType() {
    return etGargoyle;
}

int Gargoyle::ReturnDamage() {
	return Common::RandomInt(5, 24);
}

int Gargoyle::ReturnRiskAttackDamage() {
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

int Gargoyle::ReturnHealAmount() {
	return Common::RandomInt(6, 20);
}

std::string Gargoyle::GetIntro()
{
	return "A silhouette of wings and horns swoops towards you...";
}
