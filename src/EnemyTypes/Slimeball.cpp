#include "../../include/Common.h"
#include "../../include/EnemyTypes/Slimeball.h"

Slimeball::Slimeball() {
    name = "Slimeball";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(0, 49);
}

EnemyType Slimeball::GetType() {
    return etSlimeball;
}

int Slimeball::ReturnDamage() {
    auto acidSplash = 2;
    return 1 + acidSplash + Common::RandomInt(0, 9);
}

std::string Slimeball::GetIntro() {
    return "Gurgle, gurgle, glub, glub...";
}

int Slimeball::ReturnRiskAttackDamage() {
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

int Slimeball::ReturnHealAmount() {
    return Common::RandomInt(1, 11);
}
