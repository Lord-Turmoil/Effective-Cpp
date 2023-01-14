/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : Console                                   *
 *                                                                            *
 *                      File Name : Input.cpp                                 *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 1, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   For input control.                                                       *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#include "Input.h"
#include "Common.h"

#include <ctime>

_CNSL_BEGIN

static const char INPUT_TERMINATOR[] = "\n\r";
char buffer[INPUT_BUFFER_SIZE];

static bool IsTerminator(char ch)
{
	for (const char* p = INPUT_TERMINATOR; *p; p++)
	{
		if (*p == ch)
			return true;
	}

	return false;
}

bool GetString(char* buffer)
{
	int length = 0;
	char ch;

	for (; ;)
	{
		ch = _getch();
		if (IsTerminator(ch))
		{
			if (length > 0)
				break;
		}
		else if (ch == BACKSPACE)
		{
			if (length > 0)
			{
				InsertBackspace();
				length--;
			}
		}
		else
		{
			buffer[length++] = ch;
			InsertChar(ch);
		}
	}

	buffer[length] = '\0';

	return true;
}

void FlushInput()
{
	static HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

	FlushConsoleInputBuffer(hInput);
}

void WaitForKey(const char* prompt, char key)
{
	InsertText(prompt);

	FlushInput();

	for (int i = 0; ; i++)
	{
		char ch = _getch();
		if (ch == key)
			break;
		else if (key == (char)0)
			break;
	}
}

_CNSL_END