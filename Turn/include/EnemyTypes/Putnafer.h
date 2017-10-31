#ifndef PUTNAFER_H
#define PUTNAFER_H

#include "../Enemy.h"


class Putnafer : public Enemy 
{
public:
	Putnafer();

    EnemyType GetType() override;
	std::string GetIntro();
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // PUTNAFER_H
