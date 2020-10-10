#include "../../include/Common.h"
#include "../../include/EnemyTypes/GiantCrab.h"

GiantCrab::GiantCrab() {
    name = "Giant Crab";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(0, 99);
}

EnemyType GiantCrab::GetType() {
    return etGiantCrab;
}


int GiantCrab::ReturnDamage() {
    return Common::RandomInt(7, 14);
}

int GiantCrab::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch(selector){
        case 0: case 1: case 2: case 3:
            return 0;
            break;
        case 4: case 5:
            return 20;
            break;
        default:
            return 0;
            break;
    }
}

int GiantCrab::ReturnHealAmount() {
    return Common::RandomInt(5, 11);
}

std::string GiantCrab::GetIntro()
{
	return "A great claw begins to close around you...";
}
