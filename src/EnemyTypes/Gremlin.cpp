#include "../../include/Common.h"
#include "../../include/EnemyTypes/Gremlin.h"

Gremlin::Gremlin() {
    name = "Gremlin";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(0, 39);
}

EnemyType Gremlin::GetType() {
    return etGremlin;
}

std::string Gremlin::GetIntro() {
    return "Hihihihihi, want some fun ?";
}



int Gremlin::ReturnDamage() {
    return Common::RandomInt(5, 9);
}

int Gremlin::ReturnHealAmount() {
    return Common::RandomInt(3, 10);
}


// similar to rolling a d20  : 0 is equal to rolling a d20 in D&D 1, 19 is equal to rolling a 20
int Gremlin::ReturnRiskAttackDamage() {
    std::vector <int> weights = {1, 9, 1, 8, 1};
    std::vector <int> outcomes = {0, 2, Common::RandomInt(5,9), 
                                Common::RandomInt(8, 12), 20};
    return Common::RandomEvent(weights, outcomes);
}