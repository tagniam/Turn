#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../Enemy.h"


class Vampire : public Enemy {
  public:
    Vampire();

    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // VAMPIRE_H
