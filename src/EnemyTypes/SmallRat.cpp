#include "../../include/Common.h"
#include "../../include/EnemyTypes/SmallRat.h"

SmallRat::SmallRat() {
	name = "Small Rat";
	ExperienceAmount = 15;
	CoinsDrop = Common::RandomInt(3, 30);
}

EnemyType SmallRat::GetType() {
	return etSmallRat;
}

int SmallRat::ReturnDamage() {
	return Common::RandomInt(2, 6);
}

int SmallRat::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 9);
	switch (selector){
	case 0: case 1: case 2: case 3:
		return 0;
		break;
	case 4: case 5: case 6: case 7: case 8:
		return 2;
		break;
	case 9:
		return 5;
		break;
	case 10:
		return 10;
		break;
	default:
		return 0;
		break;
	}
}

int SmallRat::ReturnHealAmount() {
	return Common::RandomInt(3, 17);
}

std::string SmallRat::GetIntro()
{
	return "Little feet tripping over the floor...";
}
