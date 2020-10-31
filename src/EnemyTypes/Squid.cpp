#include "../../include/Common.h"
#include "../../include/EnemyTypes/Squid.h"

Squid::Squid() {
    name = "Squid";
    ExperienceAmount = 20;
    CoinsDrop = Common::RandomInt(0, 49);
}

EnemyType Squid::GetType() {
    return etSquid;
}

int Squid::ReturnDamage() {
    return Common::RandomInt(1, 10);
}

int Squid::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 15};
    return Common::RandomEvent(weights, outcomes);
}

int Squid::ReturnHealAmount() {
    return Common::RandomInt(1, 11);
}

std::string Squid::GetIntro() {
    return "Because two arms attacking you just wasn't enough.";
}
