#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "..\include\Common.h"
#include "..\include\Gambling.h"
#include "..\include\Player.h"

using namespace std;
using namespace Common;

// Contains the functions needed to simulate a gamble for items.

void Gambling::Gamble(Player *_Player){
    // A gambling arena, in which the die you roll must be equal or higher than requirement
    // Uses the Player object passed in to give won items to player.

    /// Maybe check Queens? If too low then can't gamble.


    // Generates random values for the local variables declared in the class.
    GenerateValues();
    // Player's die. Equal to a random number between 1 and 9.
    int Die=ReturnShakenDie();
    // Initialized to analyze user input.
    int choice = 0;

    // Loops until player chooses to reveal die.
    while (choice!=1){
        /// Since the ClearScreen() method is in class Game, system("CLS") is used instead.
        /// Must fix.
        ClearScreen();

        // Prints required die number to win gamble.
        /// Currently says 'REQUIREMENT: 9 and over' when DieRequirement==9, when dies cannot go over 9.
        cout << endl << "REQUIREMENT: " << DieRequirement << " and over" << endl;
        // Prints the amount of items received if gamble is won.
        cout << "PRIZE: [" << ItemNumber << "] ";
        // Prints the item name according to the char Item.
        switch(Item){
        case 'b':
            cout << "bombs" << endl;
            break;
        case 'p':
            cout << "potions" << endl;
            break;
        case 'w':
            cout << "whetstones" << endl;
            break;
        case 'a':
            cout << "arrows" << endl;
            break;
        default:
            // No default, since ReturnItem(), which GenerateValue() calls, already has one.
            // Technically impossible for char Item to be other than b, p, w, a.
            break;
        }

        // Prints Queens deduction if you lose the gamble.
        cout << "PENALTY: [" << QueensDeduction << "] Queens" << endl << endl;

        cout << "1) Reveal Die" << endl;
        cout << "2) Shake Die" << endl;
        cout << "3) Pass" << endl << "\n";
        
        choice = input();
        switch (choice){
        case 1:
            // Only breaks because the loop stops since choice==1.
            break;
        case 2:
            cout << "You shake the die." << endl;
            Sleep(SLEEP_MS);
            // Generates another random number for the die, simulating the real life die shake.
            Die=ReturnShakenDie();
            break;
        case 3:
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
        WinGamble(_Player);
    else
        // Passes in Player object to deduct experience from the player for losing the gamble.
        LoseGamble(_Player);
}

void Gambling::GenerateValues(){
    // Generates values for the variables used in the gamble.

    // Generates a number between 1 and 9, the number that  the player's die must be equal to or greater than.
    DieRequirement=1+rand()%9;
    // The amount of items won if the player win the gamble.
    ItemNumber=1+rand()%4;
    // The amount of experience lost if the player loses the gamble.
    QueensDeduction=100;
    // Initializes Item equal to a random char to indicate the item won.
    Item=ReturnItem();
}

int Gambling::ReturnShakenDie(){
    // Returns a random integer between 1 and 9.
    return 1+rand()%9;
}

char Gambling::ReturnItem(){
    // Generates a random char with a random integer selector, indicating the item won in the gamble.
  int selector=rand()%4;
    switch(selector){
    case 0:
        // Arrows are the item.
        return 'a';
    case 1:
        // Bombs are the item.
        return 'b';
    case 2:
        // Potions are the item.
        return 'p';
    case 3:
        // Whetstones are the item.
        return 'w';
    default:
        // By default, arrows are the item if the random integer does not equal any of the above cases.
        return 'a';
    }
}

void Gambling::WinGamble(Player *_Player){
    // Executes the events when the gamble is won.
    // Uses the Player object to give player items won.

    cout << "You win the bet!" << endl;

    // Evaluates local class variable Item to see what item was won.
    // ItemNumber is passed in to AddToInventory() to provide the number of items won.
    // The place of ItemNumber in the arguments is to specify which item was won.
    // More clarification and information in the _Player->AddToInventory(int, int, int ,int) function.
    switch(Item){
    case 'a':
        // Arrows were won.
        _Player->AddToInventory(ItemNumber, 0, 0, 0, 0);
        break;
    case 'b':
        // Bombs were won.
        _Player->AddToInventory(0, 0, 0, ItemNumber, 0);
        break;
    case 'p':
        // Potions were won.
        _Player->AddToInventory(0, 0, ItemNumber, 0, 0);
        break;
    case 'w':
        // Whetstones were won.
        _Player->AddToInventory(0, ItemNumber, 0, 0, 0);
        break;
    default:
        // Technically impossible for Item not equaling above cases.
        break;
    }
    // Used to pause the console to let the player see what they won.
    /// Must use something more efficient.
    system("PAUSE");
}

void Gambling::LoseGamble(Player *_Player){
    // Executes the events when gamble is lost.
    // Uses the Player object passed in to deduct experience.

    cout << "You lost the bet! You lose " << QueensDeduction << " Queens!" << endl;

    // Deducts the player's experience.
    _Player->LoseQueens(QueensDeduction);
    system("PAUSE");
}
