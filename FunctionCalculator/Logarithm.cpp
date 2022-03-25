#include "Logarithm.h"
#include "Change.h"

#define LN log()
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
	__super::FSLDVisualFunc(bOn);
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
		koaph = Vvod<double>("������� ��������� ��� ��������� (�� ����)", [](double a) {return a!=0; });
		koaphLog = Vvod<double>("������� ��������� ��� ���������", [](double a) {return true; });
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
};