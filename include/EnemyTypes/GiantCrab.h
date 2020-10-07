#ifndef GIANTCRAB_H
#define GIANTCRAB_H

#include "Crab.h"


class GiantCrab : public Crab {
public:
    GiantCrab();

    EnemyType GetType() override;
    std::string GetIntro() override;
private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // GIANTCRAB_H
