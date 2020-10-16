#include "../../include/Common.h"
#include "../../include/EnemyTypes/Putnafer.h"

Putnafer::Putnafer() {
    name = "Putnafer";
    ExperienceAmount = 150;
    CoinsDrop = Common::RandomInt(90, 109);
}

EnemyType Putnafer::GetType() {
    return etPutnafer;
}

int Putnafer::ReturnDamage() {
    return Common::RandomInt(10, 31);
}

int Putnafer::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0:
    case 1:
    case 2:
        return 5;
        break;
    case 3:
        return 1;
        break;
    case 4:
    case 5:
        return 25;
        break;
    default:
        return 0;
        break;
    }
}

int Putnafer::ReturnHealAmount() {
    return Common::RandomInt(2, 13);
}

std::string Putnafer::GetIntro() {
    return "Terrifying doesn't describe this...";
}
