#include <fstream>
#include <iostream>

#include "..\include\Common.h"
#include "..\include\Player.h"

using namespace std;
using namespace Common;

void Player::SaveGame(){
	ofstream WriteData;
	WriteData.open("data.txt");
	if (WriteData.is_open()) {
        	WriteData << player_type << endl 
			<< name << endl
			<< level << endl
			<< experience << endl
			<< health << endl
			<< arrows << endl
			<< bombs << endl
			<< potions << endl
			<< whetstones << endl
			<< weaponstrength << endl
			<< coins;
    		WriteData.close();
	} else {
		cout << "Error opening savegame data (data.txt)." << endl;
	}
}



void Player::SetPlayerData(){
    // Primarily initializes default values at the beginning of the game.

	ifstream ReadData;
	ReadData.clear();
	ReadData.open("data.txt");
	if (ReadData.is_open())	{
		ReadData >> player_type;
    		ReadData >> name;
    		ReadData >> level;
    		ReadData >> experience;
		ReadData >> health;
		ReadData >> arrows;
		ReadData >> bombs;
		ReadData >> potions;
		ReadData >> whetstones;
		ReadData >> weaponstrength;
		ReadData >> coins;
		ReadData.close();
 	} else {
		cout << "Error opening savegame data (data.txt)." << endl;
	}

}

int Player::Attack(){
    // Returns the amount of attack points the player gives.
    // Also the main battle screen.

    int choice = 0;


    // Displays the inventory.
    DisplayInventory();

    // Gives player a list of moves to choose from.
	cout << "Choose your move:" << endl
		<< "1) Attack" << endl
		<< "2) Risk Attack" << endl
		<< "3) Bow and Arrow" << endl
		<< "4) Heal" << endl << endl
		<< "5) Use Bomb" << endl
		<< "6) Use Potion" << endl
		<< "7) Use Whetstone" << endl
		<< "0) Get me out of here!" << endl << endl;
	
	while (true) {
		choice = input();

		// Evaluates player's choice.
		switch (choice) {
		case 0:
			return Flee();
		case 1:
			// Player generically attacks.
			return GenericAttack();
		case 2:
			// Player takes a risk and attacks.
			return RiskAttack();
		case 3:
			// Player shoots their bow.
			if (arrows > 0)
				return BowAndArrow();
			break;
		case 4:
			// Player heals, no damage is done to enemy.
			Heal();
			return 0;
		case 5:
			// Player throws a bomb.
			// Does not execute if there are no bombs in the inventory.
			if (bombs > 0) 
				return UseBomb();
			break;
		case 6:
			// Player drinks a potion.
			// Does not execute if there are no potions in the inventory.
			if (potions > 0) {
				UsePotion();
				return 0;
			}
			break;
		case 7:
			// Player sharpens their weapon with a whetstone.
			// Does not execute if there are no whetstones in inventory.
			// No damage is done to the enemy.
			if (whetstones > 0) {
				UseWhetstone();
				return 0;
			}
			break;
		default:
			// Generically attacks by default if player's choice does not equal above cases.
			return GenericAttack();
		}
	}
}

void Player::UseItem() {
	// Use item from inventory
	int choice = 0;

	while (true) {
		ClearScreen();

		// Displays the inventory.
		DisplayInventory();

		// Gives player a list of moves to choose from.
		cout << "Choose which item use:" << endl
			<< "1) Use Potion" << endl
			<< "2) Use Whetstone" << endl
			<< "0) Quit" << endl << endl;

		choice = input();

		// Evaluates player's choice.
		switch (choice) {
		case 0:
			return;
		case 1:
			// Player drinks a potion.
			// Does not execute if there are no potions in the inventory.
			if (potions > 0) {
				UsePotion();
				Sleep(SLEEP_MS);
			} else {
				cout << "No potions in the inventory!" << endl;
				Sleep(SLEEP_MS);
			}

			break;
		case 2:
			// Player sharpens their weapon with a whetstone.
			// Does not execute if there are no whetstones in inventory.
			// No damage is done to the enemy.
			if (whetstones > 0) {
				UseWhetstone();
				Sleep(SLEEP_MS);
			} else {
				cout << "No whetstones in the inventory!" << endl;
				Sleep(SLEEP_MS);
			}

			break;
		default:
			break;
		}
	}
}

void Player::AddToInventory(vector<int> drops){
    // Adds items to inventory and prints out what the player received.
	
    // Adds items received to total items.
    arrows += drops.at(0);
	bombs += drops.at(1);
	potions += drops.at(2);
	whetstones += drops.at(3);
    coins += drops.at(4);
	
	
    // Prints number of items received.
	cout << "You have gained: " << endl;
	if (drops[0] > 0)
		cout << "[" << drops.at(0) << "] arrows" << endl;
	if (drops[1] > 0)
		cout << "[" << drops.at(1) << "] bombs" << endl;
	if (drops[2] > 0)
		cout << "[" << drops.at(2) << "] potions" << endl;
	if (drops[3] > 0)
		cout << "[" << drops.at(3) << "] whetstones" << endl;
	if (drops[4] > 0)
         cout << "[" << drops.at(4) << "] coins" << endl;

	cout << endl;
}

