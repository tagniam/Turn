#ifndef GARGOYLE_H
#define GARGOYLE_H

#include "../Enemy.h"


class Gargoyle : public Enemy 
{
public:
	Gargoyle();

    EnemyType GetType() override;
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // GARGOYLE_H
