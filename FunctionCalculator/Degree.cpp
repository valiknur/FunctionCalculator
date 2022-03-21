#include "Degree.h"
#include "Change.h"
int CDegree::FDegree()
{
	CDegree func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
float CDegree::FCalculate() { return 0.0f; }
void CDegree::FSLDVisualFunc(bool bOn)
{
}
void CDegree::FOpredIntegral()
{
}
void CDegree::FFindCor()
{
}
void CDegree::FFindExtremum()
{
}
void CDegree::Init()
{
	bool bYouAагрее = false;
	__super::Init();
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
		step = Vvod<double>("Введите левую границу", [](double a) {return true; });
		constant = Vvod<double>("Введите левую границу", [](double a) {return true; });

		__super::Init();

		std::cout << koaph << "*x^" << step << " + " << constant;

		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 2; } ,"Нет"},
			},
			std::string("Вы согласны с представленными данными?"),
			NONECLEARCONSOLE | NONEEXIT);
	} while (bYouAагрее != 2);
}