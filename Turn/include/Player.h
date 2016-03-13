#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <Windows.h>

#include "Enemy.h"

class Player {
    // Contains the functions needed to construct the player's character.
    public:
        void SaveGame();

        std::string ReturnName();
        void SetPlayerData();
        int Attack();
        void TakeDamage(int);
        void AddToInventory(int, int, int, int, int);

        void DisplayHealthBar(Enemy*);
        void ReplenishHealth();
        bool IsDead();

        void DisplayName();

        void AddExperience(int);
        void LoseExperience(int);

        void AddQueens(int q);
        void LoseQueens(int);

        void DisplayInventory();

    private:
        int GenericAttack();
        int RiskAttack();
        int BowAndArrow();

        void UseWhetstone();
        void UsePotion();
        int UseBomb();
        void DeductDamage(int&);
        int ReturnBowDamage();
        void Heal();

        int Flee();


        virtual int ReturnDamage() = 0;
        virtual int ReturnRiskAttackDamage() = 0;
        virtual int ReturnHealAmount() = 0;

        std::string name;
        HANDLE hConsole;
        int level;
		int experience;
        int health;
        int whetstones;
        int arrows;
        int potions;
        int bombs;
        int weaponstrength;
        int queens;
};

#endif // PLAYER_H
