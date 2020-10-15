#ifndef STORE_H
#define STORE_H

#include <unordered_map>
#include <string>

#include "Player.h"

struct ItemInfo {
    std::string item_name;
    int amount;
    int piece_price;
};

class Store {
    using catalogue_t = std::unordered_map<ITEMTYPE, ItemInfo>;

  public:
    void StoreFront(Player*);

  private:
    void BuyFront(Player*);
    void SellFront(Player*);

    void SellItem(Player*, ITEMTYPE, ItemInfo);
    void BuyItem(Player*, ITEMTYPE, ItemInfo);

    void DisplayStock(const catalogue_t&) const;
    void DisplayStoreMainMenu(Player*) const;

};

#endif // STORE_H
