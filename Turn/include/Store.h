#ifndef STORE_H
#define STORE_H

#include "Player.h"

class Store {
    public:
        void StoreFront(Player*);
        void SellingItems(Player*);//impliments selling of items
        int  getJeremysCoin(){

        	return JeremysCoin; 
        }

    private: 

    	unsigned int JeremysCoin=20000; 
};

#endif // STORE_H
