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
	__super::FSLDVisualFunc(bOn);

}

void CCosinFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout << koaph * cosKoaph * sin(cosKoaph * rightIntegr + cosConstant) + constant * rightIntegr
		- koaph * cosKoaph * sin(cosKoaph * leftIntegr + cosConstant) + constant * leftIntegr << '\n';
}
void CCosinFunc::FFindCor()
{
	if (abs(cosKoaph) < abs(koaph))
	{
		std::cout << "\n������ ���\n";
		return;
	}
	if (abs(cosKoaph) < abs(koaph))
	{
		std::cout << "\n�����: " << acos(-constant / koaph) / cosKoaph - cosConstant << "+2*pi*k\n";
		return;
	}
	std::cout << "\n�����: " << (acos(-constant / koaph) - cosConstant) / cosKoaph << "+" << 2 / cosKoaph << "*pi*k � "
		<< ((M_PI - acos(-constant / koaph)) - cosConstant) / cosKoaph << "+" << 2 / cosKoaph << "*pi*k\n";
}
void CCosinFunc::FFindExtremum()
{
	std::cout << "\n����������:";
	std::cout << "\n��������: " << cosConstant << "+" << 2 / cosKoaph << "*pi*k";
	std::cout << "\n�������: " << cosKoaph * M_PI - cosConstant << "+" << 2 / cosKoaph << "*pi*k\n";
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
	if (cosConstant > 0) cosConstant -= int(abs(cosConstant) / M_PI) * M_PI;
	else cosConstant += int(abs(cosConstant) / M_PI) * M_PI + M_PI;
	if (koaph < 0 || cosKoaph < 0)
	{
		if (koaph < 0 != cosKoaph < 0)cosConstant = M_PI - cosConstant;
		koaph = abs(koaph);
		cosKoaph = abs(cosKoaph);
	}
}