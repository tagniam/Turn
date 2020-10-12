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
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 2;
        break;
    case 4:
    case 5:
        return 12;
        break;
    default:
        return 0;
        break;
    }
}

int Murloc::ReturnHealAmount() {
    return Common::RandomInt(5, 39);
}

std::string Murloc::GetIntro() {
    return "The sound of wet footsteps approaches...";
}
