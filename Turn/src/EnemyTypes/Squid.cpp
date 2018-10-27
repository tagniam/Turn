#include "Turn/EnemyTypes/Squid.h"

Squid::Squid() {
    name = "Squid";
    ExperienceAmount = 20;
    CoinsDrop = rand()%50;
}

EnemyType Squid::GetType() {
    return etSquid;
}

int Squid::ReturnDamage() {
    return 1+rand()%10;
}

int Squid::ReturnRiskAttackDamage() {
    int selector= rand()%6;
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
    return 1+rand()%11;
}

std::string Squid::GetIntro()
{
	return "Because two arms attacking you just wasn't enough.";
}
