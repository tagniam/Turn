#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

// Common functions and data to share across all files.
namespace Common {
    // Sorry, I'm Canadian.
    /*extern struct Colours;
    extern Colours _Colours;*/
    void ClearScreen();
    int input();

    // Indicates if the game is still going.
    extern bool IsPlaying;
    const int SLEEP_MS = 600;

	// Colours for the game
	extern const int GREY;
	extern const int DARK_GREY;
	extern const int RED;
	extern const int RED_BACKGROUND;
	extern const int GREY_BACKGROUND;
}



#endif // COMMON_H_INCLUDED
