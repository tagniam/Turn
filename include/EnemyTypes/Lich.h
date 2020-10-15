#ifndef LICH_H
#define LICH_H

#include "../Enemy.h"


class Lich : public Enemy {
  public:
    Lich();

    EnemyType GetType() override;
    std::string GetIntro() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // LICH_H
