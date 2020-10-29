#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <random>

#include "../include/Common.h"
using namespace std;

void Common::ClearScreen() {
    Console::GetInstance().ClearScreen();
}

int Common::input() {
    // Converts character code to number, returns.
    while (true) {
        // Gets character code for input.
        int getchCode = Console::GetInstance().GetChar();
        if (getchCode >= 48 && getchCode <= 57) {
            return getchCode-48;
        }
        // Yes/no return
        else if (getchCode == 121 || getchCode == 89 || getchCode == 110 ||
                 getchCode == 78) {
            return getchCode;
        }
    }
}

void Common::ColourPrint(string text, Console::EColour colour) {
    Console::GetInstance().SetColour(colour);
    cout << text;
    Console::GetInstance().SetColour(Console::Default);
}

void Common::Sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int Common::RandomInt(int min, int max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

bool Common::IsPlaying;

const int Common::SLEEP_MS = 800;

const int Common::NUM_ITEMS = 5;
