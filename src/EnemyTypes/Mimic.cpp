#include "../../include/Common.h"
#include "../../include/EnemyTypes/Mimic.h"

Mimic::Mimic()
{
    name = "Mimic";
    ExperienceAmount = 10;
    CoinsDrop = Common::RandomInt(150, 200);
}

EnemyType Mimic::GetType()
{
    return etMimic;
}

int Mimic::ReturnDamage()
{
    return Common::RandomInt(3, 9);
}

int Mimic::ReturnRiskAttackDamage()
{
    int selector = Common::RandomInt(0, 1);
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
    return Common::RandomInt(2, 10);
}

std::string Mimic::GetIntro()
{
	return "Is this your lucky day??";
}