void Player::DisplayHUD(Enemy *_Enemy){
    // Displays player's name and health bar. Enemy object is used to print name on the same line as player name for aesthetics.

    // Prints player's name.
    cout << endl;
	ColourPrint(name, DARK_GREY);
    // Tabs to make room for enemy's name.
    if (name.length() > 5){
        cout << "\t\t\t";
    }
    else {
        cout <<" \t\t\t";
    }
    // Prints enemy name.
	ColourPrint(_Enemy->GetName(), DARK_GREY);
	cout << endl;
	DisplayHealthBar();
}

void Player::ReplenishHealth(){
    // Adds health points after player has defeated an enemy.
	if (health <= 0)
		health = 100;
	else {
		health += 30;
		if (health > 100) health = 100;
	}
}

void Player::AddExperience(int xp){
    // Adds points to the player's experience and levels player up.

    // Adds experience from passed in integer to local class variable experience.
    experience += xp;

    // Evaluates if experience is higher than 99, which means a level up is in order.
    if (experience>99) {
        // Experience is set to 0.
        experience = 0;

        // Player is leveled up.
        level+=1;

        // Sets level cap to 50, player cannot level higher than that.
        if (level >= 50) level = 50;

        // Alerts player that they have leveled up.
        cout << "You leveled up! Now you are level " << level << "!" << endl;
        Sleep(SLEEP_MS);
    }
}

void Player::LoseExperience(int xp){
    // Deducts points from the player's experience and de-levels player.

    // Deducts experience from passed in integer to local class variable experience.
    experience -= xp;

    // Evaluates if experience is less than 0.
    if (experience<0){
        // Experience is deducted continuing from the experience which de-leveled the player (hard to explain...)
        experience = 100-(0-experience);

        // De-levels player.
        level-=1;

        // Checks any glitches and sets player level to 1 if level is below 1 or above 50.
        // Also resets experience points.
        if (level<1 || level>50){
            level=1;
            experience = 0;
        }

        // Alerts the player that they have de-leveled.
        else {
            cout << "You de-leveled back to level " << level << "..." << endl;
            Sleep(SLEEP_MS);
        }
    }
}

void Player::AddCoins(int c){
    coins += c;
}

void Player::LoseCoins(int c){
    coins -= c;
    if (coins < 0) coins = 0;
}

void Player::DisplayInventory(){
    // Checks valid weapon strength.
    if (weaponstrength < 0){
        weaponstrength = 0;
    }
    // Simply prints the player's inventory.

    cout << "*----------- INVENTORY -----------* " << endl;
    cout << "Level " << level << "\t\t\t" << experience << "/100 xp" << endl;
    cout << "| Arrows: [" << arrows << "]" << endl;
    cout << "| Potions: [" << potions << "]" << endl;
    cout << "| Bombs: [" << bombs << "]" << endl;
    cout << "| Whetstones: [" << whetstones << "]" << endl;
    cout << "| Weapon strength: [" << weaponstrength << "%]" << endl;
    cout << "| Wealth: [" << coins << "] coins" << endl;
    cout << "*---------------------------------*" << endl << endl;
}

int Player::GetCoins() { 
    return coins; 
} 

int Player::GenericAttack(){
    int damage = ReturnDamage();
    DeductDamage(damage);
	ColourPrint(name, DARK_GREY);
    cout << " attacks! He deals ";
	ColourPrint(to_string(damage), RED);
    cout << " damage points!" << endl;
    if (damage>0) weaponstrength-= 2+rand()%5;
    return damage;
}

int Player::RiskAttack(){
    int damage = ReturnRiskAttackDamage();
    DeductDamage(damage);
	ColourPrint(name, DARK_GREY);
    cout << " takes a risk and attack! It deals ";
	ColourPrint(to_string(damage), RED);
    cout << " damage points!" << endl;

    if (damage>0) weaponstrength-= 4+rand()%5;
    return damage;
}

int Player::BowAndArrow(){
    int damage = ReturnBowDamage();
	ColourPrint(name, DARK_GREY);
    cout << " shoots his bow! He deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << damage;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " damage points!" << endl;
    return damage;
}

void Player::UseWhetstone(){
    weaponstrength=100;
	ColourPrint(name, DARK_GREY);
    cout << " sharpened his weapon!" << endl;
    whetstones--;
}

void Player::UsePotion(){
    health=100;
	ColourPrint(name, DARK_GREY);
    cout << " drank a healing potion!" << endl;
    potions--;
}

int Player::UseBomb(){
	ColourPrint(name, DARK_GREY);
    cout << " hurls a bomb! It deals ";
	ColourPrint("50", RED);
	cout << " damage points!" << endl;
    
	bombs--;
    return 50;
}

void Player::DeductDamage(int &damage){
    if (weaponstrength<=75&&weaponstrength>50)
        damage-=1;
    else if (weaponstrength<=50&&weaponstrength>30)
        damage-=4;
    else if (weaponstrength<=30&&weaponstrength>20)
        damage-=5;
    else if (weaponstrength<=20&&weaponstrength>10)
        damage-=6;
    else if (weaponstrength<=10)
        damage-=7;
    if (damage<0)
        damage=0;
}

int Player::ReturnBowDamage(){
    if (arrows < 1)
        return 0;
    arrows--;
    return 10+rand()%6; // 10 - 15
}

int Player::Flee(){
	ColourPrint(name, DARK_GREY);
    cout << " chooses to flee!" << endl;
    return -1;
}
