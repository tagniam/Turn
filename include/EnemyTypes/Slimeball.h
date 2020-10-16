#ifndef SLIMEBALL_H
#define SLIMEBALL_H

#include "../Enemy.h"

class Slimeball : public Enemy {
  public:
    Slimeball();
    std::string GetIntro() override;
    EnemyType GetType() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // SLIMEBALL_H
