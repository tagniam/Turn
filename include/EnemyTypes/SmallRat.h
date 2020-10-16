#ifndef SMALLRAT_H
#define SMALLRAT_H

#include "../Enemy.h"


class SmallRat : public Enemy {
  public:
    SmallRat();

    EnemyType GetType() override;
    std::string GetIntro() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // SMALLRAT_H
