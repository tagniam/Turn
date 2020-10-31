#include "../../include/Common.h"
#include "../../include/EnemyTypes/Vampire.h"

Vampire::Vampire() {
    name = "Vampire";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Vampire::GetType() {
    return etVampire;
}

int Vampire::ReturnDamage() {
    return Common::RandomInt(5, 24);
}

int Vampire::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 25};
    return Common::RandomEvent(weights, outcomes);
}

int Vampire::ReturnHealAmount() {
    return Common::RandomInt(8, 22);
}

std::string Vampire::GetIntro() {
    return "A dark presence...";
}
