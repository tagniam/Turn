#include "../../include/EnemyTypes/Mimic.h"

Mimic::Mimic()
{
    name = "Mimic";
    ExperienceAmount = 10;
    CoinsDrop = 150 + rand() % 51;
}

EnemyType Mimic::GetType()
{
    return etMimic;
}

int Mimic::ReturnDamage()
{
    return 3 + rand() % 7;
}

int Mimic::ReturnRiskAttackDamage()
{
    int selector = rand() % 2;
    switch (selector)
    {
    case 0:
        return 13;
        break;
    case 1:
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

int Mimic::ReturnHealAmount() 
{
    return 2 + rand() % 9;
}

std::string Mimic::GetIntro()
{
	return "Is this your lucky day??";
}
