#ifndef LICH_H
#define LICH_H

#include "..\Enemy.h"


class Lich : public Enemy 
{
public:
    Lich();

    EnemyType GetType() override;
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // LICH_H
