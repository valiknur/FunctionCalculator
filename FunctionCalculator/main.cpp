#include"Change.h"
#include"Resourse.h"
#include"MyFunction.h"
#include"MatrixCalc.h"
#include"simplefractions.h"
#include"Mnogochleni.h"
#include"Theor_prob.h"

int main(int argc, char* args[])
{
	setlocale(0, "");
	int menu_choise;
	do
	{
		menu_choise = Change(
		{
		{StartFunction,"Калькулятор функций"},
		{simplefractions,"Калькулятор обычных дробей"},
		{MatrixCalc,"Матричный калькулятор"},
		{Mnogochleni,"Многочлены"},
		{Theor_prob,"Теория вероятности"}
		}
	);
	} while (menu_choise != 0);
	return 0;
}