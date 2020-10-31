#include "../../include/Common.h"
#include "../../include/EnemyTypes/Slimeball.h"

Slimeball::Slimeball() {
    name = "Slimeball";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(0, 49);
}

EnemyType Slimeball::GetType() {
    return etSlimeball;
}

int Slimeball::ReturnDamage() {
    auto acidSplash = 2;
    return 1 + acidSplash + Common::RandomInt(0, 9);
}

std::string Slimeball::GetIntro() {
    return "Gurgle, gurgle, glub, glub...";
}

int Slimeball::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 15};
    return Common::RandomEvent(weights, outcomes);
}

int Slimeball::ReturnHealAmount() {
    return Common::RandomInt(1, 11);
}
