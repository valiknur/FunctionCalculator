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


	std::cout << "конец";
	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDegree::FCalculate(double x)
{ 
	return koaph * pow(x, step) + constant;
}
void CDegree::FSLDVisualFunc(bool bOn)
{
}
void CDegree::FOpredIntegral()
{
	koaph / (step + 1) * pow(x, step + 1) + constant * x;
}
void CDegree::FFindCor()
{
}
void CDegree::FFindExtremum()
{
}
void CDegree::Init()
{
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент", [](double a) {return true; });
		step = Vvod<double>("Введите степень", [](double a) {return true; });
		constant = Vvod<double>("Введите константу", [](double a) {return true; });

		__super::Init();
		std::cout << koaph << "*x^" << step << " + " << constant;

		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 2 ; } ,"Нет"},
			},
			std::string("Вы согласны с представленными данными?"),
			NONEEXIT | ONETIME);
	} while (bYouAагрее != 2);
}