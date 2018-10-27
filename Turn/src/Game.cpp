#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>

#include "../include/Game.h"
#include "../include/Common.h"
#include "../include/Console.h"

#include "../include/PlayerTypes/PlayerTypes.h"
#include "../include/EnemyTypes/EnemyTypes.h"


using namespace std;
using namespace Common;

// To avoid conflict with numeric_limits<streamsize>::max used in Game::GetChoice()
#ifdef max
#undef max
#endif

#define SKIP_TURN -2

void Game::MainMenu(){
    // Main menu. Loops until you start
    // a game or quit.
	    for (int choice=-1; choice!=0;){
        choice = GetChoice(MenuType::eMain);
        switch(choice){
			case 1:
           		StartGame();
				break;
			case 2:
				HowToPlay();
				break;
			case 0:
				break;
        }
    }
}

string Game::InitializePlayerName() {
	ClearScreen();
	string name;
	cout << "What is your name?"
		<< endl << endl
		<< "> ";

  cin.ignore();
	getline(cin,name); // Change to full name
	return name;
}

char Game::InitializePlayerGender() {
    char gender;
    do {
        ClearScreen();
        cout << "What is your gender (M, F or O)?"
            << endl << endl
            << "> ";

        cin >> gender;
        gender = toupper(gender);
    } while (gender != 'M' && gender != 'F' && gender != 'O');

    return gender;
}


int Game::InitializePlayerClass() {
	// Initializes the player's class through user choice.
	int player_class = 0;
	player_class = GetChoice(MenuType::ePlayerClass);
	SetPlayerClass(player_class);
	return player_class;
}

void Game::SetPlayerClass(int player_class) {
	// Sets the Player class according to player code given.
	switch (player_class) {
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

void Game::SetPlayerData(){
	/* Data initialized in order of:
	* class code
	* name
	* level
	* experience
	* health
	* arrows
	* bombs
	* potions
	* whetstones
	* weaponstrength
	* coins
	*/

	ifstream ReadData;
	ReadData.open("data.txt");

	// Runs if user has never played the game before or data is not found.
	if (!ReadData) {
		ReadData.close();
		ofstream WriteData;
		WriteData.open("data.txt");

		WriteData << InitializePlayerClass() << endl
			<< InitializePlayerName() << endl
            << InitializePlayerGender() << endl
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
	}

	else {
		// Initializes player type from class code given in data.txt
		int player_class;
		ReadData >> player_class;
		SetPlayerClass(player_class);
		ReadData.close();
	}
}

void Game::SetEnemy(){
    // Generates a random integer to determine class of the enemy.
    // The abstract class Enemy is morphed with one of its child classes.

    EnemyType selector = EnemyType(rand()%etNumEnemyTypes);
    switch(selector)
    {
        case etSlimeball:
	    // Enemy is a slimeball.
	    _Enemy = new Slimeball;
            break;
        case etCrab:
            // Enemy is a crab.
            _Enemy = new Crab;
            break;
        case etGiantCrab:
            // Enemy is a giant crab.
            _Enemy = new GiantCrab;
            break;
        case etSquid:
            // Enemy is a squid.
            _Enemy = new Squid;
            break;
        case etGiantSquid:
            // Enemy is a giant squid.
            _Enemy = new GiantSquid;
            break;
		case etLich:
			// Enemy is a Lich
			_Enemy = new Lich;
			break;
		case etMurloc:
			//Enemy is a Murloc
			_Enemy = new Murloc;
			break;
		case etPutnafer:
			// Enemy is a Putnafer
			_Enemy = new Putnafer;
			break;
        case etZombie:
            // Enemy is a Zombie
            _Enemy = new Zombie;
            break;
		case etVampire:
			// Enemy is a Vampire
			_Enemy = new Vampire;
			break;
		case etWerewolf:
			// Enemy is a Werewolf
			_Enemy = new Werewolf;
			break;
		case etGoblin:
			// Enemy is a Goblin
			_Enemy = new Goblin;
			break;
		case etGargoyle:
			// Enemy is a Goblin
			_Enemy = new Gargoyle;
			break;
		case etCerberus:
			// Enemy is a Cerberus
			_Enemy = new Cerberus;
			break;
		case etSkeleton:
			// Enemy is a Rat
			_Enemy = new Skeleton;
			break;
		case etSmallRat:
			// Enemy is a Small Rat
			_Enemy = new SmallRat;
			break;
        default:
            // If the above cases do not match the selector for any reason,
            // the enemy defaults on the crab class.
            _Enemy = new Crab;
            break;
    }
    // Simply prints that the enemy's class was encountered.
	cout << _Enemy->GetIntro() << endl;
	Sleep(SLEEP_MS);
	ColourPrint(_Enemy->GetName(), Console::DarkGrey);
    cout << " encountered!" << endl << endl;
    Sleep(SLEEP_MS);
}

bool Game::PlayAgain(){
    // Returns a bool value to determine if the player wants to play again.

    char choice;
    cout << "Keep going? (y/n)" << endl << endl;
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
        cout << "*--------- Intermission ----------* " << endl << endl;

	_Player->DisplayInventory();
        cout << "1) Start battle" << endl;
        cout << "2) Store" << endl;
        cout << "3) Gamble" << endl;
	cout << "4) Use Item" << endl;
        cout << "0) Quit" << endl << endl;

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
	    _Player->UseItem();
	    _Player->SaveGame();
	    break;
        case 0:
            // Breaks the loop in StartGame(), going back to MainMenu().
            IsPlaying=false;
	    break;
        }
    }
}

