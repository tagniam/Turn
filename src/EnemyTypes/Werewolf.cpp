#include "../../include/Common.h"
#include "../../include/EnemyTypes/Werewolf.h"

Werewolf::Werewolf() {
	name = "Werewolf";
	ExperienceAmount = 100;
	CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Werewolf::GetType() {
    return etWerewolf;
}

int Werewolf::ReturnDamage() {
	return Common::RandomInt(5, 24);
}

int Werewolf::ReturnRiskAttackDamage() {
	int selector = Common::RandomInt(0, 5);
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

int Werewolf::ReturnHealAmount() {
	return Common::RandomInt(4, 18);
}

std::string Werewolf::GetIntro()
{
	return "Smells like wet dog.";
}
