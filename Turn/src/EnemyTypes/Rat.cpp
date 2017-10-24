#include "..\..\include\EnemyTypes\Rat.h"

Rat::Rat(){
    name = "Rat";
    ExperienceAmount = 5;
    CoinsDrop = 1 + rand()%9;
}

int Rat::ReturnDamage(){
    return rand()%5;
}

int Rat::ReturnRiskAttackDamage(){
    int selector = rand()%6;
    switch(selector){
        case 0; case 1: case 2: case 3:
            return 1;
            break;
        case 4: case 5: 
            return 7;
            break;
        default:
            return 0;
            break;
    }    
}

int Rat::ReturnHealAmount(){
    return rand()%6;
}