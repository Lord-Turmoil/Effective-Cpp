/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : InheritanceAndOOP                         *
 *                                                                            *
 *                      File Name : InheritanceAndImplementation.h            *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 14, 2023                          *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Differentiate between inheritance of interface and inheritance of        *
 *   implementation.                                                          *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#ifndef _INHERITANCE_AND_IMPLEMENTATION_
#define _INHERITANCE_AND_IMPLEMENTATION_

#include <cnsl.h>

/********************************************************************
** In this example, we focus on inheritance of interface and
** implementation.
** - For public inheritance, derived classes always inheritant
** interface.
** - For pure function in base class, it is only an interface, while
** impure function is a definition at the same time.
** - Specially, for pure functions that has a definition (not impure),
** it provides a default function subtly.
** - More straightly, pure function denotes that derived classes MUST
** give it a specific definition, whether duplicates or not, in case
** unwanted default function used.
*/

class Airplane
{
public:
	virtual void fly() = 0;
};

// Actually, we can give a subtle definition to a pure function.
void Airplane::fly()
{
	cnsl::InsertText("Airplane::fly()\n");
}

// Default fly
class ModelA : public Airplane
{
public:
	virtual void fly()
	{
		cnsl::InsertText("ModelA::");
		Airplane::fly();
	}
};

// Default fly
class ModelB : public Airplane
{
public:
	virtual void fly()
	{
		cnsl::InsertText("ModelB::");
		Airplane::fly();
	}
};

// Special fly
class ModelC : public Airplane
{
public:
	virtual void fly()
	{
		cnsl::InsertText("ModelC::fly()\n");
	}
};


void InhAndImp()
{
	Airplane* pAirplane;

	pAirplane = new ModelA();
	pAirplane->fly();
	delete pAirplane;

	pAirplane = new ModelB();
	pAirplane->fly();
	delete pAirplane;

	pAirplane = new ModelC();
	pAirplane->fly();
	delete pAirplane;
}

#endif
