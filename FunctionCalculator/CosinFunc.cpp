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


	std::cout << "�����";
	system("pause");
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CCosinFunc::FCalculate(double x)
{ 
	return -(koaph * cos(cosKoaph * x + cosConstant) + constant);
}

void CCosinFunc::FSLDVisualFunc(bool bOn)
{
	__super::FSLDVisualFunc(bOn);
}

void CCosinFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout << koaph * cosKoaph * sin(cosKoaph * rightIntegr + cosConstant) + constant * rightIntegr
		- koaph * cosKoaph * sin(cosKoaph * leftIntegr + cosConstant) - constant * leftIntegr << '\n';
}
void CCosinFunc::FFindCor()
{
	if (abs(koaph) < abs(constant))
	{
		std::cout << "\n������ ���\n";
		return;
	}
	if (abs(koaph) == abs(constant))
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
	std::string bigString;
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ��������� ��� �������� (�� ����)", [](double a) {return a!=0; });
		cosKoaph = Vvod<double>("������� ��������� ��� ��������� (�� ����)", [](double a) {return a!=0; });
		cosConstant = Vvod<double>("������� ��������� ��� ���������",[](double a) {return true; });
		constant = Vvod<double>("������� ��������� ��� �������", [](double a) {return true; });

		__super::Init();
		bigString = std::to_string(koaph) + "cin(" + std::to_string(cosKoaph) + "x+" + std::to_string(cosConstant) + ")" + std::to_string(constant) + '\n';
		bigString += "\n���������� ������������ ���������� = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 0; } ,"���"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "�� �������� � ��������������� �������?"));
	} while (bYouA����� != 1);
	if (cosConstant > 0) cosConstant -= int(abs(cosConstant) / M_PI) * M_PI;
	else cosConstant += int(abs(cosConstant) / M_PI) * M_PI + M_PI;
	if (koaph < 0 || cosKoaph < 0)
	{
		if (koaph < 0 != cosKoaph < 0)cosConstant = M_PI - cosConstant;
		koaph = abs(koaph);
		cosKoaph = abs(cosKoaph);
	}
}