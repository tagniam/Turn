#include <iostream>

#include "../include/Common.h"
#include "../include/Store.h"
#include "../include/StoreGreetings.h"
#include "../include/ItemTypes.h"


using namespace std;
using namespace Common;

const unsigned short arrowsCost = 200;
const unsigned short bombCost = 100;
const unsigned short potionCost = 150;
const unsigned short whetstoneCost = 20;

// Messages
const string notEnoughItemsMessage = " Insufficient Items !";
const string lowCoinsMessage = " Insufficient Coins !";
const string invalidChoice = " Invalid Choice !";

void Store::StoreFront(Player* _Player) {
	// Displays store menu and allows player to buy/sell items.

	unsigned short choice = 0;

	bool buyItems = false;
	bool isValidChoice = false;

	do
	{
		ClearScreen();
		cout << endl << endl;
		_Player->DisplayInventory();
		cout << endl << " Jeremy's Tools Store" << endl;
		cout << " \"" << random_greeting() << "\"" << endl << endl;
		cout << " ---------------------------------- " << endl << endl;
		cout << " 1) Buy" << endl;
		cout << " 2) Sell" << endl << endl;
		cout << " 0) Exit" << endl << endl;
		cout << " ---------------------------------- " << endl << endl;
		cout << " What would you like to do today? " << endl << endl << " ";
		choice = input();
		cout << endl;

		isValidChoice = true;
		switch (choice)
		{
		case 1: // Buy
			buyItems = true;
			break;
		case 2: // Sell
			buyItems = false;
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

	// Allow player to buy/sell items as long as the player does not want to exit the store
	while (choice != 0)
	{
		ClearScreen();
		cout << endl << endl;
		_Player->DisplayInventory();
		cout << endl << " Jeremy's Tools Store" << endl << endl;
		cout << " ----ITEM----------------COST------ " << endl << endl;
		cout << " 1) Arrows x 5\t\t " << arrowsCost << endl;
		cout << " 2) Bomb\t\t " << bombCost << endl;
		cout << " 3) Potion\t\t " << potionCost << endl;
		cout << " 4) Whetstone\t\t " << whetstoneCost << endl << endl;
		cout << " 0) Exit" << endl << endl;
		cout << " ---------------------------------- " << endl << endl;
		if (buyItems)
		{
			cout << " What do you want to buy today?" << endl << endl << " ";
		}
		else
		{
			cout << " What do you want to sell today?" << endl << endl << " ";
		}
		choice = input();
		cout << endl;

		switch (choice)
		{
		case ITEMTYPE::ARROWS:
		case ITEMTYPE::BOMB:
		case ITEMTYPE::POTION:
		case ITEMTYPE::WHETSTONE:
			if (buyItems)
			{
				BuyItem(_Player, choice);
			}
			else
			{
				SellItem(_Player, choice);
			}
			Sleep(SLEEP_MS);
		case 0: // Exit
			break;
		default:
			cout << invalidChoice << endl;
			Sleep(SLEEP_MS);
		}
	}
}

void Store::SellItem(Player* _Player, int _Item) {
	// Sells a specific item from a player.

	switch (_Item)
	{
	case ITEMTYPE::ARROWS:
		if (_Player->RemoveStoreItemFromInventory(ITEMTYPE::ARROWS))
		{
			cout << " Arrows sold !" << endl;
			_Player->AddCoins(arrowsCost);
		}
		else
		{
			cout << notEnoughItemsMessage << endl;
		}
		break;
	case ITEMTYPE::BOMB:
		if (_Player->RemoveStoreItemFromInventory(ITEMTYPE::BOMB))
		{
			cout << " Bomb sold !" << endl;
			_Player->AddCoins(bombCost);
		}
		else
		{
			cout << notEnoughItemsMessage << endl;
		}
		break;
	case ITEMTYPE::POTION:
		if (_Player->RemoveStoreItemFromInventory(ITEMTYPE::POTION))
		{
			cout << " Potion sold !" << endl;
			_Player->AddCoins(potionCost);
		}
		else
		{
			cout << notEnoughItemsMessage << endl;
		}
		break;
	case ITEMTYPE::WHETSTONE:
		if (_Player->RemoveStoreItemFromInventory(ITEMTYPE::WHETSTONE))
		{

			cout << " Whetstone sold !" << endl;
			_Player->AddCoins(whetstoneCost);
		}
		else
		{
			cout << notEnoughItemsMessage << endl;
		}
		break;
	}
}

void Store::BuyItem(Player* _Player, int _Item) {
	// Buys a specific item from the store.

	unsigned short coins = _Player->GetCoins();

	switch (_Item)
	{
	case ITEMTYPE::ARROWS:
		if (coins < arrowsCost)
		{
			cout << lowCoinsMessage << endl;
		}
		else
		{
			cout << " 5 Arrows purchased ! " << endl;
			_Player->AddStoreItemToInventory(ITEMTYPE::ARROWS);
			_Player->LoseCoins(arrowsCost);
		}
		break;
	case ITEMTYPE::BOMB:
		if (coins < bombCost)
		{
			cout << lowCoinsMessage << endl;
		}
		else
		{
			cout << " Bomb purchased !" << endl;
			_Player->AddStoreItemToInventory(ITEMTYPE::BOMB);
			_Player->LoseCoins(bombCost);
		}
		break;
	case ITEMTYPE::POTION:
		if (coins < potionCost)
		{
			cout << lowCoinsMessage << endl;
		}
		else
		{
			cout << " Potion purchased !" << endl;
			_Player->AddStoreItemToInventory(ITEMTYPE::POTION);
			_Player->LoseCoins(potionCost);
		}
		break;
	case ITEMTYPE::WHETSTONE:
		if (coins < whetstoneCost)
		{
			cout << lowCoinsMessage << endl;
		}
		else
		{
			cout << " Whetstone purchased !" << endl;
			_Player->AddStoreItemToInventory(ITEMTYPE::WHETSTONE);
			_Player->LoseCoins(whetstoneCost);
		}
		break;
	}
}
