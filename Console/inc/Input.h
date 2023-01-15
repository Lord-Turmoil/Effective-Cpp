/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : Console                                   *
 *                                                                            *
 *                      File Name : Input.h                                   *
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

#ifndef _INPUT_H_
#define _INPUT_H_

#include "Macros.h"
#include "Console.h"
#include "Output.h"

#include <conio.h>
#include <sstream>

_CNSL_BEGIN

const int INPUT_BUFFER_SIZE = 128;
extern char buffer[INPUT_BUFFER_SIZE];

/*
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
** Input Control
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
bool GetString(char* buffer);


template<typename _Ty>
bool DefaultVerifier(_Ty value) { return true; }


template<typename _Ty>
bool GetNumber(_Ty* value, bool (*verifier)(_Ty), const char* prompt)
{
	COORD origin = GetCursorPosition();

	GetString(buffer);
	std::stringstream stream(buffer);

	_Ty val;
	bool err = false;
	if (stream >> val)
	{
		if (verifier && !verifier(val))
			err = true;
	}
	else
		err = true;

	if (err)
	{
		Clear(origin.X);
		SetCursorPosition(origin);
		if (prompt)
		{
			InsertText(prompt);
			Sleep(1000);
			Clear(origin.X);
			SetCursorPosition(origin);
		}
	}
	else
		*value = val;

	return !err;
}

template<typename _Ty>
bool GetNumber(_Ty* value)
{
	return GetNumber(value, DefaultVerifier<_Ty>, nullptr);
}

template<typename _Ty>
bool GetNumber(_Ty* value, bool (*verifier)(_Ty))
{
	return GetNumber(value, verifier, nullptr);
}

template<typename _Ty>
bool GetNumber(_Ty* value, const char* prompt)	// error prompt
{
	return GetNumber(value, DefaultVerifier, prompt);
}

void FlushInput();

// Wait for key to continue, 0 means any.
void WaitForKey(const char* prompt, char key = (char)0);

_CNSL_END

#endif