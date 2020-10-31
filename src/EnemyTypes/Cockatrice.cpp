#include "../../include/Common.h"
#include "../../include/EnemyTypes/Cockatrice.h"

Cockatrice::Cockatrice() {
    name = "Cockatrice";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(10, 49);
}

EnemyType Cockatrice::GetType() {
    return etCockatrice;
}

int Cockatrice::ReturnDamage() {
    return Common::RandomInt(1, 15);
}

int Cockatrice::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2, 1};
    std::vector <int> outcomes = {5, 12, 1};
    return Common::RandomEvent(weights, outcomes);
}

int Cockatrice::ReturnHealAmount() {
    return Common::RandomInt(5, 20);
}

std::string Cockatrice::GetIntro() {
    return "hiss...";
}