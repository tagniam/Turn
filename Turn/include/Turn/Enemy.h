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
    etCerberus,
    etSkeleton,
    etSmallRat,
    etMurloc,
    etSlimeball,
    etNumEnemyTypes
};


class Enemy : public Entity {
    public:
        Enemy();

        int Action();
        void DisplayHUD();

		std::vector<int> GetDrops();
        int ReturnExperience();

        virtual EnemyType GetType() = 0;
		virtual std::string GetIntro();

    protected:
        int GenericAttack();
        int RiskAttack();

        int ReturnItemDrop(int);
        
        int ExperienceAmount;
        int CoinsDrop;
};

#endif // ENEMY_H
