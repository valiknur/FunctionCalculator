#include "Change.h"

void Change(int size, std::vector<Foo> arr)
{
	int selected = 0;
	do
	{
		std::cout << "\033[2J\033[1;1H";
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i].string << (i == selected ? " <-" : "") << '\n';
		}
		switch (_getch())
		{
		case 80:
		{
			selected = min(size, selected + 1);
			break;
		}
		case 72:
		{
			selected = max(0, selected - 1);
			break;
		}
		case 13:
		{
			std::cout << "\033[2J\033[1;1H";
			arr[selected].func();
			break;
		}
		default:
			break;
		}
	} while (true);
}

Foo::Foo(void(*func)(), const char* string)
{
	this->func = func;
	this->string = string;
}
