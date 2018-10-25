#ifndef GIANTSPIDER_H
#define GIANTSPIDER_H

#include "../Enemy.h"


class GiantSpider : public Enemy
{
public:
	GiantSpider();

	EnemyType GetType() override;
	std::string GetIntro();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // GIANTSPIDER_H
