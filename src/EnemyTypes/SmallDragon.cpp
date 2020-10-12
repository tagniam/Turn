#include "../../include/Common.h"
#include "../../include/EnemyTypes/SmallDragon.h"

SmallDragon::SmallDragon() {
	name = "Small Dragon";
	ExperienceAmount = 135;
	CoinsDrop = Common::RandomInt(50, 79);
}

EnemyType SmallDragon::GetType() {
    return etSmallDragon;
}

int SmallDragon::ReturnDamage() {
	return Common::RandomInt(15, 29);
}

int SmallDragon::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 5);
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 5;
		break;
	case 4: case 5:
		return 30;
		break;
	default:
		return 0;
		break;
	}
}

int SmallDragon::ReturnHealAmount() {
	return Common::RandomInt(15, 24);
}

std::string SmallDragon::GetIntro() {
	return "You hope there isn't a bigger version of this monster...";
}
