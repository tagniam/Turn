#include "../../include/Common.h"
#include "../../include/PlayerTypes/Warrior.h"

Warrior::Warrior(void) {
    SoundInfo info;
    info.attackRange = std::make_pair(1, 16);
    SetSoundInfo(info);
}

int Warrior::ReturnDamage() {
    return Common::RandomInt(0, 20);
}

int Warrior::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {0, 20};
    return Common::RandomEvent(weights, outcomes);
}

int Warrior::ReturnHealAmount() {
    return Common::RandomInt(1, 10);
}
