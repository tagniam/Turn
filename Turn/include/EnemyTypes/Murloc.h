#ifndef MURLOC_H
#define MURLOC_H

#include "../Enemy.h"


class Murloc : public Enemy 
{
public:
    Murloc();

    EnemyType GetType() override;
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // MURLOC_H
