#ifndef MIMIC_H
#define MIMIC_H

#include "../Enemy.h"

class Mimic : public Enemy
{
public:

    Mimic();

    EnemyType GetType() override;
    std::string GetIntro() override;

private:

    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // MIMIC_H
