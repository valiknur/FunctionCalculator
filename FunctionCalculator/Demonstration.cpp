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


	std::cout << "�����";
	system("pause");
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDemonstration::FCalculate(double x)
{ 
	return koaph * pow(osnow, stepKoaph * x) + constant;
}
void CDemonstration::FSLDVisualFunc(bool bOn)
{
	__super::FSLDVisualFunc(bOn);
}
void CDemonstration::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CDemonstration::FFindCor()
{
	if (koaph != abs(koaph) != constant != abs(constant))
	{
		std::cout << "\n������ = " << log(constant / koaph) / log(osnow) - stepKoaph;
	}
}
void CDemonstration::FFindExtremum()
{
	std::cout << "\n����������� ���\n";
}
void CDemonstration::Init()
{
	std::string bigString;
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ��������� (������ 0)", [](double a) {return a>0; });
		osnow = Vvod<double>("������� ������ (������ 0)", [](double a) {return a>0; });
		stepKoaph = Vvod<double>("������� ��������� ������� (�� ����)", [](double a) {return a!=0; });
		constant = Vvod<double>("������� ���������", [](double a) {return true; });
		__super::Init();
		bigString = std::to_string(koaph) + std::to_string(osnow) + "^" + std::to_string(stepKoaph) + std::to_string(stepKoaph) + ")" + std::to_string(constant) + '\n';
		bigString += "\n���������� ������������ ���������� = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 0; } ,"���"},
			},
			NONEEXIT | ONETIME,
			std::string("�� �������� � ��������������� �������?"));
	} while (bYouA����� != 1);
}