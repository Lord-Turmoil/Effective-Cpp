/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : Implementations                           *
 *                                                                            *
 *                      File Name : StaticCast.h                              *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 2, 2022                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Static cast create a copy?                                               *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#ifndef _STATIC_CAST_
#define _STATIC_CAST_

#include <cnsl.h>

class Base
{
public:
	Base() : count(0) {}
	virtual void Show()
	{
		cnsl::InsertText("Base class [%p] No %d\n", this, GetCount());
	}

/*
** protected does not provide encapsulation. As it may cause as much
** trouble as public, as for its child classes.
*/
protected:
	int GetCount() const { return count++; }

private:
	// mutable can avoid bitwise const
	mutable int count;
};

class DeriveA : public Base
{
public:
	virtual void Show()
	{
		/*
		** This is totally wrong! It depends on the memory layout
		** of the object, and it varies.
		*/
		static_cast<Base>(*this).Show();
		cnsl::InsertText("Derive A   [%p] No %d\n", this, GetCount());
	}
};

class DeriveB : public Base
{
public:
	virtual void Show()
	{
		Base::Show();
		cnsl::InsertText("Derive B   [%p] No %d\n", this, GetCount());
	}
};

void StaticCast()
{
	cnsl::InsertHeaderLine("Derive A", '-');
	cnsl::InsertText("sizeof(DriveA) = %zd\n", sizeof(DeriveA));
	DeriveA a;
	a.Show();
	a.Show();
	a.Show();

	cnsl::InsertHeaderLine("Derive B", '-');
	cnsl::InsertText("sizeof(DriveB) = %zd\n", sizeof(DeriveB));
	DeriveB b;
	b.Show();
	b.Show();
	b.Show();
}

#endif
