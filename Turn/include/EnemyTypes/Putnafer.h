#ifndef PUTNAFER_H
#define PUTNAFER_H

#include "..\Enemy.h"


class Putnafer : public Enemy 
{
public:
	Putnafer();

private:
	int ReturnDamage();
	int ReturnRiskAttackDamage();
	int ReturnHealAmount();
};

#endif // PUTNAFER_H
