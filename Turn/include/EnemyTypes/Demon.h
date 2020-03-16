#ifndef Demon_H
#define Demon_H

#include "../Enemy.h"


class Demon : public Enemy {
public:
    Demon();

    EnemyType GetType() override;
    std::string GetIntro();
private:
    int ReturnDamage();
    int ReturnRiskAttackDamage();
    int ReturnHealAmount();
};

#endif // DEMON_H