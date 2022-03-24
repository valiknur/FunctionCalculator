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
	return koaph * sin(sinKoaph * x + sinConstant) + constant;
}
void CSinusFunc::FSLDVisualFunc(bool bOn)
{
}
void CSinusFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout <<  koaph * sinKoaph * cos(sinKoaph * rightIntegr + sinConstant) + constant * rightIntegr
				- koaph * sinKoaph * cos(sinKoaph * leftIntegr + sinConstant) + constant * leftIntegr << '\n';
}
void CSinusFunc::FFindCor()
{
	if (abs(sinKoaph) < abs(koaph))
	{
		std::cout << "\nКорней нет\n";
		return;
	}
	if (abs(sinKoaph) < abs(koaph))
	{
		std::cout << "\nКорни: " << asin(constant / koaph) / sinKoaph << "+2*pi*k\n";
		return;
	}
	std::cout << "\nКорни: " << asin(constant / koaph) / sinKoaph << "+2*pi*k и " << (M_PI - asin(constant / koaph)) / sinKoaph << "+2*pi*k\n";
}
void CSinusFunc::FFindExtremum()
{
	std::cout << "\nКорни: " << asin(constant / koaph) / sinKoaph << "+2*pi*k и " << (M_PI - asin(constant / koaph)) / sinKoaph << "+2*pi*k\n";
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
		NONEEXIT | ONETIME,
		std::string("Вы согласны с представленными данными?"));
} while (bYouAагрее != 2);
}