#ifndef RAT_H
#define RAT_H

#include "..\Enemy.h"

class Rat : public enemy {
    public: 
        Rat();
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif  // RAT_H