#ifndef SMALLDRAGON_H
#define SMALLDRAGON_H

#include "../Enemy.h"


class SmallDragon : public Enemy {
  public:
    SmallDragon();

    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // SMALLDRAGON_H
