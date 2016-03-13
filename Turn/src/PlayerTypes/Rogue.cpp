#include "..\..\include\PlayerTypes\Rogue.h"


int Rogue::ReturnDamage(){
    return 7+rand()%6; // 7 - 12
}

int Rogue::ReturnRiskAttackDamage(){
    int selector = rand()%2;
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
    return 6+rand()%7; // 6 - 12
}
