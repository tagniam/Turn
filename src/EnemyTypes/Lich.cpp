#include "../../include/Common.h"
#include "../../include/EnemyTypes/Lich.h"

Lich::Lich() {
    name = "Lich";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Lich::GetType() {
    return etLich;
}

int Lich::ReturnDamage() {
    return Common::RandomInt(5, 24);
}

int Lich::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 30};
    return Common::RandomEvent(weights, outcomes);
}

int Lich::ReturnHealAmount() {
    return Common::RandomInt(5, 29);
}

std::string Lich::GetIntro() {
    return "A cold chill enters the room...";
}
