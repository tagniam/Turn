#include "../../include/Common.h"
#include "../../include/EnemyTypes/Zabra.h"

Zabra::Zabra() {
    name="Zabra";
    ExperienceAmount = 150;
    CoinsDrop = Common::RandomInt(55, 154);
}


EnemyType Zabra::GetType() {
    return etZabra;
}

int Zabra::ReturnDamage() {
    return Common::RandomInt(6, 25);
}

int Zabra::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 30};
    return Common::RandomEvent(weights, outcomes);
}

int Zabra::ReturnHealAmount() {
    return Common::RandomInt(6, 35);
}

std::string Zabra::GetIntro() {
    return std::string("Three times coraman, nobody can beat ....");
}
