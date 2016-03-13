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
}



#endif // COMMON_H_INCLUDED
