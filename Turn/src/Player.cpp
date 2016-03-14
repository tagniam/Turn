#include <fstream>
#include <iostream>
#include <Windows.h>

#include "..\include\Common.h"
#include "..\include\Player.h"
#include "..\include\Enemy.h"

using namespace std;
using namespace Common;

#define GREY 7
#define DARK_GREY 7
#define RED 12
#define RED_BACKGROUND 207
#define GREY_BACKGROUND 127

void Player::SaveGame(){
    ofstream WriteData;
    WriteData.open("data.txt");
    WriteData << name << endl
              << level << endl
              << experience << endl
              << health << endl
              << arrows << endl
              << bombs << endl
              << potions << endl
              << whetstones << endl
              << weaponstrength << endl
              << queens;
    WriteData.close();
}

string Player::ReturnName(){
    ClearScreen();
	cout << "What is your name?"
		<< endl << endl
		<< "> ";
	
	cin >> name; // Change to full name
	return name;
}
void Player::SetPlayerData(){
    // Primarily initializes default values at the beginning of the game.

    /*
    // Sets health to maximum.
    health=100;

    // Sets level to 1, lowest level.
    level = 1;

    // Sets experience points to 0.
    experience = 0;

    // Gives player 10 arrows.
    arrows = 10;

    // Gives player 1 bomb.
    bombs = 1;

    // Sets weapon strength to maximum.
    weaponstrength=100;

    // Gives player 1 whetstone.
    whetstones=1;

    //Gives player 1 potion.
    potions=1;

    // Initializes player name to Player, in case player does not initialize a name.
    name = "Player";*/

    // Handle for SetConsoleTextAttribute()'s first argument.
    /// To be honest, don't know what this does.

    ifstream ReadData;
    ReadData.open("data.txt");

    if (!ReadData){
        ReadData.close();
        ofstream WriteData;
        WriteData.open("data.txt");
        WriteData << ReturnName() << endl
                  << 1 << endl
                  << 0 << endl
                  << 100 << endl
                  << 10 << endl
                  << 1 << endl
                  << 1 << endl
                  << 1 << endl
                  << 100 << endl
                  << 0;
        WriteData.close();
        ReadData.open("data.txt");
    }
    else
        ReadData.clear();


    ReadData >> name;
    ReadData >> level;
    ReadData >> experience;
    ReadData >> health;
    ReadData >> arrows;
    ReadData >> bombs;
    ReadData >> potions;
    ReadData >> whetstones;
    ReadData >> weaponstrength;
    ReadData >> queens;

    ReadData.close();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
         << "0) Get me out of here!" << endl << endl
         << "> ";
    
    choice = input();
    cout << endl;

    // Evaluates player's choice.
    switch(choice){
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
            if (arrows > 0) return BowAndArrow();
            else cout << "None in inventory!" << endl;
            break;
        case 4:
            // Player heals, no damage is done to enemy.
            Heal();
            break;
        case 5:
            // Player throws a bomb.
            // Does not execute if there are no bombs in the inventory.
            if (bombs>0) return UseBomb();
            else cout << "None in inventory!" << endl;
            break;
        case 6:
            // Player drinks a potion.
            // Does not execute if there are no potions in the inventory.
            // No damage is done to the enemy.
            if (potions>0) UsePotion();
            else cout << "None in inventory!" << endl;
            break;
        case 7:
            // Player sharpens their weapon with a whetstone.
            // Does not execute if there are no whetstones in inventory.
            // No damage is done to the enemy.
            if (whetstones>0) UseWhetstone();
            else cout << "None in inventory!" << endl;
            break;
        default:
            // Generically attacks by default if player's choice does not equal above cases.
            return GenericAttack();
    }
    // No damage is done. This line is called when the player heals, uses a potion, or uses a whetstone.
    return 0;
}

void Player::TakeDamage(int damage){
    // Simply deducts damage points from total health.
    health -= damage;
}

void Player::AddToInventory(int _arrows, int _whetstones, int _potions, int _bombs, int _queens){
    // Adds items to inventory and prints out what the player received.

    // Adds items received to total items.
    arrows+=_arrows;
    whetstones+=_whetstones;
    potions+=_potions;
    bombs += _bombs;
    queens += _queens;

    // Prints number of items received.
    cout << "You have gained: " << endl
         << "[" << _arrows << "] arrows + " << endl
         << "[" << _bombs << "] bombs + " << endl
         << "[" << _potions << "] potions +" << endl
         << "[" << _whetstones << "] whetstones" << endl
         << "[" << _queens << "] Queens" << endl << endl;
}

