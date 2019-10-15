#ifndef ZBRA_H
#define ZBRA_H

#include "../Enemy.h"


class Zabra : public Enemy 
{
public:
    Zabra();

    EnemyType GetType() override;
    std::string GetIntro();
    
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // ZBRA_H
