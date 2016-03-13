#include "..\..\include\PlayerTypes\Healer.h"


int Healer::ReturnDamage(){
    return 5+rand()%6; // 5 - 10
}

int Healer::ReturnRiskAttackDamage(){
    int selector = rand()%2;
    switch(selector){
        case 0:
            return 5;
            break;
        case 1:
            return 10;
            break;
        default:
            return 0;
            break;
    }
}

int Healer::ReturnHealAmount(){
    return 7+rand()%9; // 7 - 15
}
