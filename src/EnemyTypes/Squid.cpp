#include "../../include/Common.h"
#include "../../include/EnemyTypes/Squid.h"

Squid::Squid() {
    name = "Squid";
    ExperienceAmount = 20;
    CoinsDrop = Common::RandomInt(0, 49);
}

EnemyType Squid::GetType() {
    return etSquid;
}

int Squid::ReturnDamage() {
    return Common::RandomInt(1, 10);
}

int Squid::ReturnRiskAttackDamage() {
    int selector= Common::RandomInt(0, 5);
    switch(selector){
        case 0: case 1: case 2: case 3:
            return 2;
            break;
        case 4: case 5:
            return 15;
            break;
        default:
            return 0;
            break;
    }
}

int Squid::ReturnHealAmount() {
    return Common::RandomInt(1, 11);
}

std::string Squid::GetIntro()
{
	return "Because two arms attacking you just wasn't enough.";
}
