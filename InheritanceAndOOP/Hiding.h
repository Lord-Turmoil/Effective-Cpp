/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : InheritanceAndOOP                         *
 *                                                                            *
 *                      File Name : Hiding.h                                  *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 4, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Avoid Hiding inherited names.                                            *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#ifndef _HIDING_H_
#define _HIDING_H_

#include <cnsl.h>

class Base
{
public:
	virtual void mf1() = 0;
	virtual void mf1(int) {
		cnsl::InsertText("Base::mf1(int)\n");
	}

	virtual void mf2() {
		cnsl::InsertText("Base::mf2()\n");
	}

	void mf3() {
		cnsl::InsertText("Base::mf3()\n");
	}
	virtual void mf3(double) {
		cnsl::InsertText("Base::mf3(double)\n");
	}

private:
	int x;
};

class DerivedA : public Base
{
public:
	virtual void mf1() {
		cnsl::InsertText("DerivedA::mf1()\n");
	}

	void mf3() {
		cnsl::InsertText("DerivedA::mf3()\n");
	}

	void mf4() {
		cnsl::InsertText("DerivedA::mf4()\n");
	}
};

class DerivedB : public Base
{
public:
	using Base::mf1;
	using Base::mf3;

	virtual void mf1() {
		cnsl::InsertText("DerivedB::mf1()\n");
	}

	void mf3() {
		cnsl::InsertText("DerivedB::mf3()\n");
	}

	void mf4() {
		cnsl::InsertText("DerivedB::mf4()\n");
	}
};

void Hiding()
{
	cnsl::InsertHeaderLine("Drived A");
	DerivedA a;

	// Function with the same name hides inheritance!
	a.mf1();
	// a.mf1(1); // Error!
	cnsl::InsertText("Cannot call DerivedA::mf1(int)!\n");
	a.mf2();
	a.mf3();
	// a.mf3(1.0); // Error!
	cnsl::InsertText("Cannot call DerivedA::mf3(double)!\n");


	cnsl::InsertHeaderLine("Drived B");
	DerivedB b;

	// using makes hidden inheritance visible.
	b.mf1();
	b.mf1(1);
	b.mf2();
	b.mf3();
	b.mf3(1.0);
}


#endif
