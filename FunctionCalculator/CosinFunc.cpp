#include "CosinFunc.h"
#include "Change.h"

int CCosinFunc::FCosinFunc()
{
	CCosinFunc func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CCosinFunc::FCalculate(double x)
{ 
	return koaph * cos(cosKoaph * x + cosConstant) + constant;
}
void CCosinFunc::FSLDVisualFunc(bool bOn)
{
}
void CCosinFunc::FOpredIntegral()
{
	-1 * koaph * cosKoaph * sin(cosKoaph * x + cosConstant) + constant * x;
	__super::FOpredIntegral();
}
void CCosinFunc::FFindCor()
{
}
void CCosinFunc::FFindExtremum()
{
}
void CCosinFunc::Init()
{
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент для косинуса", [](double a) {return true; });
		cosKoaph = Vvod<double>("Введите коэфицент для аргумента", [](double a) {return true; });
		cosConstant = Vvod<double>("Введите константу для аргумента",[](double a) {return true; });
		constant = Vvod<double>("Введите константу для функции", [](double a) {return true; });

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