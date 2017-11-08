#ifndef SLIMEBALL_H
#define SLIMEBALL_H

#include "../Enemy.h"

class Slimeball : public Enemy {
public:
    Slimeball();
    std::string GetIntro();
    EnemyType GetType() override;
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // SLIMEBALL_H
