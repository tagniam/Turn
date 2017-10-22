#ifndef GOBLIN_H
#define GOBLIN_H

#include "..\Enemy.h"


class Goblin : public Enemy 
{
public:
	Goblin();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // GOBLIN_H
