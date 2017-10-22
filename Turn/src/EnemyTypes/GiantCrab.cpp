#include "../../include/EnemyTypes/GiantCrab.h"

GiantCrab::GiantCrab(){
    name = "Giant Crab";
    ExperienceAmount = 100;
    CoinsDrop = rand()%100;
}

int GiantCrab::ReturnDamage(){
    return 7+rand()%8; // 7 - 14
}

int GiantCrab::ReturnRiskAttackDamage(){
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

int GiantCrab::ReturnHealAmount(){
    return 5+rand()%7; // 5 -11
}
