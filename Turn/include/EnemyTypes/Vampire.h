#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../Enemy.h"


class Vampire : public Enemy 
{
public:
	Vampire();

    EnemyType GetType() override;
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // VAMPIRE_H
