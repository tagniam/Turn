#ifndef PUTNAFER_H
#define PUTNAFER_H

#include "../Enemy.h"


class Putnafer : public Enemy
{
public:
	Putnafer();

    EnemyType GetType() override;
	std::string GetIntro() override;
private:
	int ReturnDamage() override;
	int ReturnRiskAttackDamage() override;
	int ReturnHealAmount() override;
};

#endif // PUTNAFER_H
