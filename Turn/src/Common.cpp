#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "../include/Common.h"
using namespace std;

void Common::ClearScreen(){
		Console::GetInstance().ClearScreen();
}

int Common::input(){
    // Converts character code to number, returns.
    while (true){
        // Gets character code for input.
		int getchCode = Console::GetInstance().GetChar();

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

void Common::ColourPrint(string text, Console::EColour colour){
	Console::GetInstance().SetColour(colour);
	cout << text;
	Console::GetInstance().SetColour(Console::Default);
}

void Common::Sleep(int ms){
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

bool Common::IsPlaying;

const int Common::SLEEP_MS = 600;

const int Common::NUM_ITEMS = 5;