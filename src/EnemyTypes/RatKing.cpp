#include "../../include/Common.h"
#include "../../include/EnemyTypes/RatKing.h"

RatKing::RatKing() {
    name = "Rat King";
    amountOfRats_ = Common::RandomInt(3, 14);
    ExperienceAmount = amountOfRats_ * 15;
    CoinsDrop = amountOfRats_ * Common::RandomInt(3, 30);
}

EnemyType RatKing::GetType() {
    return etRatKing;
}

int RatKing::ReturnDamage() {
    return amountOfRats_ * Common::RandomInt(2, 6);
}

int RatKing::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 9);
    switch (selector){
    case 0: case 1: case 2: case 3: case 4: case 5:
        return 0;
        break;
     case 6: case 7: case 8:
        return amountOfRats_ * 7;
        break;
    case 9:
        return amountOfRats_ * 5;
        break;
    case 10:
        return amountOfRats_ * 10;
        break;
    default:
        return 0;
        break;
    }
}

int RatKing::ReturnHealAmount() {
    return amountOfRats_ * Common::RandomInt(3, 17);
}

std::string RatKing::GetIntro()
{
    return "Clumsy yet scary ball of rats approaches...";
}
