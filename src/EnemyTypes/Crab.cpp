#include "../../include/Common.h"
#include "../../include/EnemyTypes/Crab.h"

Crab::Crab() {
    name = "Crab";
    ExperienceAmount = 20;
    CoinsDrop = Common::RandomInt(0, 49);
}

EnemyType Crab::GetType() {
    return etCrab;
}

int Crab::ReturnDamage() {
    return Common::RandomInt(1, 10);
}

int Crab::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2, 1};
    std::vector <int> outcomes = {2, 15, 0};
    return Common::RandomEvent(weights, outcomes);
}

int Crab::ReturnHealAmount() {
    return Common::RandomInt(1, 11);
}

std::string Crab::GetIntro() {
    return "A small shape scuttles from the shadows...";
}
