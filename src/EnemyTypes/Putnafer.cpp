#include "../../include/Common.h"
#include "../../include/EnemyTypes/Putnafer.h"

Putnafer::Putnafer() {
    name = "Putnafer";
    ExperienceAmount = 150;
    CoinsDrop = Common::RandomInt(90, 109);
}

EnemyType Putnafer::GetType() {
    return etPutnafer;
}

int Putnafer::ReturnDamage() {
    return Common::RandomInt(10, 31);
}

int Putnafer::ReturnRiskAttackDamage() {
    std::vector <int> weights = {3, 1, 2};
    std::vector <int> outcomes = {5, 1, 25};
    return Common::RandomEvent(weights, outcomes);
}

int Putnafer::ReturnHealAmount() {
    return Common::RandomInt(2, 13);
}

std::string Putnafer::GetIntro() {
    return "Terrifying doesn't describe this...";
}
