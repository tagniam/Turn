#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <Windows.h>

class Enemy {
    public:
        Enemy();

        int Attack();
        void TakeDamage(int);
        bool IsDead();

        void DisplayHealthBar();
        void DisplayName();

        int GetDrops(char);
        int ReturnExperience();

    protected:
        int GenericAttack();
        int RiskAttack();
        void Heal();

        virtual int ReturnDamage() = 0;
        virtual int ReturnRiskDamage() = 0;
        virtual int ReturnHealAmount() = 0;

        int ReturnItemDrop(char);

        std::string name;
        int ExperienceAmount;
        int QueensDrop;
        int health;
    private:
        HANDLE hConsole;

};

#endif // ENEMY_H
