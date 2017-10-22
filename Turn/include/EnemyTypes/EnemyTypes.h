#ifndef ENEMYTYPES_H_INCLUDED
#define ENEMYTYPES_H_INCLUDED

// Includes all enemy type headers.

#include "Crab.h"
#include "GiantCrab.h"
#include "Squid.h"
#include "GiantSquid.h"
#include "Lich.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Goblin.h"
#include "Gargoyle.h"

enum EnemyType
{
    etCrab,
    etGiantCrab,
    etSquid,
    etGiantSquid,
    etLich,
    etVampire,
    etWerewolf,
    etGoblin,
    etGargoyle,
    etNumEnemyTypes
};

#endif // ENEMYTYPES_H_INCLUDED
