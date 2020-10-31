#include "../../include/Common.h"
#include "../../include/EnemyTypes/Mimic.h"

Mimic::Mimic() {
    name = "Mimic";
    ExperienceAmount = 10;
    CoinsDrop = Common::RandomInt(150, 200);
}

EnemyType Mimic::GetType() {
    return etMimic;
}

int Mimic::ReturnDamage() {
    return Common::RandomInt(3, 9);
}

int Mimic::ReturnRiskAttackDamage() {
    std::vector <int> weights = {1, 1};
    std::vector <int> outcomes = {13, 2};
    return Common::RandomEvent(weights, outcomes);
}

int Mimic::ReturnHealAmount() {
    return Common::RandomInt(2, 10);
}

std::string Mimic::GetIntro() {
    return "Is this your lucky day??";
}
