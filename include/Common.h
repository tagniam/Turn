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
        std::vector <int> indices;
        int index = 0; // The possible indices for the outcomes vector
        for (int weight : weights) {
            for (int i = 0; i < weight; i++) {
                indices.push_back(index);
            }
            index++;
        }

        int randomIndex = indices.at(RandomInt(0, indices.size()-1));
        return outcomes.at(randomIndex);
    }

    // Indicates if the game is still going.
    extern bool IsPlaying;
    extern const int SLEEP_MS;

    // Number of items held in inventory.
    extern const int NUM_ITEMS;
}

#endif // COMMON_H_INCLUDED
