#ifndef RATKING_H
#define RATKING_H

#include "../Enemy.h"

class RatKing : public Enemy {
public:
    RatKing();

    EnemyType GetType() override;
    std::string GetIntro() override;
private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;

    int amountOfRats_;
};

#endif // RATKING_H
