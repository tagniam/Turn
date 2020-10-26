#ifndef WIZARD_H
#define WIZARD_H

#include "../Enemy.h"


class Wizard : public Enemy {
  public:
    Wizard();
    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // WIZARD_H
