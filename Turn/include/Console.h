#pragma once
#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#ifdef _WINDOWS
#include <Windows.h>
#endif // _WINDOWS

class Console {
public:
	enum EColour {
		Grey = 0,
		DarkGrey,
		Red,
		Green,

		Background_Red,
		Background_Grey,

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

#ifdef _WINDOWS
	HANDLE m_hConsoleHandle;
#endif // _WINDOWS
};

#endif // CONSOLE_H_INCLUDED