#include "../../include/Common.h"
#include "../../include/EnemyTypes/Goblin.h"

Goblin::Goblin() {
    name = "Goblin";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Goblin::GetType() {
    return etGoblin;
}

int Goblin::ReturnDamage() {
    return Common::RandomInt(5, 24);
}

int Goblin::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 20};
    return Common::RandomEvent(weights, outcomes);
}

int Goblin::ReturnHealAmount() {
    return Common::RandomInt(3, 12);
}

std::string Goblin::GetIntro() {
    return "You hear cackles of laughter in the distance...";
}
