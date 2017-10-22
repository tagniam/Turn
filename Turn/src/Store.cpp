#include <iostream>
#include <Windows.h>

#include "..\include\Common.h"
#include "..\include\Store.h"
#include "..\include\ItemTypes.h"


using namespace std;
using namespace Common;

const unsigned short arrowsCost = 200;
const unsigned short bombCost = 100;
const unsigned short potionCost = 150;
const unsigned short whetstoneCost = 20;

//Messages
string lowCoinsMessage = " Insufficient Coins !";
string invalidChoice = " Invalid Choice Entered !";

void Store::StoreFront(Player* _Player) {

	unsigned short choice = 0;
	unsigned short coins;

	do
	{
		ClearScreen();
		coins = _Player->GetCoins();
		cout << endl << " Jeremy's Tools Store\tPlayer: ";
		cout << coins << " Coins" << endl << endl;
		cout << " ----ITEM----------------COST---------------- " << endl << endl;
		cout << " 1) Arrows x 5\t\t " << arrowsCost << endl;
		cout << " 2) Bomb\t\t " << bombCost << endl;
		cout << " 3) Potion\t\t " << potionCost << endl;
		cout << " 4) Whetstone\t\t " << whetstoneCost << endl << endl;
		cout << " 0) Exit" << endl << endl;
		cout << " -------------------------------------------- " << endl << endl;
		cout << " What do you want to buy today?" << endl << endl << " ";
		cin >> choice;
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
			Sleep(1000);
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
			Sleep(1000);
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
			Sleep(1000);
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
			Sleep(1000);
			break;
		case 0://Exit Store
			break;
		default:
			cout << invalidChoice << endl;
			Sleep(1000);
		}
	} while (choice);
}
