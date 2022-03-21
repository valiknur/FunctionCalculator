#include "Degree.h"
#include "Change.h"
int CDegree::FDegree()
{
	CDegree func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
float CDegree::FCalculate() { return 0.0f; }
void CDegree::FSLDVisualFunc(bool bOn)
{
}
void CDegree::FOpredIntegral()
{
}
void CDegree::FFindCor()
{
}
void CDegree::FFindExtremum()
{
}
void CDegree::Init()
{
	bool bYouA����� = false;
	__super::Init();
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ����� �������", [](double a) {return true; });
		step = Vvod<double>("������� ����� �������", [](double a) {return true; });
		constant = Vvod<double>("������� ����� �������", [](double a) {return true; });

		__super::Init();

		std::cout << koaph << "*x^" << step << " + " << constant;

		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 2; } ,"���"},
			},
			std::string("�� �������� � ��������������� �������?"),
			NONECLEARCONSOLE | NONEEXIT);
	} while (bYouA����� != 2);
}