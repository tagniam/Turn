#ifndef RATKING_H
#define RATKING_H

#include "../Enemy.h"

class RatKing : public Enemy {
public:
    RatKing();

    EnemyType GetType() override;
    std::string GetIntro();
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();

    int amountOfRats_;
};

#endif // RATKING_H
