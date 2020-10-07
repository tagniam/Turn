#ifndef SQUID_H
#define SQUID_H

#include "../Enemy.h"


class Squid : public Enemy {
public:
    Squid();

    EnemyType GetType() override;
	std::string GetIntro() override;
private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // SQUID_H
