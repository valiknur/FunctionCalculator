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
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ��������� ��� ��������", [](double a) {return true; });
		cosKoaph = Vvod<double>("������� ��������� ��� ���������", [](double a) {return true; });
		cosConstant = Vvod<double>("������� ��������� ��� ���������",[](double a) {return true; });
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