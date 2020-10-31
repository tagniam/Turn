#ifndef DRAGON_H
#define DRAGON_H

#include "../Enemy.h"


class Dragon : public Enemy {
  public:
    Dragon();

    EnemyType GetType() override;
    std::string GetIntro();

  private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // DRAGON_H
