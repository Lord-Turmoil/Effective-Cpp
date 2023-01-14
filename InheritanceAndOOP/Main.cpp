/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : InheritanceAndOOP                         *
 *                                                                            *
 *                      File Name : Main.cpp                                  *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 4, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Inheritance and Object-Oriented Design.                                  *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#include "Hiding.h"
#include "InheritanceAndImplementation.h"

int main()
{
	cnsl::InitConsole(110);
	cnsl::SetTitle("Inheritance and Object-Oriented Design");
	cnsl::Print();

	cnsl::InsertHeaderLine("Hiding", '+');
	Hiding();
	cnsl::InsertHeaderLine("Inheritance And Implementation", '+');
	InhAndImp();

	return 0;
}