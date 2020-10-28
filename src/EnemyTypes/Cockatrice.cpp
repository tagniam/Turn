#include "../../include/Common.h"
#include "../../include/EnemyTypes/Cockatrice.h"

Cockatrice::Cockatrice() {
    name = "Cockatrice";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(10, 49);
}

EnemyType Cockatrice::GetType() {
    return etCockatrice;
}

int Cockatrice::ReturnDamage() {
    return Common::RandomInt(1, 15);
}

int Cockatrice::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 5;
        break;
    case 4:
    case 5:
        return 12;
        break;
    default:
        return 1;
        break;
    }
}

int Cockatrice::ReturnHealAmount() {
    return Common::RandomInt(5, 20);
}

std::string Cockatrice::GetIntro() {
    return "hiss...";
}