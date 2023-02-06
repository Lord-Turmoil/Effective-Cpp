/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : TemplateAndGeneric                        *
 *                                                                            *
 *                      File Name : Main.cpp                                  *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : February 4, 2023                          *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Template and Generic Programming.                                        *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#include <cnsl.h>

#include "TMP.h"

int main()
{
	cnsl::InitConsole(110);
	cnsl::SetTitle("Inheritance and Object-Oriented Design");
	cnsl::OverflowReprint(false);
	cnsl::Print();

	cnsl::InsertHeaderLine("TMP", '+');
	TMP();

	return 0;
}