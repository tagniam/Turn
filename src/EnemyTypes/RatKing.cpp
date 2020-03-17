#include "../../include/EnemyTypes/RatKing.h"

RatKing::RatKing() {
    name = "Rat King";
    amountOfRats_ = 3 + rand() % 12;
    ExperienceAmount = amountOfRats_ * 15;
    CoinsDrop = amountOfRats_ * (3 + rand() % 28);
}

EnemyType RatKing::GetType() {
    return etRatKing;
}

int RatKing::ReturnDamage() {
    return amountOfRats_ * (2 + rand() % 5);
}

int RatKing::ReturnRiskAttackDamage() {
    int selector = rand() % 10;
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
    return amountOfRats_ * (3 + rand() % 15);
}

std::string RatKing::GetIntro()
{
    return "Clumsy yet scary ball of rats approaches...";
}
