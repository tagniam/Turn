
#ifndef ITEMTYPES_H_INCLUDED
#define ITEMTYPES_H_INCLUDED

#include <unordered_map>

enum ITEMTYPE
{
	ARROWS = 1,
	BOMB,
	POTION,
	WHETSTONE,
	COIN
};

struct ItemTypeHash {
    template<typename T>
    std::size_t operator()(T t) const {
        return static_cast<std::size_t>(t);
    }
};

using ItemMap_t = std::unordered_map<ITEMTYPE, int, ItemTypeHash>;

#endif
