#include <cassert>
#include <iostream>

#include "../include/Common.h"
#include "../include/Store.h"
#include "../include/StoreGreetings.h"
#include "../include/ItemTypes.h"


using namespace std;
using namespace Common;

// Messages
const string notEnoughItemsMessage = " Insufficient Items !";
const string lowCoinsMessage = " Insufficient Coins !";
const string invalidChoice = " Invalid Choice !";

Store::Store() noexcept {
    buy_stock = {
        {ITEMTYPE::WHETSTONE, {"Whetstone", 1, 20}},
        {ITEMTYPE::POTION, {"Potion", 1, 150}},
        {ITEMTYPE::BOMB, {"Bomb", 1, 100}},
        {ITEMTYPE::ARROWS, {"Arrows", 5, 40}}
    };
    sell_stock = {
        {ITEMTYPE::WHETSTONE, {"Whetstone", 1, 20}},
        {ITEMTYPE::POTION, {"Potion", 1, 150}},
        {ITEMTYPE::BOMB, {"Bomb", 1, 100}},
        {ITEMTYPE::ARROWS, {"Arrows", 5, 40}}
    };
}

void Store::StoreFront(Player* _Player) {
    // Displays store menu and allows player to buy/sell items.
    bool isValidChoice = false;
    do {
        // Display the store's main menu
        DisplayStoreMainMenu(_Player);
        // Input choice
        unsigned short choice = input();
        cout << endl;
        isValidChoice = true;
        switch (choice) {
        case 1: // Buy
            BuyFront(_Player);
            break;
        case 2: // Sell
            SellFront(_Player);
            break;
        case 0: // Exit
            break;
        default:
            cout << invalidChoice << endl;
            isValidChoice = false;
            Sleep(SLEEP_MS);
            break;
        }
    } while (!isValidChoice);
}

void Store::BuyFront(Player* _Player) {
    // Displays the buy front
    while (true) {
        ClearScreen();
        cout << "\n\n";
        _Player->DisplayInventory();
        DisplayStock(buy_stock);
        cout << " What do you want to buy today?\n\n ";
        int choice = input();
        if (choice == 0 /* exit */) {
            break;
        }
        const auto& item = buy_stock.find(static_cast<ITEMTYPE>(choice));
        if (item != std::end(buy_stock)) {
            BuyItem(_Player, static_cast<ITEMTYPE>(choice), item->second);
        } else {
            cout << invalidChoice << '\n';
        }
        Sleep(SLEEP_MS);
    }
}

void Store::SellFront(Player* _Player) {
    // Displays the sell front
    while (true) {
        ClearScreen();
        cout << "\n\n";
        _Player->DisplayInventory();
        DisplayStock(sell_stock);
        cout << " What do you want to sell today?\n\n ";
        int choice = input();
        if (choice == 0 /* exit */) {
            break;
        }
        const auto& item = sell_stock.find(static_cast<ITEMTYPE>(choice));
        if (item != std::end(sell_stock)) {
            SellItem(_Player, static_cast<ITEMTYPE>(choice), item->second);
        } else {
            cout << invalidChoice << '\n';
        }
        Sleep(SLEEP_MS);
    }
}

void Store::BuyItem(Player* _Player, ITEMTYPE _Item, ItemInfo _ItemInfo) {
    // Buys a specific item, if possible
    auto price = _ItemInfo.amount * _ItemInfo.piece_price;
    if (_Player->GetCoins() >= price) {
        cout << "Bought " << _ItemInfo.amount << ' ' << _ItemInfo.item_name + " !\n";
        _Player->AddStoreItemToInventory(_Item, _ItemInfo.amount);
        _Player->LoseCoins(price);
    } else {
        cout << lowCoinsMessage << '\n';
    }
}

void Store::SellItem(Player* _Player, ITEMTYPE _Item, ItemInfo _ItemInfo) {
    // Sells a specific item from a player.
    if (_Player->RemoveStoreItemFromInventory(_Item, _ItemInfo.amount)) {
        cout << "Sold " << _ItemInfo.amount << ' ' << _ItemInfo.item_name << " !\n";
        _Player->AddCoins(_ItemInfo.piece_price * _ItemInfo.amount);
    } else {
        cout << notEnoughItemsMessage << '\n';
    }
}

void Store::DisplayStock(const catalogue_t& _Catalog) const {
    // Displays Jeremy's Tools Store's stock
    cout << endl << " Jeremy's Tools Store\n\n";
    cout << " ----ITEM----------------COST------ \n\n";
    int item_idx = 1;
    for (const auto& item: _Catalog) {
        cout << ' ' + to_string(item_idx++) << ") ";
        if (item.second.amount > 1) {
            cout << item.second.item_name << " x " << item.second.amount << "\t\t"
                 << item.second.piece_price * item.second.amount << '\n';
        } else {
            cout << item.second.item_name << "\t\t" << item.second.piece_price << '\n';
        }
    }
    cout << endl << " 0) Exit\n\n";
    cout << " ---------------------------------- \n\n";
}

void Store::DisplayStoreMainMenu(Player* _Player) const {
    // Displays Jeremy's Tools Store's main menu
    ClearScreen();
    cout << endl << endl;
    _Player->DisplayInventory();
    cout << endl << " Jeremy's Tools Store\n";
    cout << " \"" << random_greeting() << "\"\n\n";
    cout << " ---------------------------------- \n\n";
    cout << " 1) Buy\n";
    cout << " 2) Sell\n\n";
    cout << " 0) Exit\n\n";
    cout << " ---------------------------------- \n\n";
    cout << " What would you like to do today? \n\n ";
}
