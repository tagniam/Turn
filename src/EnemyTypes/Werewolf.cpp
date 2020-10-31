#include "../../include/Common.h"
#include "../../include/EnemyTypes/Werewolf.h"

Werewolf::Werewolf() {
    name = "Werewolf";
    ExperienceAmount = 100;
    CoinsDrop = Common::RandomInt(50, 149);
}

EnemyType Werewolf::GetType() {
    return etWerewolf;
}

int Werewolf::ReturnDamage() {
    return Common::RandomInt(5, 24);
}

int Werewolf::ReturnRiskAttackDamage() {
    std::vector <int> weights = {4, 2};
    std::vector <int> outcomes = {2, 20};
    return Common::RandomEvent(weights, outcomes);
}

int Werewolf::ReturnHealAmount() {
    return Common::RandomInt(4, 18);
}

std::string Werewolf::GetIntro() {
    return "Smells like wet dog.";
}
