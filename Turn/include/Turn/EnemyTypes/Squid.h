#ifndef SQUID_H
#define SQUID_H

#include "../Enemy.h"


class Squid : public Enemy {
public:
    Squid();

    EnemyType GetType() override;
	std::string GetIntro();
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // SQUID_H
