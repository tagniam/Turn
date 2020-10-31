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
    std::vector <int> weights = {6, 3, 1, 1};
    std::vector <int> outcomes = {0, amountOfRats_ * 7,
                                amountOfRats_ * 5, amountOfRats_ * 10};
    return Common::RandomEvent(weights, outcomes);
}

int RatKing::ReturnHealAmount() {
    return amountOfRats_ * Common::RandomInt(3, 17);
}

std::string RatKing::GetIntro() {
    return "Clumsy yet scary ball of rats approaches...";
}