void Game::StartGame(){
    // Starts the game by initializing values for a new game.

    // Seeds the random number generator for pseudo-random numbers.
    srand((unsigned int)time(NULL));
    IsPlaying=true;

    // SetPlayerData() initializes the variables in this end.
    ClearScreen();
    SetPlayerData();

	// This initializes the variables on the Player end.
    ClearScreen();
    _Player->SetPlayerData();


    // Loops while the game is still playing.
    // Alternates between battles and intermission (gambling, store, et)
    while(IsPlaying){
		Intermission();
		if (!IsPlaying)
			break;
		Battle();
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
        _Player->DisplayHUD(_Enemy);
        _Enemy->DisplayHUD();

		int damagePlayer = _Player->Action();
        // Player's turn to attack Enemy or choose other action.

		if (damagePlayer != SKIP_TURN){
			_Enemy->TakeDamage(damagePlayer);
			// Pauses console and ignores user input for SLEEP_MS milliseconds.
        		Sleep(SLEEP_MS);
		}


        // Leaves battle if player chooses to.
        if (!IsPlaying){
            IsPlaying = true;
            return;
        }

        // Executes when the enemy's health is 0 or below.
        if (_Enemy->IsDead()){
            // Adds drops to player's inventory from defeated enemy.
            _Player->AddToInventory(_Enemy->GetDrops());
            // Adds points to player's experience.
            _Player->AddExperience(_Enemy->ReturnExperience());
			// Replenishes player's health for the next round.
			_Player->ReplenishHealth();

			// If player wants to battle again, it breaks the loop and uses tail recursion to play again.
            if (PlayAgain()) break;
            // Returns to StartGame()'s loop, and executes Intermission().
            return;
        }

        // Enemy's turn to attack player.
		if (damagePlayer != SKIP_TURN)
			_Player->TakeDamage(_Enemy->Action());
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

void Game::HowToPlay() {

	GetChoice(MenuType::eHowToPlay);
}

int Game::GetChoice(MenuType menuType)
{
	DisplayMenu(menuType);
	int choice = -1;
	while (!(cin >> choice)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Please try again.";
		Sleep(SLEEP_MS);
		DisplayMenu(menuType);
	}
	return choice;
}

void Game::DisplayMenu(MenuType menuType)
{
	ClearScreen();
	switch (menuType)
	{
	case Game::eMain:
		cout << "========== TURN-BASED FIGHTING GAME ==========" << endl << endl
			<< "1) Start Game" << endl
			<< "2) How to play" << endl
			<< "0) Exit" << endl << endl << "> ";
		break;
	case Game::ePlayerClass:
		cout << endl
			<< "Which class do you want to play as?" << endl
			<< "1) Warrior (high damage, low healing capabilities)" << endl
			<< "2) Rogue (moderate damage, moderate healing capabilities)" << endl
			<< "3) Healer (low damage, high healing capabilities)" << endl
			<< "4) Debugger (INFINITE DAMAGE!!!!)" << endl
			<< "5) Saitama (self-explanatory)" << endl
			<< endl << endl
			<< "> ";
		break;
	case Game::eHowToPlay:
		cout << "============== HOW TO PLAY ==============" << endl << endl
			<< "Turn is a turn-based RPG game." << endl
			<< "Create your character and start playing." << endl
			<< "For playing you have to choose what to do by typing" << endl
			<< "the corresponding number." << endl
			<< "You can perform actions and use items." << endl << endl
			<< "-- Actions --" << endl
			<< "Attack: Regular attack" << endl
			<< "Risk Attack: Attack deals more damage, but with a chance of missing" << endl
			<< "Heal: Restore an amount of your HP" << endl
			<< "Flee: Run away from battle" << endl << endl
			<< "-- Items --" << endl
			<< "Bombs: Deals 50HP to your opponent with no chance of missing" << endl
			<< "Arrows: Deals 10-15HP to your opponent with no chance of missing" << endl
			<< "Potion: Replenishes your HP to 100" << endl
			<< "Whetstone: Restores your weapon's sharpness." << endl << endl
			<< "Good luck and have fun!" << endl << endl
			<< "0) Quit" << endl << endl << "> ";
		break;
	default:
		break;
	}
}
