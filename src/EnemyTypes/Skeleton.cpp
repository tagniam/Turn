#include "../../include/Common.h"
#include "../../include/EnemyTypes/Skeleton.h"

Skeleton::Skeleton() {
    name = "Skeleton";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(3, 50);
}

EnemyType Skeleton::GetType() {
    return etSkeleton;
}

int Skeleton::ReturnDamage() {
    return Common::RandomInt(3, 7);
}

int Skeleton::ReturnRiskAttackDamage() {
    std::vector <int> weights = {1, 3, 5, 1, 1};
    std::vector <int> outcomes = {0, 1, 3, 5, 20};
    return Common::RandomEvent(weights, outcomes);
}

int Skeleton::ReturnHealAmount() {
    return Common::RandomInt(1, 15);
}

std::string Skeleton::GetIntro() {
    return "Clack, clack, clack...";
}
