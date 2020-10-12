#include "../../include/Common.h"
#include "../../include/PlayerTypes/Warrior.h"

Warrior::Warrior(void)
{
	SoundInfo info;
	info.attackRange = std::make_pair(1, 16);
	SetSoundInfo(info);
}

int Warrior::ReturnDamage(){
    return Common::RandomInt(0, 20);
}

int Warrior::ReturnRiskAttackDamage(){
    int selector = Common::RandomInt(0, 5);
    switch(selector){
        case 0: case 1: case 2: case 3:
            return 0;
            break;
        case 4: case 5:
            return 20;
            break;
        default:
            return 0;
            break;
    }
}

int Warrior::ReturnHealAmount(){
    return Common::RandomInt(1, 10);
}
