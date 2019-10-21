#ifndef CRAB_H
#define CRAB_H

#include "../Enemy.h"


class Crab : public Enemy {
public:
    Crab();

    EnemyType GetType() override;
    std::string GetIntro();
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // CRAB_H
