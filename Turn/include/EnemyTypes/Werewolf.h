#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "..\Enemy.h"


class Werewolf : public Enemy 
{
public:
	Werewolf();

    EnemyType GetType() override;
private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // WEREWOLF_H
