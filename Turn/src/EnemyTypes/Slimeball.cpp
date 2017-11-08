#include "../../include/EnemyTypes/Slimeball.h"

Slimeball::Slimeball()
{
    name = "Slimeball";
    ExperienceAmount = 25;
    CoinsDrop = rand() % 50;
}

EnemyType Slimeball::GetType()
{
    return etSlimeball;
}

int Slimeball::ReturnDamage()
{
    auto acidSplash = 2;
    return 1 + acidSplash + rand() % 10;
}

int Slimeball::ReturnRiskAttackDamage()
{
    int selector = rand() % 6;
    switch(selector){
        case 0:
        case 1:
        case 2:
        case 3:
            return 2;
            break;
        case 4:
        case 5:
            return 15;
            break;
        default:
            return 0;
            break;
    }
}

int Slimeball::ReturnHealAmount()
{
    return 1 + rand() % 11;
}
