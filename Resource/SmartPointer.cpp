/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : Resource                                  *
 *                                                                            *
 *                      File Name : SmartPointer.cpp                          *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : January 1, 2023                           *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   First practice of smart pointer in C++.                                  *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community                                             *
 ******************************************************************************/

#include <cnsl.h>
#include <memory>

class Object
{
public:
	Object(int _id)
	{
		id = _id;
		cnsl::InsertText(" Object(%d)\n", id);
	}
	~Object()
	{
		cnsl::InsertText("~Object(%d)\n", id);
	}

	void show()
	{
		cnsl::InsertText("This is Object(%d)\n", id);
	}

private:
	int id;
};

struct ObjectDeleter
{
	void operator()(Object* obj)
	{
		cnsl::InsertText("Custom deleter: ");
		delete obj;
	};
};

int main()
{
	cnsl::InitConsole();
	cnsl::SetTitle("Smart Pointer");
	cnsl::Print();

	{
		cnsl::InsertHeaderLine("std::shared_ptr<>", '+');
		std::shared_ptr<Object> share_1(new Object(1));
		std::shared_ptr<Object> share_2(new Object(2));
		std::shared_ptr<Object> share_3(share_2);

		share_1->show();
		(*share_2).show();
		share_3->show();
	}

	{
		cnsl::InsertNewLine();
		cnsl::InsertHeaderLine("std::unique_ptr<>", '+');
		std::unique_ptr<Object> unique_1(new Object(3));
		std::unique_ptr<Object, ObjectDeleter> unique_2(new Object(4));

		unique_1->show();
		unique_2->show();
		
		// we can transfer owner by release
		std::unique_ptr<Object, ObjectDeleter> unique_3(unique_2.release());

		/*
		** copy constructor and copy assignment are deleted
		std::unique_ptr<Object> unique_3(unique_2);
		std::unique_ptr<Object> unique_3 = unique_2;
		*/

		std::unique_ptr<Object> unique_4;

		/*
		** normal unique could not swap with unique with deleter
		unique_4.swap(unique_2);
		*/
		unique_4.swap(unique_1);
		unique_4->show();
		if (!unique_1)
			cnsl::InsertText("unique_1 is nullptr.\n");
	}

	return 0;
}

