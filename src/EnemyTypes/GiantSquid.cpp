#include "../../include/Common.h"
#include "../../include/EnemyTypes/GiantSquid.h"

GiantSquid::GiantSquid() {
    name = "Giant Squid";
    ExperienceAmount = 50;
    CoinsDrop = Common::RandomInt(0, 99);
}

EnemyType GiantSquid::GetType() {
    return etGiantSquid;
}

int GiantSquid::ReturnDamage() {
    return Common::RandomInt(7, 14);
}

int GiantSquid::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {0, 20};
    return Common::RandomEvent(weights, outcomes);
}

int GiantSquid::ReturnHealAmount() {
    return Common::RandomInt(5, 11);
}

std::string GiantSquid::GetIntro() {
    return "With a thunderous splash...";
}
