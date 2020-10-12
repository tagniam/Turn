#include "../../include/Common.h"
#include "../../include/PlayerTypes/Rogue.h"

Rogue::Rogue(void)
{
	SoundInfo info;
	info.attackRange = std::make_pair(1, 11);
	SetSoundInfo(info);
}

int Rogue::ReturnDamage(){
    return Common::RandomInt(7, 12);
}

int Rogue::ReturnRiskAttackDamage(){
    int selector = Common::RandomInt(0, 1);
    switch(selector){
        case 0:
            return 1;
            break;
        case 1:
            return 10;
            break;
        default:
            return 0;
            break;
    }
}

int Rogue::ReturnHealAmount(){
    return Common::RandomInt(6, 12);
}
