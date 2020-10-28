#ifndef COCKATRICE_H
#define COCKATRICE_H

#include "../Enemy.h"


class Cockatrice : public Enemy {
  public:
    Cockatrice();
    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // COCKATRICE_H