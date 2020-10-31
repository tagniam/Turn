#include "../../include/Common.h"
#include "../../include/PlayerTypes/Rogue.h"

Rogue::Rogue(void) {
    SoundInfo info;
    info.attackRange = std::make_pair(1, 11);
    SetSoundInfo(info);
}

int Rogue::ReturnDamage() {
    return Common::RandomInt(7, 12);
}

int Rogue::ReturnRiskAttackDamage() {
    std::vector <int> weights = {1, 1};
    std::vector <int> outcomes = {1, 10};
    return Common::RandomEvent(weights, outcomes);
}

int Rogue::ReturnHealAmount() {
    return Common::RandomInt(6, 12);
}
