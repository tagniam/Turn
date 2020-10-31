#include "../../include/Common.h"
#include "../../include/EnemyTypes/SmallDragon.h"

SmallDragon::SmallDragon() {
    name = "Small Dragon";
    ExperienceAmount = 135;
    CoinsDrop = Common::RandomInt(50, 79);
}

EnemyType SmallDragon::GetType() {
    return etSmallDragon;
}

int SmallDragon::ReturnDamage() {
    return Common::RandomInt(15, 29);
}

int SmallDragon::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {5, 30};
    return Common::RandomEvent(weights, outcomes);
}

int SmallDragon::ReturnHealAmount() {
    return Common::RandomInt(15, 24);
}

std::string SmallDragon::GetIntro() {
    return "You hope there isn't a bigger version of this monster...";
}
