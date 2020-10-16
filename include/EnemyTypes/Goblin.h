#ifndef GOBLIN_H
#define GOBLIN_H

#include "../Enemy.h"


class Goblin : public Enemy {
  public:
    Goblin();

    EnemyType GetType() override;
    std::string GetIntro() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // GOBLIN_H
