#ifndef SKELETON_H
#define SKELETON_H

#include "../Enemy.h"


class Skeleton : public Enemy {
public:
	Skeleton();

	EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // SKELETON_H
