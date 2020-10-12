#include "../../include/Common.h"
#include "../../include/EnemyTypes/Skeleton.h"

Skeleton::Skeleton() {
	name = "Skeleton";
	ExperienceAmount = 25;
	CoinsDrop = Common::RandomInt(3, 50);
}

EnemyType Skeleton::GetType() {
	return etSkeleton;
}

int Skeleton::ReturnDamage() {
	return Common::RandomInt(3, 7);
}

int Skeleton::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 9);
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

int Skeleton::ReturnHealAmount() {
	return Common::RandomInt(1, 15);
}

std::string Skeleton::GetIntro()
{
	return "Clack, clack, clack...";
}
