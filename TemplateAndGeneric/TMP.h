/******************************************************************************
 ***                        T O N Y ' S  S T U D I O                        ***
 ******************************************************************************
 *                   Project Name : TemplateAndGeneric                        *
 *                                                                            *
 *                      File Name : TMP.h                                     *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : February 4, 2023                          *
 *                                                                            *
 *                    Last Update :                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Template MetaProgramming.                                                *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community Preview                                     *
 ******************************************************************************/

#include <cnsl.h>

struct FactorialBase
{
	using value_type = unsigned long long;
};

template<unsigned n>
struct Factorial : public FactorialBase
{
	enum : value_type { value = (value_type)n * Factorial<n - 1>::value };
};

// specialization?
template<>
struct Factorial<0> : public FactorialBase
{
	enum : value_type { value = 1 };
};

void TMP()
{
	cnsl::InsertText("Factorial<5> = %llu\n", Factorial<5>::value);
	cnsl::InsertText("Factorial<10> = %llu\n", Factorial<10>::value);
	cnsl::InsertText("Factorial<15> = %llu\n", Factorial<15>::value);
	cnsl::InsertText("Factorial<20> = %llu\n", Factorial<20>::value);
}