#pragma once
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <iostream>
#include <vector>
struct Foo
{
	void (*func)();
	const char* string;
	Foo(void (*func)(), const char* string);
};

void Change(int size, std::vector<Foo> arr);

template<class T>
T Vvod(const char* string, bool(*func)(T))
{
	T per = 0.0f;
	std::cout << string << '\n';
	
	{
		std::cin >> per;
		if (!func(per)) std::cout << "Неверный ввод\n";
	} while (func(per));
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