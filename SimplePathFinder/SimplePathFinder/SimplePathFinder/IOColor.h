#ifndef _IO_COLOR_H_
#define _IO_COLOR_H_

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>

namespace IOCOLOR
{
	using namespace std;
	enum Color {
		BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_TAN,
		GREY, DARK_GREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE,
		BG_BLACK, BG_DARK_BLUE, BG_DARK_GREEN, BG_DARK_CYAN, BG_DARK_RED, BG_DARK_MAGENTA, BG_DARK_TAN,
		BG_GREY, BG_DARK_GREY, BG_BLUE, BG_GREEN, BG_CYAN, BG_RED, BG_MAGENTA, BG_YELLOW, BG_WHITE
	};

	ostream& operator<<(ostream& out, Color c)
	{
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

		HANDLE consoleHandle;
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);
		WORD consoleColorInfo = bufferInfo.wAttributes;

		WORD backgroundColor = consoleColorInfo >> 4;
		backgroundColor = backgroundColor << 4;

		WORD textColor = consoleColorInfo - backgroundColor;

		if (c > WHITE)
		{
			backgroundColor = c;
		}
		else
		{
			textColor = c;
		}

		SetConsoleTextAttribute(consoleHandle, textColor + (backgroundColor * 16));

		return out;
	}
}

#undef WIN32_LEAN_AND_MEAN

#endif