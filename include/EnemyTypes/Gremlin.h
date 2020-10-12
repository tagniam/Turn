#ifndef GREMLIN_H
#define GREMLIN_H

#include "../Enemy.h"


class Gremlin : public Enemy {
  public:
    Gremlin();
    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // GREMLIN_H
