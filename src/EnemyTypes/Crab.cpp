#include "../../include/Common.h"
#include "../../include/EnemyTypes/Crab.h"

Crab::Crab() {
    name = "Crab";
    ExperienceAmount = 20;
    CoinsDrop = Common::RandomInt(0, 49);
}

EnemyType Crab::GetType() {
    return etCrab;
}

int Crab::ReturnDamage() {
    return Common::RandomInt(1, 10);
}

int Crab::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch(selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 2;
        break;
    case 4:
    case 5:
        return 15;
        break;
    default:
        return 0;
        break;
    }
}

int Crab::ReturnHealAmount() {
    return Common::RandomInt(1, 11);
}

std::string Crab::GetIntro() {
    return "A small shape scuttles from the shadows...";
}
