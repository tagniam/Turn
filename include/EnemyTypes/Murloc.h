#ifndef MURLOC_H
#define MURLOC_H

#include "../Enemy.h"


class Murloc : public Enemy {
  public:
    Murloc();

    EnemyType GetType() override;
    std::string GetIntro() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // MURLOC_H
