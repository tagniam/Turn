#include <iostream>
#include <Windows.h>

#include "..\include\Common.h"
#include "..\include\Enemy.h"


using namespace std;
using namespace Common;

#define GREY 7
#define DARK_GREY 7
#define RED 12
#define RED_BACKGROUND 207
#define GREY_BACKGROUND 127


Enemy::Enemy(){
    // Sets up the default variables for the enemy.

    // Sets health to max.
    health = 100;

    // Sets experience amount to 0, just an initialization for the child classes to modify.
    ExperienceAmount = 0;

    // For aesthetic purposes of changing colors in the console.
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

int Enemy::Attack(){
    // Returns damage hit for the player. Uses random number to select enemy's move.

  int selector = rand()%9;
    switch(selector){
        case 0: case 1:
            // 2/9 chance of risk attacking.
            return RiskAttack();
            break;
        case 2: case 3:
            // 2/9 chance of healing.
            Heal();
            return 0;
            break;
        case 4: case 5: case 6: case 7: case 8:
            // 5/9 chance of generically attacking.
            return GenericAttack();
            break;
        default:
            // Returns 0 damage in case selector goes wrong.
            return 0;
            break;
    }
}

void Enemy::TakeDamage(int damage){
    // Doesn't subtract damage points if player chooses to quit.
    if (damage == -1){
        IsPlaying = false;
        return;
    }

    // Simply subtracts the damage player deals to the enemy.
    health -= damage;
}

bool Enemy::IsDead(){
    // Checks if the enemy's health is less than or equal to 0.

    if (health <= 0){
        // Prints that the enemy is defeated.
        DisplayName();
        cout << " is defeated!" << endl << endl;
        Sleep(SLEEP_MS);
        return true;
    }
    return false;
}

void Enemy::DisplayHealthBar(){
    // Displays the enemy's health bar.

    SetConsoleTextAttribute(hConsole, GREY);

    cout << "\t";
    string healthBar = "        " + std::to_string(health);

    for (int i = healthBar.length(); i < 20; i++)
        healthBar += " ";

    for (int i = 0; i < healthBar.length(); i++){
        if ((i+1)*10 <= health*2){
            SetConsoleTextAttribute(hConsole, RED_BACKGROUND);
            cout << healthBar.at(i);
        }
        else {
            SetConsoleTextAttribute(hConsole, GREY_BACKGROUND);
            cout << healthBar.at(i);
        }
    }

    SetConsoleTextAttribute(hConsole, GREY);
    cout << endl << endl;
}

void Enemy::DisplayName(){
    // Prints the enemy's name in dark gray.

    SetConsoleTextAttribute(hConsole, DARK_GREY);
    cout << name;
    SetConsoleTextAttribute(hConsole, GREY);
}

int Enemy::GetDrops(char selector){
    // Returns the number of items dropped when the enemy is defeated depending on the item won.

    return ReturnItemDrop(selector);
}

int Enemy::ReturnExperience(){
    // Returns the amount of experience the player gets when the enemy dies, or the amount of experience
    // lost if the player dies.
    return ExperienceAmount;
}

int Enemy::GenericAttack(){
    // Returns a generic attack, just a simple attack.

    int damage = ReturnDamage();

    // Prints how much damage the enemy deals to the player.
    DisplayName();
    cout << " attacks! It deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << damage;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " damage!" << endl << endl;
    return damage;
}

int Enemy::RiskAttack(){
    // Returns a risk attack, having a chance of dealing either very low points or high points.

    int damage = ReturnRiskDamage();

    // Prints how much damage the enemy deals to the player.
    DisplayName();
    cout << " takes a risk and attacks! It deals ";
    SetConsoleTextAttribute(hConsole, RED);
    cout << damage;
    SetConsoleTextAttribute(hConsole, GREY);
    cout << " damage!" << endl << endl;
    return damage;
}

void Enemy::Heal(){
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
    cout << " now has " << health << "HP!" << endl << endl;
}

int Enemy::ReturnItemDrop(char selector){
    int ArrowSelector = rand()%6;
    int WhetstoneSelector = rand()%2;
    int PotionSelector = rand()%10;
    switch(selector){
    case 'a':
        if (ArrowSelector<=1)
            return 0;
        else if (ArrowSelector==2||ArrowSelector==3)
            return 3;
        else
            return 5;
    case 'q':
        return QueensDrop;
    case 'w':
        if (WhetstoneSelector==1)
            return 1;
        else
            return 0;
    case 'p': case 'b':
        if (PotionSelector==0)
            return 1;
        else if (PotionSelector==1)
            return 2;
        else
            return 0;
    default:
        return 0;
        break;
    }
}
