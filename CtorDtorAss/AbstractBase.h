/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : CtorDtorAss                               *
 *                                                                            *
 *                      File Name : AbstractBase.h                            *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 2, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Create a abstract class without extra functions.                         *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#ifndef _ABSTRACT_BASE_
#define _ABSTRACT_BASE_

#include <cnsl.h>

class Abstract
{
public:
	/*
	** Just a virtual destructor can make a fine abstract
	** class, but not enough. It needs a definition, or it
	** will cause linking error.
	*/
	virtual ~Abstract() = 0;
};

Abstract::~Abstract() {}

class Concrete
{
public:
	Concrete()
	{
		cnsl::InsertText("Concrete()\n");
	}
	~Concrete()
	{
		cnsl::InsertText("~Concrete()\n");
	}
};

void AbstractBase()
{
	Concrete concrete;
}

#endif