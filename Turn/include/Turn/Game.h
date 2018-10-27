#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Gambling.h"
#include "Store.h"

class Game {
    public:
        void MainMenu();

    private:

		enum MenuType {
			eMain = 0,
			ePlayerClass,
			eHowToPlay
		};

        void SetPlayerData();
		int InitializePlayerClass();
		void SetPlayerClass(int);
		std::string InitializePlayerName();
        char InitializePlayerGender();

        void SetEnemy();
        bool PlayAgain();
        void Intermission();

        void StartGame();
        void Battle();
		void HowToPlay();

		int GetChoice(MenuType menuType);
		void DisplayMenu(MenuType menuType);

        // Pointers needed to call functions from respective classes.
        // They are pointers because they have child classes (they polymorph).
        Player *_Player;
        Enemy *_Enemy;
        // This object is not a pointer because it does not have a child class.
        Gambling _Gambling;
        Store _Store;
        // the current level the player is at it this is different than what is in the _player object the player leveled up
        int _Level;

};

#endif // GAME_H
