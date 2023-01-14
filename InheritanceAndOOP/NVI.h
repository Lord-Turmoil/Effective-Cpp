/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : InheritanceAndOOP                         *
 *                                                                            *
 *                      File Name : NVI.h                                     *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 14, 2023                          *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Use Non-Virtual Interface to implements Template Method pattern.         *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#ifndef _NVI_H_
#define _NVI_H_

#include <cnsl.h>

/********************************************************************
** This is not good. It seems that doHealthValue could not become
** polymorphism?
** In fact, Strategy pattern is a better solution.
*/
class GameCharacter
{
public:
	void healthValue() const
	{
		doHealthValue();
	}

protected:
	virtual void doHealthValue() const
	{
		cnsl::InsertText("GameCharacter::doHealthValue() = %p\n", this);
	}
};

class Hero : public GameCharacter
{
public:
	// Now, this non-virtual function remains.
	// int healthValue() const;

protected:
	virtual void doHealthVlaue() const
	{
		cnsl::InsertText("Hero::doHealthValue() = %p\n", this);
	}
};

class Enemy : public GameCharacter
{
public:
	// Now, this non-virtual functino remains.
	// int healthValue() const;

protected:
	virtual void doHealthVlaue() const
	{
		cnsl::InsertText("Enemy::doHealthValue() = %p\n", this);
	}
};

void NVI()
{
	GameCharacter* pCharacter;

	pCharacter = new Hero();
	pCharacter->healthValue();
	delete pCharacter;

	pCharacter = new Enemy();
	pCharacter->healthValue();
	delete pCharacter;
}

#endif