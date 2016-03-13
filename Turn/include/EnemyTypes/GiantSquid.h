#ifndef GIANTSQUID_H
#define GIANTSQUID_H

#include "Squid.h"


class GiantSquid : public Squid {
    public:
        GiantSquid();
    private:
        int ReturnDamage();
        int ReturnRiskDamage();
        int ReturnHealAmount();
};

#endif // GIANTSQUID_H
