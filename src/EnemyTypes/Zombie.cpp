#include "../../include/Common.h"
#include "../../include/EnemyTypes/Zombie.h"

Zombie::Zombie() {
	name = "Zombie";
	ExperienceAmount = 90;
	CoinsDrop = Common::RandomInt(40, 64);
}

EnemyType Zombie::GetType() {
    return etZombie;
}

int Zombie::ReturnDamage() {
	return Common::RandomInt(20, 29);
}

int Zombie::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 6);
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5: case 6:
		return 30;
		break;
	default:
		return 0;
		break;
	}
}

int Zombie::ReturnHealAmount() {
	return Common::RandomInt(2, 41);
}

std::string Zombie::GetIntro()
{
	return "\"Brains,\" it moans...";
}
