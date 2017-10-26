#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include "../include/Console.h"

// Common functions and data to share across all files.
namespace Common {
    void ClearScreen();
    int input();

	void ColourPrint(std::string, Console::EColour colour);

	void Sleep(int ms);

    // Indicates if the game is still going.
    extern bool IsPlaying;
    extern const int SLEEP_MS;

	// Number of items held in inventory.
	extern const int NUM_ITEMS;
}



#endif // COMMON_H_INCLUDED
