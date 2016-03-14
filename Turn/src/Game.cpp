#include <iostream>
#include <ctime>
#include <fstream>
#include <Windows.h>

#include "..\include\Game.h"
#include "..\include\Common.h"

#include "..\include\PlayerTypes\PlayerTypes.h"
#include "..\include\EnemyTypes\EnemyTypes.h"


using namespace std;
using namespace Common;



void Game::MainMenu(){
    // Main menu. Loops until you start
    // a game or quit.
    for (int choice=0; choice!=2;){
        ClearScreen();
        cout << "========== TURN-BASED FIGHTING GAME ==========" << endl << endl
             << "1) Start Game" << endl
             << "2) Quit" << endl << endl << "> ";
        cin >> choice;
        switch(choice){
        case 1:
            StartGame();
        // There's no 'case 2' because it breaks
        // the loop already.
        }
    }
}

/// Reset this function to work with save files for different users.
void Game::SetPlayerData(){
    // Sets the player's class. Uses user input to determine their class.
    // The abstract class Player is morphed with one of its child classes.

    int choice = 0;
    cout << endl
         << "Which class do you want to play as?" << endl
         << "1) Warrior (high damage, low healing capabilities)" << endl
         << "2) Rogue (moderate damage, moderate healing capabilities)" << endl
         << "3) Healer (low damage, high healing capabilities)" << endl
         << "4) Debugger (INFINITE DAMAGE!!!!)" << endl
         << "5) Saitama (self-explanatory)" << endl
         << endl << endl
         << "> ";
    cin >> choice;
    switch(choice){
        case 1:
            // Player's class is a warrior.
            _Player = new Warrior;
            break;
        case 2:
            // Player's class is a rogue.
            _Player = new Rogue;
            break;
        case 3:
            // Player's class is a healer.
            _Player = new Healer;
            break;
        case 4:
            // Player's class is a debugger.
            // Used to easily defeat enemies. Only for development purposes.
            _Player = new Debugger;
            break;
        case 5:
            // You are Saitama.
            // Do I have to explain??
            _Player = new Saitama;
            break;
        default:
            // If input does not equal any of the cases, the default class is a warrior.
            _Player = new Warrior;
            break;
    }
}

void Game::SetEnemy(){
    // Generates a random integer to determine class of the enemy.
    // The abstract class Enemy is morphed with one of its child classes.

    int selector = rand()%4;
    switch(selector){
        case 0:
            // Enemy is a crab.
            _Enemy = new Crab;
            break;
        case 1:
            // Enemy is a giant crab.
            _Enemy = new GiantCrab;
            break;
        case 2:
            // Enemy is a squid.
            _Enemy = new Squid;
            break;
        case 3:
            // Enemy is a giant squid.
            _Enemy = new GiantSquid;
            break;
        default:
            // If the above cases do not match the selector for any reason,
            // the enemy defaults on the crab class.
            _Enemy = new Crab;
            break;
    }
    // Simply prints that the enemy's class was encountered.
    _Enemy->DisplayName();
    cout << " encountered!" << endl << endl;
    Sleep(SLEEP_MS);
}

bool Game::PlayAgain(){
    // Returns a bool value to determine if the player wants to play again.

    char choice;
    cout << "Keep going? (y/n)" << endl << endl << "> ";
    choice = (char)input();
    // Returns true if the player says yes (Y, y, 1).
    if (choice == 'y' || choice == 'Y' || choice == '1') return true;
    // Returns false otherwise, regardless of choice=='n'.
    return false;
}


void Game::Intermission(){
    // Saves game in case player unexpectedly quits (uses X instead of
    // in-game quit.
    _Player->SaveGame();

    // Loops until the player starts another battle or they quit (IsPlaying=false).
    for (int choice=0; IsPlaying;){
        ClearScreen();
        cout << "*----- Intermission -----* " << endl << endl;
        _Player->DisplayInventory();
        cout << "1) Start battle" << endl;
        cout << "2) Store" << endl;
        cout << "3) Gamble" << endl;
        cout << "4) Quit" << endl << endl;

        choice = input();

        switch(choice){
        case 1:
            // Returns to StartGame()'s loop, calling Battle().
            return;
        case 2:
            // Goes to the store where the player can buy items.
            /// Currently in working progress.
            _Store.StoreFront(_Player);
            break;
        case 3:
            // Goes to the gambling arena.
            // _Player is passed in to add items won to the player inventory.
            _Gambling.Gamble(_Player);
            break;
        case 4:
            // Breaks the loop in StartGame(), going back to MainMenu().
            IsPlaying=false;
        }
    }
}

void Game::StartGame(){
    // Starts the game by initializing values for a new game.

    // Seeds the random number generator for pseudo-random numbers.
    srand(time(NULL));
    IsPlaying=true;

    // SetPlayerData() makes the player choose their class.
    ClearScreen();
    SetPlayerData();

    // _Player->SetName() sets the name of the player.
    ClearScreen();
    _Player->SetPlayerData();
    //_Player->SetName();

    // Loops while the game is still playing.
    // Alternates between battles and intermission (gambling, store, et)
    while(IsPlaying){
        Battle();
        Intermission();
    }

    // Saves the player's data to an external file before quitting.
    _Player->SaveGame();
}

void Game::Battle(){
    ClearScreen();
    // Uses random integers to determine class of the enemy.
    SetEnemy();

    // Loops the actual battle while playing.
    while(IsPlaying){
        ClearScreen();
        // Displays the name and health bar of the player and enemy.
        // The Enemy* argument is to display the enemy's
        // name. Explained more in _Player->DisplayHealthBar().
        _Player->DisplayHealthBar(_Enemy);
        _Enemy->DisplayHealthBar();

        // Player's turn to attack Enemy.
        _Enemy->TakeDamage(_Player->Attack());
        // Pauses console and ignores user input for SLEEP_MS milliseconds.
        Sleep(SLEEP_MS);

        // Leaves battle if player chooses to.
        if (!IsPlaying){
            IsPlaying = true;
            return;
        }

        // Executes when the enemy's health is 0 or below.
        if (_Enemy->IsDead()){
            // Adds points to player's experience.
            _Player->AddExperience(_Enemy->ReturnExperience());
            // Adds drops to player's inventory from defeated enemy.
            /// Not very efficient with its arguments, must fix that later.
            _Player->AddToInventory(_Enemy->GetDrops('a'), _Enemy->GetDrops('w'), _Enemy->GetDrops('p'), _Enemy->GetDrops('b'), _Enemy->GetDrops('q'));
			// Replenishes player's health for the next round.
			_Player->ReplenishHealth();
			
			// If player wants to battle again, it breaks the loop and uses tail recursion to play again.
            if (PlayAgain()) break;
            // Returns to StartGame()'s loop, and executes Intermission().
            return;
        }

        // Enemy's turn to attack player.
        _Player->TakeDamage(_Enemy->Attack());
        Sleep(SLEEP_MS);

        // Executes when player's health is 0 or below.
        if (_Player->IsDead()){
            // Player loses the amount of experience points gained when you defeat the enemy.
            _Player->LoseExperience(_Enemy->ReturnExperience());
			// Replenishes player's health for the next round.
			_Player->ReplenishHealth();
			
			if (PlayAgain()) break;
            return;
        }
    }
    Battle();
}
