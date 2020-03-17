#include "../../include/EnemyTypes/Demon.h"

Demon::Demon() {
    name = "Demon";
    ExperienceAmount = 25;
    CoinsDrop = rand() % 35;
}

EnemyType Demon::GetType() {
    return etDemon;
}

int Demon::ReturnDamage() {
    return 5 + rand() % 12; //5-16
}

int Demon::ReturnRiskAttackDamage() {
    int selector = rand() % 6;
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
    return 1 + rand() % 15;
}

std::string Demon::GetIntro()
{
    return "A hellish roar is heard. . . ";
}
