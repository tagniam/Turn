#include "../../include/Common.h"
#include "../../include/EnemyTypes/Cerberus.h"

Cerberus::Cerberus() {
    name = "Cerberus";
    ExperienceAmount = 120;
    CoinsDrop = Common::RandomInt(40, 60);
}

EnemyType Cerberus::GetType() {
    return etCerberus;
}

int Cerberus::ReturnDamage() {
    return Common::RandomInt(15, 25);
}

int Cerberus::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2, 1};
    std::vector <int> outcomes = {2, 25, 30};
    return Common::RandomEvent(weights, outcomes);
}

int Cerberus::ReturnHealAmount() {
    return Common::RandomInt(5, 10);
}


std::string Cerberus::GetIntro() {
    return "Something is growling behind you...";
}
