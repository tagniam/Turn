#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Entity.h"


class Enemy : public Entity {
    public:
        Enemy();

        int Attack();
        void DisplayHUD();

		std::vector<int> GetDrops();
        int ReturnExperience();

    protected:
        int GenericAttack();
        int RiskAttack();

        int ReturnItemDrop(int);
        
        int ExperienceAmount;
        int CoinsDrop;
};

#endif // ENEMY_H
