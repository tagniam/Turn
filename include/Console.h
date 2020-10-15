#pragma once
#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

class Console {
  public:
    enum EColour {
        Grey = 0,
        DarkGrey,
        Red,
        Green,

        Background_Red,
        Background_Grey,
        Background_DarkGrey,

        // Aliases for easy changing of defaults
        Default = Grey,
        DefaultBackgroun = Background_Grey,
    };

    void ClearScreen();

    char GetChar() const;

    void SetColour(EColour colour);

    static Console& GetInstance();
  private:
    // Private constructor for the singleton
    Console();

    // Copy constructor private and unimplemented for this singleton
    Console(Console&) = delete;

#ifdef _WIN32
    HANDLE m_hConsoleHandle;
#endif // _WIN32
};

#endif // CONSOLE_H_INCLUDED
