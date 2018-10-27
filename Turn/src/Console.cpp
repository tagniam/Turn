#include "Turn/Console.h"
#ifdef _WINDOWS
#include <Windows.h>
#include <conio.h>
#else
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#endif // _WINDOWS

Console::Console() {
#if defined(_WINDOWS)
	m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}

void Console::ClearScreen() {
#ifdef _WINDOWS
	system("cls");
#else
	system("clear");
#endif // _WINDOWS
}

char Console::GetChar() const {
#ifdef _WINDOWS
	return _getch();
#else
	// The following code attempts to manually reproduce the same behaviour as the
	// getch function from Windows' conio.h

	// Cache the existing terminal attributes
	struct termios cachedAttributes, customAttributes;
	tcgetattr(STDIN_FILENO, &cachedAttributes);

	// Copy them, and change the flags needed to achieve getch-style behaviour
	customAttributes = cachedAttributes;
	customAttributes.c_lflag &= ~(ICANON | ECHO);

	// Set the attributes to the new ones, read a character with getchar
	tcsetattr(STDIN_FILENO, TCSANOW, &customAttributes);
	int ch = getchar();

	// Restore the original terminal attribute setup
	tcsetattr(STDIN_FILENO, TCSANOW, &cachedAttributes);

	// Return the character that was read
	return ch;
#endif // _WINDOWS
}

void Console::SetColour(EColour colour) {
#ifdef _WINDOWS
	enum WindowsAttributes
	{
		GREY = 7,
		DARK_GREY = 8,
		RED = 12,
		GREEN = 10,

		RED_BACKGROUND = 207,
		GREY_BACKGROUND = 127,
	};
	int colourMap[] =
	{
		GREY,			// EColour::Grey
		DARK_GREY,		// EColour::DarkGrey
		RED,			// EColour::Red
		GREEN,			// EColour::Green
		
		RED_BACKGROUND,	// EColour::Background_Red
		GREY_BACKGROUND,// EColour::Background_Grey
	};
	SetConsoleTextAttribute(m_hConsoleHandle, colourMap[colour]);
#else
	char const* const colourEscapeCodes[] =
	{
		"\033[0m\033[37m",	// EColour::Grey
		"\033[0m\033[90m",	// EColour::DarkGrey
		"\033[0m\033[31m",	// EColour::Red
		"\033[0m\033[32m",	// EColour::Green

		"\033[0m\033[41m",	// EColour::Background_Red
		"\033[0m\033[47m",	// EColour::Background_Grey
	};
	printf("%s", colourEscapeCodes[colour]);
#endif // _WINDOWS
}

Console& Console::GetInstance() {
	static Console singletonInstance;
	return singletonInstance;
}