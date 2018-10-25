#include "../../include/EnemyTypes/GiantSpider.h"

GiantSpider::GiantSpider() {
	name = "Cerberus";
	ExperienceAmount = 110;
	CoinsDrop = 40 + rand() % 10;
}

EnemyType GiantSpider::GetType() {
	return etGiantSpider;
}

int GiantSpider::ReturnDamage() {
	return 8 + rand() % 11;
}

int GiantSpider::ReturnRiskAttackDamage() {
	int selector = rand() % 7;
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

int GiantSpider::ReturnHealAmount() {
	return 5 + rand() % 6;
}


std::string GiantSpider::GetIntro()
{
	return "There is something moving above you...";
}
