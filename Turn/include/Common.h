#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <Windows.h>

// Common functions and data to share across all files.
namespace Common {
    void ClearScreen();
    int input();

	void ColourPrint(std::string, const int);

    // Indicates if the game is still going.
    extern bool IsPlaying;
    extern const int SLEEP_MS;

	// Colours for the game
	extern const int GREY;
	extern const int DARK_GREY;
	extern const int RED;
	extern const int GREEN;
	extern const int RED_BACKGROUND;
	extern const int GREY_BACKGROUND;

	// Number of items held in inventory.
	extern const int NUM_ITEMS;

	// Needed for colourize function
	extern const HANDLE hConsole;
}



#endif // COMMON_H_INCLUDED
