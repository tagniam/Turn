#include "../../include/Common.h"
#include "../../include/EnemyTypes/Zabra.h"

Zabra::Zabra(){
    name="Zabra";
    ExperienceAmount = 150;
    CoinsDrop = Common::RandomInt(55, 154);
}


EnemyType Zabra::GetType(){
    return etZabra;
}

int Zabra::ReturnDamage() {
    return Common::RandomInt(6, 25);
}

int Zabra::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
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
	return Common::RandomInt(6, 35);
}

std::string Zabra::GetIntro() {
    return std::string("Three times coraman, nobody can beat ....");
}
