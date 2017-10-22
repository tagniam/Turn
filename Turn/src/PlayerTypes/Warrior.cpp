#include "../../include/PlayerTypes/Warrior.h"

int Warrior::ReturnDamage(){
    return rand()%21;
}

int Warrior::ReturnRiskAttackDamage(){
    int selector = rand()%6;
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
    return 1+rand()%10; // 1 - 10
}
