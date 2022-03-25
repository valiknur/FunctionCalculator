#include "Demonstration.h"
#include "Change.h"
int CDemonstration::FDemonstration()
{
	CDemonstration func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDemonstration::FCalculate(double x) { return 0.0f; }
void CDemonstration::FSLDVisualFunc(bool bOn)
{
}
void CDemonstration::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CDemonstration::FFindCor()
{
}
void CDemonstration::FFindExtremum()
{
}
void CDemonstration::Init()
{
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент", [](double a) {return a>0; });
		osnow = Vvod<double>("Введите основу", [](double a) {return a>0; });
		stepKoaph = Vvod<double>("Введите коэфицент степени", [](double a) {return a!=0; });
		constant = Vvod<double>("Введите константу", [](double a) {return true; });
		__super::Init();

		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 0; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string("Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
}