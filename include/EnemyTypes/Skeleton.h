#ifndef SKELETON_H
#define SKELETON_H

#include "../Enemy.h"


class Skeleton : public Enemy {
  public:
    Skeleton();

    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // SKELETON_H
