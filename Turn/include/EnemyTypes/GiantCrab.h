#ifndef GIANTCRAB_H
#define GIANTCRAB_H

#include "Crab.h"


class GiantCrab : public Crab {
    public:
        GiantCrab();
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif // GIANTCRAB_H
