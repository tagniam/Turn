#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

// Common functions and data to share across all files.
namespace Common {
    void ClearScreen();
    int input();

    // Indicates if the game is still going.
    extern bool IsPlaying;
    extern const int SLEEP_MS;

	// Colours for the game
	extern const int GREY;
	extern const int DARK_GREY;
	extern const int RED;
	extern const int RED_BACKGROUND;
	extern const int GREY_BACKGROUND;

	// Number of items held in inventory.
	extern const int NUM_ITEMS;
}



#endif // COMMON_H_INCLUDED
