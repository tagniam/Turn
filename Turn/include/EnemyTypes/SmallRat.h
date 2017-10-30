#ifndef SMALLRAT_H
#define SMALLRAT_H

#include "../Enemy.h"


class SmallRat : public Enemy {
public:
	SmallRat();

	EnemyType GetType() override;
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // SMALLRAT_H
