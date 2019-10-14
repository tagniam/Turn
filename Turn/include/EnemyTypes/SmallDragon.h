#ifndef SMALLDRAGON_H
#define SMALLDRAGON_H

#include "../Enemy.h"


class SmallDragon : public Enemy {
public:
	SmallDragon();

	EnemyType GetType() override;
	std::string GetIntro();
	
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // SMALLDRAGON_H
