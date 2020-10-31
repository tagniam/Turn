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
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {0, 20};
    return Common::RandomEvent(weights, outcomes);
}

int GiantCrab::ReturnHealAmount() {
    return Common::RandomInt(5, 11);
}

std::string GiantCrab::GetIntro() {
    return "A great claw begins to close around you...";
}
