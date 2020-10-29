#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

#include "../include/Console.h"

// Common functions and data to share across all files.
namespace Common {
    void ClearScreen();
    int input();

    void ColourPrint(std::string, Console::EColour colour);

    void Sleep(int ms);

    int RandomInt(int min, int max);

    template <typename T>
    T RandomEvent(std::vector<int> weights, std::vector<T> outcomes) {
        std::vector <int> events;
        int k = 0;
        for (auto it : weights)
        {
            for (int i = 0; i < it; i++)
            {
                events.push_back(k);
            }
            k++;
        }

        int denominator = std::accumulate(weights.begin(), weights.end(), 0);
        int rIndex = Common::RandomInt(0, denominator-1);
        int outIndex = events.at(rIndex);
        return outcomes.at(outIndex);
    }

    // Indicates if the game is still going.
    extern bool IsPlaying;
    extern const int SLEEP_MS;

    // Number of items held in inventory.
    extern const int NUM_ITEMS;
}

#endif // COMMON_H_INCLUDED
