#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"


class Enemy : public Entity {
    public:
        Enemy();

        int Attack();
        void DisplayHUD();

        int GetDrops(char);
        int ReturnExperience();

    protected:
        int GenericAttack();
        int RiskAttack();

        int ReturnItemDrop(char);
        
        int ExperienceAmount;
        int QueensDrop;
};

#endif // ENEMY_H
