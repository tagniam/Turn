#ifndef DEBUGGER_H
#define DEBUGGER_H

#include "../Player.h"


class Debugger : public Player {
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif // DEBUGGER_H
