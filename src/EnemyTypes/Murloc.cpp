#include "../../include/Common.h"
#include "../../include/EnemyTypes/Murloc.h"

Murloc::Murloc() {
    name = "Murloc";
    ExperienceAmount = 35;
    CoinsDrop = Common::RandomInt(0, 39);
}

EnemyType Murloc::GetType() {
    return etMurloc;
}

int Murloc::ReturnDamage() {
    return Common::RandomInt(5, 9);
}

int Murloc::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 12};
    return Common::RandomEvent(weights, outcomes);
}

int Murloc::ReturnHealAmount() {
    return Common::RandomInt(5, 39);
}

std::string Murloc::GetIntro() {
    return "The sound of wet footsteps approaches...";
}
