#ifndef GARGOYLE_H
#define GARGOYLE_H

#include "../Enemy.h"


class Gargoyle : public Enemy {
  public:
    Gargoyle();

    EnemyType GetType() override;
    std::string GetIntro() override;
  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // GARGOYLE_H
