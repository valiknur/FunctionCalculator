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
		std::string("�� �������� � ��������������� �������?"),
		NONEEXIT | ONETIME);
} while (bYouA����� != 2);
}