#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Enemy.h"

class Player : public Entity {
    // Contains the functions needed to construct the player's character.
    public:
        void SaveGame();

        void SetPlayerData();
        int Attack();
	void UseItem();
        void AddToInventory(std::vector<int>);

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

        void printInventoryItem(std::string, int, std::string);
        void printXPBar(std::string, int, std::string, std::string, int, std::string);
        void printDivider(char, char, std::string);


	int player_type;
        int level;
	int experience;
        int whetstones;
        int arrows;
        int potions;
        int bombs;
        int weaponstrength;
        int coins;
};

#endif // PLAYER_H
