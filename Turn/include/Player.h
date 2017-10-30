#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Enemy.h"
#include "Sound.h"

class Player : public Entity, public SoundMaker {
    // Contains the functions needed to construct the player's character.
    public:
		Player(void);
        void SaveGame();

        void SetPlayerData();
        int Action();
	void UseItem();
        void AddToInventory(std::vector<int>);
	void AddStoreItemToInventory(int);

        void DisplayHUD(Enemy*);
        void ReplenishHealth();

        void AddExperience(int);
        void LoseExperience(int);

        void AddCoins(int);
        void LoseCoins(int);

        void DisplayInventory();
        int GetCoins();

    private:
        int GenericAttack();
        int RiskAttack();
        int BowAndArrow();

        void UseWhetstone();
        void UsePotion();
        int UseBomb();
        void DeductDamage(int&);
        int ReturnBowDamage();

        int Flee();

        void PrintInventoryItem(std::string, int, std::string);
        void PrintXPBar(std::string, int, std::string, std::string, int, std::string);
        void PrintDivider(char, char, std::string);


	int player_type;
        int level;
        char gender;
	int experience;
        int whetstones;
        int arrows;
        int potions;
        int bombs;
        int weaponstrength;
        int coins;
};

#endif // PLAYER_H
