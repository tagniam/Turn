#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>

#include "..\include\Common.h"
using namespace std;


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

void Common::ColourPrint(string text, const int COLOUR){
	SetConsoleTextAttribute(hConsole, COLOUR);
	cout << text;
	SetConsoleTextAttribute(hConsole, GREY);
}

bool Common::IsPlaying;

const int Common::SLEEP_MS = 600;

const int Common::GREY = 7;
const int Common::DARK_GREY = 8;
const int Common::RED = 12;
const int Common::GREEN = 10;
const int Common::RED_BACKGROUND = 207;
const int Common::GREY_BACKGROUND = 127;

const int Common::NUM_ITEMS = 5;

const HANDLE Common::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);