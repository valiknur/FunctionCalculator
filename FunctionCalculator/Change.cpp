#include "Change.h"

void Change(int size, std::vector<Foo> arr)
{
	static int selected = 0;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i].string <<(i==selected?" <-" : "") << '\n';
	}

}

float Vvod(const char* string, bool(*func)(float))
{
	float per = 0.0f;
	std::cout << string << '\n';
	do
	{
		std::cin >> per;
		if (!func(per)) std::cout << "Неверный ввод\n";
	} while (func(per));
	return per;
}

Foo::Foo(void(*func)(), const char* string)
{
	this->func = func;
	this->string = string;
}