void Player::DisplayHealthBar(Enemy *_Enemy){
    // Displays player's name and health bar. Enemy object is used to print name on the same line as player name for aesthetics.

    // Prints player's name.
    cout << endl;
    DisplayName();
    // Tabs to make room for enemy's name.
    if (name.length() > 5){
        cout << "\t";
    }
    else {
        cout <<" \t\t";
    }
    // Prints enemy name.
    _Enemy->DisplayName();


    /// The following lines contain the code for the health bar.
    /// Being difficult to explain, no comments will explain why
    /// SetConsoleTextAttribute() is used, why it evaluates the health, why it prints blank spaces, etc.
    /// Intuition will be enough to understand what is going on in the following lines.

    string healthBar = "    " + std::to_string(health);

    for (int i = healthBar.length(); i < 10; i++)
        healthBar += " ";

    cout << endl;
    for (int i = 0; i < healthBar.length(); i++){
        if ((i+1)*10 <= health){
            SetConsoleTextAttribute(hConsole, RED_BACKGROUND);
            cout << healthBar.at(i);
        }
        else {
            SetConsoleTextAttribute(hConsole, GREY_BACKGROUND);
            cout << healthBar.at(i);
        }
    }

    SetConsoleTextAttribute(hConsole, GREY);
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

bool Player::IsDead(){
    // Returns a bool value, if the player's health is equal or below 0.
    if (health <= 0) {
        cout << "You're dead!" << endl << endl;
        Sleep(SLEEP_MS);
        return true;
    }
    return false;
}

void Player::DisplayName(){
    // Prints the player's name is dark gray for aesthetic purposes.

    // Sets text to dark grey.
    SetConsoleTextAttribute(hConsole, DARK_GREY);

    // Prints the player's name.
    cout << name;

    // Sets text back to normal gray.
    SetConsoleTextAttribute(hConsole, GREY);
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

void Player::AddQueens(int q){
    queens += q;
}

void Player::LoseQueens(int q){
    queens -= q;
    if (queens < 0) queens = 0;
}

void Player::DisplayInventory(){
    // Checks valid weapon strength.
    if (weaponstrength < 0){
        weaponstrength = 0;
    }
    // Simply prints the player's inventory.

    cout << "*------- INVENTORY -------* " << endl;
    cout << "Level " << level << "\t\t" << experience << "/100 xp" << endl;
    cout << "| Arrows: [" << arrows << "]" << endl;
    cout << "| Potions: [" << potions << "]" << endl;
    cout << "| Bombs: [" << bombs << "]" << endl;
    cout << "| Whetstones: [" << whetstones << "]" << endl;
    cout << "| Weapon strength: [" << weaponstrength << "%]" << endl;
    cout << "| Wealth: [" << queens << "] Queens" << endl;
    cout << "--------------------------- " << endl << endl;
}

int Player::GenericAttack(){
    int damage = ReturnDamage();
    DeductDamage(damage);
    DisplayName();
    cout << " attacks! He deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << damage;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " damage points!" << endl;
    if (damage>0) weaponstrength-= 2+rand()%5;
    return damage;
}

int Player::RiskAttack(){
    int damage = ReturnRiskAttackDamage();
    DeductDamage(damage);
    DisplayName();
    cout << " takes a risk and attack! He deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << damage;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " damage points!" << endl;
    if (damage>0) weaponstrength-= 4+rand()%5;
    return damage;
}

int Player::BowAndArrow(){
    int damage = ReturnBowDamage();
    DisplayName();
    cout << " shoots his bow! He deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << damage;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " damage points!" << endl;
    return damage;
}

void Player::UseWhetstone(){
    weaponstrength=100;
    DisplayName();
    cout << " sharpened his weapon!" << endl;
    whetstones--;
}

void Player::UsePotion(){
    health=100;
    DisplayName();
    cout << " drank a healing potion!" << endl;
    potions--;
}

int Player::UseBomb(){
    DisplayName();
    cout << " hurls a bomb! ";
    DisplayName();
    cout << " deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << "50";
    SetConsoleTextAttribute(hConsole, GREY);
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

void Player::Heal(){
    int heal = ReturnHealAmount();
    health += heal;
    if (health > 100) health = 100;
    DisplayName();
    cout << " gains ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << heal;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " HP! ";
    DisplayName();
    cout << " now has " << health << "HP!" << endl;
}

int Player::Flee(){
    DisplayName();
    cout << " chooses to flee!" << endl;
    return -1;
}

