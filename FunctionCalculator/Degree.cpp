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
	system("pause");
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
	std::string bigString = "";
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ���������", [](double a) {return true; });
		step = Vvod<double>("������� �������", [](double a) {return true; });
		constant = Vvod<double>("������� ���������", [](double a) {return true; });

		__super::Init();
		std::cout << koaph << "*x^" << step << " + " << constant;
		bigString = std::to_string(koaph) + "*x^" + std::to_string(step) + " + " + std::to_string(constant);
		bigString += "\n���������� ������������ ���������� = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 0; } ,"���"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "�� �������� � ��������������� �������?"));
	} while (bYouA����� != 1);
	std::cout << bigString;
}