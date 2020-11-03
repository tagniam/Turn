#include <iostream>
//#include <conio.h>
#include <vector>

#include "../include/Common.h"
#include "../include/Gambling.h"
#include "../include/Player.h"

using namespace std;
using namespace Common;

// Contains the functions needed to simulate a gamble for items.

void Gambling::Gamble(Player *_Player) {
    // A gambling arena, in which the die you roll must be equal or higher than requirement
    // Uses the Player object passed in to give won items to player.
    /// Maybe check Coins? If too low then can't gamble.
    // Generates random values for the local variables declared in the class.
    GenerateValues();
    // check if the player has enough money to play
    if (_Player->GetCoins() < CoinsDeduction) {
        // the player does not have enough money
        cout << "You need at least " << CoinsDeduction << " coins to gamble." << endl;
        Sleep(SLEEP_MS);
        return;
    }
    // Player's die. Equal to a random number between 1 and 9.
    int Die=ReturnShakenDie();
    // Initialized to analyze user input.
    int choice = 0;
    // Loops until player chooses to reveal die.
    while (choice!=1) {
        /// Since the ClearScreen() method is in class Game, system("CLS") is used instead.
        /// Must fix.
        ClearScreen();
        // Prints required die number to win gamble.
        /// Currently says 'REQUIREMENT: 9 and over' when DieRequirement==9, when dies cannot go over 9.
        cout << endl << "REQUIREMENT: " << DieRequirement << " and over" << endl;
        // Prints the amount of items received if gamble is won.
        cout << "PRIZE: [" << ItemNumber << "] ";
        // Prints the item name according to the char Item.
        cout << Item;
        // Prints Coins deduction if you lose the gamble.
        cout << "PENALTY: [" << CoinsDeduction << "] coins" << endl << endl;
        cout << "1) Reveal Die" << endl;
        cout << "2) Shake Die" << endl;
        cout << "0) Pass" << endl << "\n";
        choice = input();
        switch (choice) {
        case 1:
            // Only breaks because the loop stops since choice==1.
            break;
        case 2:
            cout << "You shake the die." << endl;
            Sleep(SLEEP_MS);
            // Generates another random number for the die, simulating the real life die shake.
            Die=ReturnShakenDie();
            break;
        case 0:
            // Returns to Intermission().
            return;
        default:
            break;
        }
    }
    // Prints what you rolled.
    cout << "You rolled a " << Die << "." << endl;
    Sleep(SLEEP_MS);
    // Evaluates whether or not you won the bet.
    if (Die>=DieRequirement)
        // Passes in Player object to give player the items won.
    {
        WinGamble(_Player);
    } else
        // Passes in Player object to deduct experience from the player for losing the gamble.
    {
        LoseGamble(_Player);
    }
}

void Gambling::GenerateValues() {
    // Generates values for the variables used in the gamble.
    // Generates a number between 1 and 9, the number that  the player's die must be equal to or greater than.
    DieRequirement = Common::RandomInt(1, 9);
    // The amount of items won if the player win the gamble.
    ItemNumber = Common::RandomInt(1, 4);
    // The amount of experience lost if the player loses the gamble.
    CoinsDeduction=100;
    // Initializes Item equal to a random char to indicate the item won.
    Item=ReturnItem();
}

int Gambling::ReturnShakenDie() {
    // Returns a random integer between 1 and 9.
    return Common::RandomInt(1, 9);
}

ITEMTYPE Gambling::ReturnItem() {
    // Generates a random char with a random integer selector, indicating the item won in the gamble.
    int selector=Common::RandomInt(0, 3);
    switch(selector) {
    case 0:
        // Arrows are the item.
        return ITEMTYPE::ARROWS;
    case 1:
        // Bombs are the item.
        return ITEMTYPE::BOMB;
    case 2:
        // Potions are the item.
        return ITEMTYPE::POTION;
    case 3:
        // Whetstones are the item.
        return ITEMTYPE::WHETSTONE;
    default:
        // By default, arrows are the item if the random integer does not equal any of the above cases.
        return ITEMTYPE::ARROWS;
    }
}

void Gambling::WinGamble(Player *_Player) {
    // Executes the events when the gamble is won.
    // Uses the Player object to give player items won.
    cout << "You win the bet!" << endl;
    pair<ITEMTYPE, int> drop;
    drop = make_pair(Item, ItemNumber);
    // Evaluates local class variable Item to see what item was won.
    // ItemNumber is passed in to AddToInventory() to provide the number of items won.
    // The place of ItemNumber in the arguments is to specify which item was won.
    // More clarification and information in the _Player->AddToInventory(int, int, int ,int) function.
    _Player->AddToInventory(drop);
    // Used to pause the console to let the player see what they won.
    /// Must use something more efficient.
    system("PAUSE");
}

void Gambling::LoseGamble(Player *_Player) {
    // Executes the events when gamble is lost.
    // Uses the Player object passed in to deduct experience.
    cout << "You lost the bet! You lose " << CoinsDeduction << " coins!" << endl;
    // Deducts the player's experience.
    _Player->LoseCoins(CoinsDeduction);
    system("PAUSE");
}
