#include "Logarithm.h"
#include "Change.h"

int CLogarithm::FLogarithm()
{
	CLogarithm func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CLogarithm::FCalculate(double x) 
{
	return 0.0;
}
void CLogarithm::FSLDVisualFunc(bool bOn)
{
}
void CLogarithm::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CLogarithm::FFindCor()
{
}
void CLogarithm::FFindExtremum()
{
}
void CLogarithm::Init()
{
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
	koaph = Vvod<double>("Введите коэфицент для логарифма", [](double a) {return true; });
	koaphLog = Vvod<double>("Введите коэфицент для аргуметна", [](double a) {return true; });
	constant = Vvod<double>("Введите константу", [](double a) {return true; });

	__super::Init();

	bYouAагрее = Change(
		{
			{[]() {return 1; } ,"Да"},
			{[]() {return 2; } ,"Нет"},
		},
		NONEEXIT | ONETIME,
		std::string("Вы согласны с представленными данными?"));
} while (bYouAагрее != 2);
}