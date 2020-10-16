#include "../../include/Common.h"
#include "../../include/EnemyTypes/GiantSquid.h"

GiantSquid::GiantSquid() {
    name = "Giant Squid";
    ExperienceAmount = 50;
    CoinsDrop = Common::RandomInt(0, 99);
}

EnemyType GiantSquid::GetType() {
    return etGiantSquid;
}

int GiantSquid::ReturnDamage() {
    return Common::RandomInt(7, 14);
}

int GiantSquid::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch(selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 0;
        break;
    case 4:
    case 5:
        return 20;
        break;
    default:
        return 0;
        break;
    }
}

int GiantSquid::ReturnHealAmount() {
    return Common::RandomInt(5, 11);
}

std::string GiantSquid::GetIntro() {
    return "With a thunderous splash...";
}
