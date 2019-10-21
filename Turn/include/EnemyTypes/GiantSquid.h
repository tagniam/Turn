#ifndef GIANTSQUID_H
#define GIANTSQUID_H

#include "Squid.h"


class GiantSquid : public Squid {
public:
    GiantSquid();

    EnemyType GetType() override;
    std::string GetIntro();
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // GIANTSQUID_H
