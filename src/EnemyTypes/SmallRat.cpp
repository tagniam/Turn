#include "../../include/Common.h"
#include "../../include/EnemyTypes/SmallRat.h"

SmallRat::SmallRat() {
    name = "Small Rat";
    ExperienceAmount = 15;
    CoinsDrop = Common::RandomInt(3, 30);
}

EnemyType SmallRat::GetType() {
    return etSmallRat;
}

int SmallRat::ReturnDamage() {
    return Common::RandomInt(2, 6);
}

int SmallRat::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 5, 1, 1};
    std::vector <int> outcomes = {0, 2, 5, 10};
    return Common::RandomEvent(weights, outcomes);
}

int SmallRat::ReturnHealAmount() {
    return Common::RandomInt(3, 17);
}

std::string SmallRat::GetIntro() {
    return "Little feet tripping over the floor...";
}
