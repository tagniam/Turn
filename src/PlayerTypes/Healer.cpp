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
    int selector = Common::RandomInt(0, 1);
    switch(selector) {
    case 0:
        return 5;
        break;
    case 1:
        return 10;
        break;
    default:
        return 0;
        break;
    }
}

int Healer::ReturnHealAmount() {
    return Common::RandomInt(7, 15);
}
