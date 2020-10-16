#ifndef CERBERUS_H
#define CERBERUS_H

#include "../Enemy.h"


class Cerberus : public Enemy {
  public:
    Cerberus();

    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // CERBERUS_H
