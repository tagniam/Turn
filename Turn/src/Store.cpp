#include <iostream>

#include "../include/Common.h"
#include "../include/Store.h"
#include "../include/ItemTypes.h"


using namespace std;
using namespace Common;

const unsigned short arrowsCost = 200;
const unsigned short bombCost = 100;
const unsigned short potionCost = 150;
const unsigned short whetstoneCost = 20;

//Messages
const string lowCoinsMessage = " Insufficient Coins !";
const string invalidChoice = " Invalid Choice !";

void Store::StoreFront(Player* _Player) {

	unsigned short choice = 0;
	unsigned short coins;

	do
	{
		ClearScreen();
		coins = _Player->GetCoins();
		cout << endl << endl;
		_Player->DisplayInventory();
		cout << endl << " Jeremy's Tools Store" << endl << endl;
		switch((rand() % 7))
    {
    case 0:
        {
            cout << "It might not look it, but I have the best gear in town!";
        }
    case 1:
        {
            cout << "Ain't no better place to get your gear.";
        }
    case 2:
        {
            cout << "Well I'll be, a fresh face!";
        }
    case 3:
        {
            cout << "I'd heard there was an adventurer in town!";
        }
    case 5:
        {
            cout << "You never know when you'll need to be prepared!";
        }
    case 6:
        {
            cout << "You look like someone who could use some of these!";
        }
    }
		cout << " ----ITEM----------------COST------ " << endl << endl;
		cout << " 1) Arrows x 5\t\t " << arrowsCost << endl;
		cout << " 2) Bomb\t\t " << bombCost << endl;
		cout << " 3) Potion\t\t " << potionCost << endl;
		cout << " 4) Whetstone\t\t " << whetstoneCost << endl << endl;
		cout << " 0) Exit" << endl << endl;
		cout << " ---------------------------------- " << endl << endl;
		cout << " What do you want to buy today?" << endl << endl << " ";
		choice = input();
		cout << endl;
		switch (choice)
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
			Sleep(SLEEP_MS);
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
			Sleep(SLEEP_MS);
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
			Sleep(SLEEP_MS);
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
			Sleep(SLEEP_MS);
			break;
		case 0://Exit Store
			break;
		default:
			cout << invalidChoice << endl;
			Sleep(SLEEP_MS);
		}
	} while (choice);
}
