#include "../../include/Common.h"
#include "../../include/EnemyTypes/Dragon.h"

Dragon::Dragon() {
    name = "Dragon";
    ExperienceAmount = 270;
    CoinsDrop = Common::RandomInt(100, 158);
}

EnemyType Dragon::GetType() {
    return etDragon;
}

int Dragon::ReturnDamage() {
    return Common::RandomInt(30, 58);
}

int Dragon::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 10;
        break;
    case 4:
    case 5:
        return 60;
        break;
    default:
        return 0;
        break;
    }
}

int Dragon::ReturnHealAmount() {
    return Common::RandomInt(30, 48);
}

std::string Dragon::GetIntro() {
    return "Your biggest nightmare comes true a bigger version of small dragon comes...";
}
