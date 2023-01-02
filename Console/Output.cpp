/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : Console                                   *
 *                                                                            *
 *                      File Name : Output.cpp                                *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 1, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Output control.                                                          *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#include "Output.h"
#include "Console.h"
#include "Common.h"

#include <cstring>
#include <cstdio>
#include <cstdarg>

_CNSL_BEGIN

/*
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
** Output Control
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
static bool IsNewLine(char ch)
{
	return (ch == LINE_FEED) || (ch == CHARRIGE);
}

void InsertLineFeed()
{
	COORD pos = GetCursorPosition();
	pos.Y++;

	if (!SetCursorPosition(pos, nullptr))
	{
		// out of bound
		Reprint();
	}
}

void InesrtLineFeed(int n)
{
	for (int i = 0; i < n; i++)
		InsertLineFeed();
}

void InsertCarrige()
{
	putchar(CHARRIGE);
}

void InsertNewLine()
{
	putchar(CHARRIGE);
	putchar(LINE_FEED);
}

void InsertNewLine(int n)
{
	for (int i = 0; i < n; i++)
		InsertNewLine();
}

void InsertBackspace()
{
	putchar(BACKSPACE);
	putchar(SPACE);
	putchar(BACKSPACE);
}

void InsertChar(const char ch)
{
	if (ch == CHARRIGE)
		InsertCarrige();
	else if (ch == LINE_FEED)
		InsertLineFeed();
	else
		putchar(ch);
}

void InsertText(const char* format, ...)
{
	static char buffer[256];

	if (!format)
		return;

	va_list args;

	va_start(args, format);
	vsprintf_s(buffer, format, args);
	va_end(args);

	for (const char* p = buffer; *p; p++)
	{
		if (IsNewLine(*p))
			InsertNewLine();
		else
			InsertChar(*p);
	}
}

void InsertSplitLine(char split)
{
	if (IsNewLine(split))
		return;

	SHORT width = GetConsoleWidth();

	Clear(0);
	InsertCarrige();

	for (SHORT i = 0; i < width; i++)
		InsertChar(split);

	InsertNewLine();
}

void InsertHeaderLine(const char* header, char split)
{
	if (!header)
		return;
	if (IsNewLine(split))
		return;

	SHORT width = GetConsoleWidth();
	
	Clear(0);
	InsertCarrige();

	SHORT length = (SHORT)strlen(header);
	SHORT begin = (width - length) / (SHORT)2;
	SHORT i;

	for (i = 0; i < begin - 1; i++)
		InsertChar(split);
	
	InsertChar(SPACE);
	i++;
	InsertText(header);
	i += length;
	InsertChar(SPACE);
	i++;

	for (i; i < width; i++)
		InsertChar(split);
	
	InsertNewLine();
}

_CNSL_END
