
#ifndef ITEMTYPES_H_INCLUDED
#define ITEMTYPES_H_INCLUDED

#include <map>

enum ITEMTYPE
{
	ARROWS = 1,
	BOMB,
	POTION,
	WHETSTONE,
	COIN
};

using ItemMap_t = std::map<ITEMTYPE, int>;

#endif
