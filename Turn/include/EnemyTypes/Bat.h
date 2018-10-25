#ifndef BAT_H
#define BAT_H

#include "../Enemy.h"


class Bat : public Enemy
{
public:
	Bat();

	EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // BAT_H
