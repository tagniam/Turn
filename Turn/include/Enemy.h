#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Entity.h"

enum EnemyType
{
    etCrab,
    etGiantCrab,
    etSquid,
    etGiantSquid,
    etLich,
    etZombie,
    etPutnafer,
    etVampire,
    etWerewolf,
    etGoblin,
    etGargoyle,
    etNumEnemyTypes
};


class Enemy : public Entity {
    public:
        Enemy();

        int Attack();
        void DisplayHUD();

		std::vector<int> GetDrops();
        int ReturnExperience();

        virtual EnemyType GetType() = 0;

    protected:
        int GenericAttack();
        int RiskAttack();

        int ReturnItemDrop(int);
        
        int ExperienceAmount;
        int CoinsDrop;
};

#endif // ENEMY_H
