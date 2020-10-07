#ifndef ZBRA_H
#define ZBRA_H

#include "../Enemy.h"


class Zabra : public Enemy
{
public:
    Zabra();

    EnemyType GetType() override;
    std::string GetIntro() override;

private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // ZBRA_H
