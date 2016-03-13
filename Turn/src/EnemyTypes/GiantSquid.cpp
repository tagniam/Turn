#include "..\..\include\EnemyTypes\GiantSquid.h"


GiantSquid::GiantSquid(){
    name = "Giant Squid";
    ExperienceAmount = 50;
    QueensDrop = rand()%1000;
}

int GiantSquid::ReturnDamage(){
    return 7+rand()%8; // 7 - 15
}

int GiantSquid::ReturnRiskDamage(){
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

int GiantSquid::ReturnHealAmount(){
    return 5+rand()%7; // 5 -12
}
