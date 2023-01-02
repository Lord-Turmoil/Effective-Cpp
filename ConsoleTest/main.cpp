/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : ConsoleTest                               *
 *                                                                            *
 *                      File Name : main.cpp                                  *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 1, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   To test console lib.                                                     *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#include <cnsl.h>

bool check(int a)
{
	return (a < 10);
}

int main()
{
	cnsl::InitConsole();

	cnsl::Print();

	int value = 0;

	cnsl::InsertText("Input an integer: ");
	while (value != -1)
	{
		while (!cnsl::GetNumber(&value, check, "A number less than 10!"))
			continue;
		cnsl::InsertNewLine();
		cnsl::InsertText("Your integer is integer: ");
		cnsl::InsertNumber(value);
		cnsl::InsertNewLine();
		cnsl::InsertHeaderLine("Split Line", '-');
		cnsl::InsertText("Input an integer: ");
	}

	return 0;
}
