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

struct ItemHash {
    std::size_t operator()(ITEMTYPE it) const {
        return static_cast<std::size_t>(it);
    }
};

class Store {
    using catalogue_t = std::unordered_map<ITEMTYPE, ItemInfo, ItemHash>;

  public:
    Store() noexcept;
    void StoreFront(Player*);

  private:
    catalogue_t buy_stock;
    catalogue_t sell_stock;

    void BuyFront(Player*);
    void SellFront(Player*);

    void SellItem(Player*, ITEMTYPE, ItemInfo);
    void BuyItem(Player*, ITEMTYPE, ItemInfo);

    void DisplayStock(const catalogue_t&) const;
    void DisplayStoreMainMenu(Player*) const;

};

#endif // STORE_H
