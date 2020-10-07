#ifndef Demon_H
#define Demon_H

#include "../Enemy.h"


class Demon : public Enemy {
public:
    Demon();

    EnemyType GetType() override;
    std::string GetIntro() override;
private:
    int ReturnDamage() override;
    int ReturnRiskAttackDamage() override;
    int ReturnHealAmount() override;
};

#endif // DEMON_H
