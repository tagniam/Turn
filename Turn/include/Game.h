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
        void SetPlayerData();
		int InitializePlayerClass();
		void SetPlayerClass(int);
		std::string InitializePlayerName();

        void SetEnemy();
        bool PlayAgain();
        void Intermission();

        void StartGame();
        void Battle();
		void HowToPlay();

        // Pointers needed to call functions from respective classes.
        // They are pointers because they have child classes (they polymorph).
        Player *_Player;
        Enemy *_Enemy;
        // This object is not a pointer because it does not have a child class.
        Gambling _Gambling;
        Store _Store;

};

#endif // GAME_H
