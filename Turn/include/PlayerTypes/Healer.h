#ifndef HEALER_H
#define HEALER_H

#include "../Player.h"


class Healer : public Player {
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif // HEALER_H
