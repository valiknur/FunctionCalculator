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
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ���������", [](double a) {return a>0; });
		osnow = Vvod<double>("������� ������", [](double a) {return a>0; });
		stepKoaph = Vvod<double>("������� ��������� �������", [](double a) {return a!=0; });
		constant = Vvod<double>("������� ���������", [](double a) {return true; });
		__super::Init();

		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 0; } ,"���"},
			},
			NONEEXIT | ONETIME,
			std::string("�� �������� � ��������������� �������?"));
	} while (bYouA����� != 1);
}