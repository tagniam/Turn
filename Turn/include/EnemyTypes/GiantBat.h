#ifndef GIANTBAT_H
#define GIANTBAT_H

#include "../Enemy.h"


class GiantBat : public Enemy
{
public:
	GiantBat();

	EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // GIANTBAT_H
