#ifndef ROGUE_H
#define ROGUE_H

#include "..\Player.h"


class Rogue : public Player {
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif // ROGUE_H
