#ifndef CRAB_H
#define CRAB_H

#include "../Enemy.h"


class Crab : public Enemy {
public:
    Crab();

    EnemyType GetType() override;
    std::string GetIntro() override;
private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // CRAB_H
