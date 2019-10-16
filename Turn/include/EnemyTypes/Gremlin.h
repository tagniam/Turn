#ifndef GREMLIN_H
#define GREMLIN_H

#include "../Enemy.h"


class gremlin : public Enemy 
{
public:
	Gremlin();
	
    EnemyType GetType() override;
	std::string GetIntro();
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // GREMLIN_H
