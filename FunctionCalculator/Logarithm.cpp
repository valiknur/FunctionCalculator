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
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
	koaph = Vvod<double>("������� ��������� ��� ���������", [](double a) {return true; });
	koaphLog = Vvod<double>("������� ��������� ��� ���������", [](double a) {return true; });
	constant = Vvod<double>("������� ���������", [](double a) {return true; });

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