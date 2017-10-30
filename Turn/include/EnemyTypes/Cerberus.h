#ifndef CERBERUS_H
#define CERBERUS_H

#include "../Enemy.h"


class Cerberus : public Enemy
{
public:
	Cerberus();

	EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // CERBERUS_H
