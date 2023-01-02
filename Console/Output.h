/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : Console                                   *
 *                                                                            *
 *                      File Name : Output.h                                  *
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

#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include "Macros.h"

#include <string>

_CNSL_BEGIN

/*
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
** Output Control
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
void InsertLineFeed();		// Row++, col does not change.
void InsertLineFeed(int n);	// Insert n line feeds.
void InsertCarrige();		// Row does not change, col back to zero.
void InsertNewLine();		// Row++, col back to zero.
void InsertNewLine(int n);	// Insert n new lines.

void InsertBackspace();	// Clear the last character and went back by one.

void InsertChar(const char ch);
void InsertText(const char* format, ...);
void InsertSplitLine(char split);
void InsertHeaderLine(const char* header, char split);

template<typename _Ty>
void InsertNumber(_Ty val)
{
	static_assert(std::is_arithmetic<_Ty>::value, "Must be arithmetic!");
	
	InsertText(std::to_string(val).c_str());
}

_CNSL_END

#endif