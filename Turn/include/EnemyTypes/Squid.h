#ifndef SQUID_H
#define SQUID_H

#include "..\Enemy.h"


class Squid : public Enemy {
    public:
        Squid();
    private:
        int ReturnDamage();
        int ReturnRiskDamage();
        int ReturnHealAmount();
};

#endif // SQUID_H
