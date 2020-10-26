#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Entity.h"

enum EnemyType {
    etCrab,
    etGiantCrab,
    etSquid,
    etGiantSquid,
    etMimic,
    etLich,
    etZombie,
    etPutnafer,
    etVampire,
    etWerewolf,
    etGoblin,
    etGargoyle,
    etCerberus,
    etSkeleton,
    etSmallDragon,
    etSmallRat,
    etMurloc,
    etSlimeball,
    etRatKing,
    etZabra,
    etTimidGhost,
    etGremlin,
    etDemon,
    etNumEnemyTypes,
    etWizard
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
