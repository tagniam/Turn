#ifndef GIANTSQUID_H
#define GIANTSQUID_H

#include "Squid.h"


class GiantSquid : public Squid {
  public:
    GiantSquid();

    EnemyType GetType() override;
    std::string GetIntro() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // GIANTSQUID_H
