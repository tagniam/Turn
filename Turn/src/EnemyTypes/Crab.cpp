#include "../../include/EnemyTypes/Crab.h"

Crab::Crab() {
    name = "Crab";
    ExperienceAmount = 20;
    CoinsDrop = rand()%50;
}

EnemyType Crab::GetType() {
    return etCrab;
}

int Crab::ReturnDamage() {
    return 1+rand()%10;
}

int Crab::ReturnRiskAttackDamage() {
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

int Crab::ReturnHealAmount() {
    return 1+rand()%11;
}
