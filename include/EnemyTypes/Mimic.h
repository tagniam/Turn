#ifndef MIMIC_H
#define MIMIC_H

#include "../Enemy.h"

class Mimic : public Enemy
{
public:

    Mimic();

    EnemyType GetType() override;
    std::string GetIntro();

private:

    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // MIMIC_H
