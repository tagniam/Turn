#include "../../include/Common.h"
#include "../../include/EnemyTypes/Lich.h"

Lich::Lich() {
    name = "Lich";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Lich::GetType() {
    return etLich;
}

int Lich::ReturnDamage() {
    return Common::RandomInt(5, 24);
}

int Lich::ReturnRiskAttackDamage() {
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
        return 30;
        break;
    default:
        return 0;
        break;
    }
}

int Lich::ReturnHealAmount() {
    return Common::RandomInt(5, 29);
}

std::string Lich::GetIntro() {
    return "A cold chill enters the room...";
}
