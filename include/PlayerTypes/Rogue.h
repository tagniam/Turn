#ifndef ROGUE_H
#define ROGUE_H

#include "../Player.h"


class Rogue : public Player {
  public:
    Rogue(void);
  private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // ROGUE_H
