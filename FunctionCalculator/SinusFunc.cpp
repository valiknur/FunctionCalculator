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
		std::cout << "\n������ ���\n";
		return;
	}
	if (abs(sinKoaph) < abs(koaph))
	{
		std::cout << "\n�����: " << asin(constant / koaph) / sinKoaph << "+2*pi*k\n";
		return;
	}
	std::cout << "\n�����: " << asin(constant / koaph) / sinKoaph << "+2*pi*k � " << (M_PI - asin(constant / koaph)) / sinKoaph << "+2*pi*k\n";
}
void CSinusFunc::FFindExtremum()
{
	std::cout << "\n�����: " << asin(constant / koaph) / sinKoaph << "+2*pi*k � " << (M_PI - asin(constant / koaph)) / sinKoaph << "+2*pi*k\n";
}
void CSinusFunc::Init()
{
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
	koaph = Vvod<double>("������� ��������� ��� ������", [](double a) {return true; });
	sinKoaph = Vvod<double>("������� ��������� ��� ���������", [](double a) {return true; });
	sinConstant = Vvod<double>("������� ��������� ��� ���������", [](double a) {return true; });
	constant = Vvod<double>("������� ��������� ��� �������", [](double a) {return true; });

	__super::Init();

	bYouA����� = Change(
		{
			{[]() {return 1; } ,"��"},
			{[]() {return 2; } ,"���"},
		},
		NONEEXIT | ONETIME,
		std::string("�� �������� � ��������������� �������?"));
} while (bYouA����� != 2);
}