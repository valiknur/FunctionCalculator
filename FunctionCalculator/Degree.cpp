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


	std::cout << "�����";
	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDegree::FCalculate(double x)
{ 
	return koaph * pow(x, step) + constant;
}
void CDegree::FSLDVisualFunc(bool bOn)
{

}
void CDegree::FOpredIntegral()
{
	std::cout <<	koaph / (step + 1) * pow(rightIntegr, step + 1) + constant * rightIntegr -
					koaph / (step + 1) * pow(leftIntegr, step + 1) + constant * leftIntegr;
}
void CDegree::FFindCor()
{
}
void CDegree::FFindExtremum()
{
}
void CDegree::Init()
{
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ���������", [](double a) {return true; });
		step = Vvod<double>("������� �������", [](double a) {return true; });
		constant = Vvod<double>("������� ���������", [](double a) {return true; });

		__super::Init();
		std::cout << koaph << "*x^" << step << " + " << constant;

		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 2 ; } ,"���"},
			},
			NONEEXIT | ONETIME | FIRSTPAUSE,
			std::string("�� �������� � ��������������� �������?"));
	} while (bYouA����� != 2);
}