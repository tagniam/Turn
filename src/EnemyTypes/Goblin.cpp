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
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 2;
        break;
    case 4:
    case 5:
        return 20;
        break;
    default:
        return 0;
        break;
    }
}

int Goblin::ReturnHealAmount() {
    return Common::RandomInt(3, 12);
}

std::string Goblin::GetIntro() {
    return "You hear cackles of laughter in the distance...";
}
