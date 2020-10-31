#include "../../include/Common.h"
#include "../../include/EnemyTypes/Zombie.h"

Zombie::Zombie() {
    name = "Zombie";
    ExperienceAmount = 90;
    CoinsDrop = Common::RandomInt(40, 64);
}

EnemyType Zombie::GetType() {
    return etZombie;
}

int Zombie::ReturnDamage() {
    return Common::RandomInt(20, 29);
}

int Zombie::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 3};
    std::vector <int> outcomes = {2, 30};
    return Common::RandomEvent(weights, outcomes);
}

int Zombie::ReturnHealAmount() {
    return Common::RandomInt(2, 41);
}

std::string Zombie::GetIntro() {
    return "\"Brains,\" it moans...";
}
