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
		{StartFunction,"����������� �������"},
		{simplefractions,"����������� ������� ������"},
		{MatrixCalc,"��������� �����������"},
		{Mnogochleni,"����������"},
		{Theor_prob,"������ �����������"}
		}
	);
	} while (menu_choise != 0);
	return 0;
}