#include "../../include/EnemyTypes/Zabra.h"

Zabra::Zabra(){
    name="Zabra";
    ExperienceAmount = 150;
    CoinsDrop = 55 + rand() % 100;
}


EnemyType Zabra::GetType(){
    return etZabra;
}

int Zabra::ReturnDamage() {
    return 6 + rand() % 20;
}

int Zabra::ReturnRiskAttackDamage() {
    int selector = rand() % 6;
	switch (selector) {
	case 0: case 1: case 2: case 3:
		return 2;
		break;
	case 4: case 5:
		return 30;
		break;
	default:
		return 0;
		break;
	}
}

int Zabra::ReturnHealAmount() {
	return 6 + rand() % 30;
}

std::string Zabra::GetIntro() {
    return std::string("Three times coraman, nobody can beat ....");
}
