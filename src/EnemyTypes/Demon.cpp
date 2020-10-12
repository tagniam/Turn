#include "../../include/Common.h"
#include "../../include/EnemyTypes/Demon.h"

Demon::Demon() {
    name = "Demon";
    ExperienceAmount = 25;
    CoinsDrop = Common::RandomInt(0, 34);
}

EnemyType Demon::GetType() {
    return etDemon;
}

int Demon::ReturnDamage() {
    return Common::RandomInt(5, 16);
}

int Demon::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0: case 1: case 2: case 3: case 4:
        return 1;
        break;
     case 5:
        return 25;
        break;
    default:
        return 0;
        break;
    }
}

int Demon::ReturnHealAmount() {
    return Common::RandomInt(1, 15);
}

std::string Demon::GetIntro()
{
    return "A hellish roar is heard. . . ";
}
