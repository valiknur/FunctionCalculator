#pragma once
#include "Resourse.h"

#ifndef CHANGE

#define CHANGE
#define NONEEXIT 2
#define CLEARCONSOLE std::cout << "\033[2J\033[1;1H"
#define ONETIME 4
struct Foo
{
	int (*func)();
	const char* string;
	Foo(int (*func)(), const char* string);
};

int Change(std::vector<Foo> arr, std::string message = "", int Keys = 0);

template<class T>
T Vvod(const char* string, bool(*func)(T))
{
	T per;
	std::cout << string << '\n';
	do
	{
		std::cin >> per;
		if (!func(per)) std::cout << "Неверный ввод\n";
	} while (!func(per));
	return per;
}

template<class T>
inline void Swap(T& a, T& b)
{
	T delta;
	delta = a;
	a = b;
	b = delta;
}

#endif // !CHANGE