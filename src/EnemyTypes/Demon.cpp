#include "../../include/Common.h"
#include "../../include/EnemyTypes/Demon.h"

Demon::Demon() {
    name = "Demon";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(0, 34);
}

EnemyType Demon::GetType() {
    return etDemon;
}

int Demon::ReturnDamage() {
    return Common::RandomInt(5, 16);
}

int Demon::ReturnRiskAttackDamage() {
    std::vector <int> weights = {5, 1, 1};
    std::vector <int> outcomes = {1, 25, 0};
    return Common::RandomEvent(weights, outcomes);
}

int Demon::ReturnHealAmount() {
    return Common::RandomInt(1, 15);
}

std::string Demon::GetIntro() {
    return "A hellish roar is heard. . . ";
}
