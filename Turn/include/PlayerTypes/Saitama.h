#ifndef SAITAMA_H
#define SAITAMA_H

#include "..\Player.h"


class Saitama : public Player
{
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif // SAITAMA_H
