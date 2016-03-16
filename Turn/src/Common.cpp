#include <conio.h>
#include <Windows.h>

#include "..\include\Common.h"

void Common::ClearScreen(){
        // Clears the screen using system() function.
        /// Not very efficient, but does the job.
        system("CLS");
}

int Common::input(){
    // Converts character code to number, returns.
    while (true){
        // Gets character code for input.
        int getchCode = _getch();

        if (getchCode >= 48 && getchCode <= 57){
            return getchCode-48;
        }

        // Yes/no return
        else if (getchCode == 121 || getchCode == 89 || getchCode == 110 ||
                 getchCode == 78){
            return getchCode;
        }
    }
}

bool Common::IsPlaying;

const int Common::GREY = 7;
const int Common::DARK_GREY = 8;
const int Common::RED = 12;
const int Common::RED_BACKGROUND = 207;
const int Common::GREY_BACKGROUND = 127;