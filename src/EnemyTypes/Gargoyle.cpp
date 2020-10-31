#include "../../include/Common.h"
#include "../../include/EnemyTypes/Gargoyle.h"

Gargoyle::Gargoyle() {
    name = "Gargoyle";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Gargoyle::GetType() {
    return etGargoyle;
}

int Gargoyle::ReturnDamage() {
    return Common::RandomInt(5, 24);
}

int Gargoyle::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 25};
    return Common::RandomEvent(weights, outcomes);
    }
}

int Gargoyle::ReturnHealAmount() {
    return Common::RandomInt(6, 20);
}

std::string Gargoyle::GetIntro() {
    return "A silhouette of wings and horns swoops towards you...";
}
