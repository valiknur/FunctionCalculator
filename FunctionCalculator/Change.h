#pragma once
#include <iostream>
#include <vector>
struct Foo
{
	void (*func)();
	const char* string;
	Foo(void (*func)(), const char* string);
};
	Foo *arr;
void Change(int size, std::vector<Foo> arr);

float Vvod(const char* string, bool(*func)(float));