#include "SinusFunc.h"
#include "Change.h"

int CSinusFunc::FSinusFunc()
{
	CSinusFunc func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CSinusFunc::FCalculate(double x)
{
	return 0.0f;koaph * sin(sinKoaph * x + sinConstant) + constant;
}
void CSinusFunc::FSLDVisualFunc(bool bOn)
{
}
void CSinusFunc::FOpredIntegral()
{
	koaph * sinKoaph * cos(sinKoaph * x + sinConstant) + constant * x;
	__super::FOpredIntegral();
}
void CSinusFunc::FFindCor()
{
}
void CSinusFunc::FFindExtremum()
{
}
void CSinusFunc::Init()
{
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
	koaph = Vvod<double>("Введите коэфицент для синуса", [](double a) {return true; });
	sinKoaph = Vvod<double>("Введите коэфицент для аргумента", [](double a) {return true; });
	sinConstant = Vvod<double>("Введите константу для аргумента", [](double a) {return true; });
	constant = Vvod<double>("Введите константу для функции", [](double a) {return true; });

	__super::Init();

	bYouAагрее = Change(
		{
			{[]() {return 1; } ,"Да"},
			{[]() {return 2; } ,"Нет"},
		},
		std::string("Вы согласны с представленными данными?"),
		NONEEXIT | ONETIME);
} while (bYouAагрее != 2);
}