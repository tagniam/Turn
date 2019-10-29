#include "../../include/EnemyTypes/TimidGhost.h"

TimidGhost::TimidGhost() {
	name = "Timid Ghost";
	ExperienceAmount = 10 + rand() % 10;
	CoinsDrop = 1 + rand() % 5;
}

EnemyType TimidGhost::GetType() {
	return etTimidGhost;
}

int TimidGhost::ReturnDamage() {
	int damage = rand() % 3;
	int chance = rand() % 2; // 50% chance
	if (chance == 0) {
		// TimidGhost musters courage
		damage += 5;
	}
	return damage;
}

int TimidGhost::ReturnRiskAttackDamage() {
	int chance = rand() % 5;
	if (chance == 0) {
		return 10; // 20% chance
	}
	else {
		return 0;
	}
}

int TimidGhost::ReturnHealAmount() {
	return 2;
}

std::string TimidGhost::GetIntro() {
	int choice = rand() % 2;
	if (choice == 0) {
		return "The room is brightly lit from all sides, but a shadow creeps up behind you...";
	}
	else {
		return "It approaches you slowly, as if mustering courage...";
	}
}