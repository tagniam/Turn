#include "../../include/Common.h"
#include "../../include/PlayerTypes/Healer.h"

Healer::Healer(void) {
    SoundInfo info;
    info.attackRange = std::make_pair(1, 9);
    SetSoundInfo(info);
}

int Healer::ReturnDamage() {
    return Common::RandomInt(5, 10);
}

int Healer::ReturnRiskAttackDamage() {
    std::vector <int> weights = {1, 1};
    std::vector <int> outcomes = {5, 10};
    return Common::RandomEvent(weights, outcomes);
}

int Healer::ReturnHealAmount() {
    return Common::RandomInt(7, 15);
}
