#ifndef TIMIDGHOST_H
#define TIMIDGHOST_H

#include "../Enemy.h"


class TimidGhost : public Enemy {
  public:
    TimidGhost();

    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // TIMIDGHOST_H
