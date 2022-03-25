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


	std::cout << "конец";
	system("pause");
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CSinusFunc::FCalculate(double x)
{
	return -(koaph * sin(sinKoaph * x + sinConstant) + constant);
}
void CSinusFunc::FSLDVisualFunc(bool bOn)
{
	__super::FSLDVisualFunc(bOn);

}
void CSinusFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout << - koaph * sinKoaph * cos(sinKoaph * rightIntegr + sinConstant) - constant * rightIntegr
				 + koaph * sinKoaph * cos(sinKoaph * leftIntegr + sinConstant) + constant * leftIntegr << '\n';
}
void CSinusFunc::FFindCor()
{
	if (abs(constant) < abs(koaph))
	{
		std::cout << "\nКорней нет\n";
		return;
	}
	if (abs(constant) == abs(koaph))
	{
		std::cout << "\nКорни: " << asin(-constant / koaph) / sinKoaph - sinConstant << "+2*pi*k\n";
		return;
	}
	std::cout << "\nКорни: " << (asin(-constant / koaph) - sinConstant) / sinKoaph << "+" << 2 / sinKoaph << "*pi*k и "
					 << ((M_PI - asin(-constant / koaph)) - sinConstant) / sinKoaph << "+" << 2 / sinKoaph << "*pi*k\n";
}
void CSinusFunc::FFindExtremum()
{
	std::cout << "\nэкстремумы:";
	std::cout << "\nмаксимум: " << sinKoaph * M_PI / 2 - sinConstant << "+" << 2 / sinKoaph << "*pi*k";
	std::cout << "\nминимум: " << (-sinKoaph) * M_PI / 2 - sinConstant << "+" << 2 / sinKoaph << "*pi*k\n";
}
void CSinusFunc::Init()
{
	std::string bigString;
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент для синуса (не нуль)", [](double a) {return a != 0; });
		sinKoaph = Vvod<double>("Введите коэфицент для аргумента (не нуль)", [](double a) {return a != 0; });
		sinConstant = Vvod<double>("Введите константу для аргумента ", [](double a) {return true; });
		constant = Vvod<double>("Введите константу для функции", [](double a) {return true; });

		__super::Init();
		bigString = std::to_string(koaph) + "cin(" + std::to_string(sinKoaph) + "x+" + std::to_string(sinConstant) + ")" + std::to_string(constant) + '\n';
		bigString += "\nПромежуток определённого интегралла = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 0; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
	if (sinConstant > 0) sinConstant -= int(abs(sinConstant) / M_PI) * M_PI;
	else sinConstant += int(abs(sinConstant) / M_PI) * M_PI + M_PI;
	if (koaph < 0 || sinKoaph < 0)
	{
		if (koaph < 0 != sinKoaph < 0)sinConstant = M_PI - sinConstant;
			koaph = abs(koaph);
			sinKoaph = abs(sinKoaph);
	}
}