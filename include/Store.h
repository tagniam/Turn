#ifndef STORE_H
#define STORE_H

#include "Player.h"

class Store {
    public:
        void StoreFront(Player*);
    private:
        void SellItem(Player*, int);
        void BuyItem(Player*, int);
};

#endif // STORE_H
