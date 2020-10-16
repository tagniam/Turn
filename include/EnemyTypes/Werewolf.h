#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "../Enemy.h"


class Werewolf : public Enemy {
  public:
    Werewolf();

    EnemyType GetType() override;
    std::string GetIntro() override;

  private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // WEREWOLF_H
