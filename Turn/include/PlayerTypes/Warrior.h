#ifndef WARRIOR_H
#define WARRIOR_H

#include "../Player.h"


class Warrior : public Player {
	public:
		Warrior(void);
    private:
        int ReturnDamage();
        int ReturnRiskAttackDamage();
        int ReturnHealAmount();
};

#endif // WARRIOR_H
