#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Enemy.h"


class Zombie : public Enemy
{
public:
	Zombie();

    EnemyType GetType() override;
	std::string GetIntro() override;

private:
	int ReturnDamage() override;
	int ReturnRiskAttackDamage() override;
	int ReturnHealAmount() override;
};

#endif // ZOMBIE_H
