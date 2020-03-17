#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Enemy.h"


class Zombie : public Enemy 
{
public:
	Zombie();

    EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // ZOMBIE_H
