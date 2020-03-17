#ifndef TIMIDGHOST_H
#define TIMIDGHOST_H

#include "../Enemy.h"


class TimidGhost : public Enemy
{
public:
	TimidGhost();

	EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // TIMIDGHOST_H
