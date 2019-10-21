#include "../../include/EnemyTypes/Goblin.h"

Goblin::Goblin() {
	name = "Goblin";
	ExperienceAmount = 100;
	CoinsDrop = 50 + rand() % 100;
}

EnemyType Goblin::GetType() {
    return etGoblin;
}

int Goblin::ReturnDamage() {
	return 5 + rand() % 20;
}

int Goblin::ReturnRiskAttackDamage() {
	int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 20;
		break;
	default:
		return 0;
		break;
	}
}

int Goblin::ReturnHealAmount() {
	return 3 + rand() % 10;
}

std::string Goblin::GetIntro()
{
	return "You hear cackles of laughter in the distance...";
}