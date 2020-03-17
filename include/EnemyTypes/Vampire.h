#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../Enemy.h"


class Vampire : public Enemy 
{
public:
	Vampire();

    EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // VAMPIRE_H
