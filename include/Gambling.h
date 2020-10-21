#ifndef GAMBLING_H
#define GAMBLING_H

#include "Player.h"

class Gambling {
    // Contains the functions needed to simulate a gamble for items.

    public:
        void Gamble(Player*);
    private:
        void GenerateValues();
        int ReturnShakenDie();
        char ReturnItem();
        void WinGamble(Player*);
        void LoseGamble(Player*);

        // Variables needed for the gamble.

        // The die number required to win the gamble. Player's die must be equal or greater than requirement to win.
        int DieRequirement;
        // Amount of coins deducted if gamble is lost.
        int CoinsDeduction;
        // Amount of items won, if gamble is won.
        int ItemNumber;
        // Character identifying the item won.
        //      0 -> Arrows
        //      1 -> Bombs
        //      2 -> Potions
        //      3 -> Whetstones
        //      4 -> Molotovs
        int Item;
};

#endif // GAMBLING_H
