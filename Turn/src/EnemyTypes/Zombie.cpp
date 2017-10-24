#include "..\..\include\EnemyTypes\Zombie.h"

Zombie::Zombie() {
	name = "Zombie";
	ExperienceAmount = 90;
	CoinsDrop = 40 + rand() % 25;
}

EnemyType Zombie::GetType() {
    return etZombie;
}

int Zombie::ReturnDamage() {
	return 20 + rand() % 10;
}

int Zombie::ReturnRiskAttackDamage() {
	int selector = rand() % 7;
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
	return 2 + rand() % 40;
}
