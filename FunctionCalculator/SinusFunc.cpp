#include "SinusFunc.h"
#include "Change.h"

int CSinusFunc::FSinusFunc()
{
	CSinusFunc func;
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
double CSinusFunc::FCalculate(double x)
{
	return -(koaph * sin(sinKoaph * x + sinConstant) + constant);
}
void CSinusFunc::FSLDVisualFunc(bool bOn)
{
	__super::FSLDVisualFunc(bOn);

}
void CSinusFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout << - koaph * sinKoaph * cos(sinKoaph * rightIntegr + sinConstant) - constant * rightIntegr
				 + koaph * sinKoaph * cos(sinKoaph * leftIntegr + sinConstant) + constant * leftIntegr << '\n';
}
void CSinusFunc::FFindCor()
{
	if (abs(constant) < abs(koaph))
	{
		std::cout << "\n������ ���\n";
		return;
	}
	if (abs(constant) == abs(koaph))
	{
		std::cout << "\n�����: " << asin(-constant / koaph) / sinKoaph - sinConstant << "+2*pi*k\n";
		return;
	}
	std::cout << "\n�����: " << (asin(-constant / koaph) - sinConstant) / sinKoaph << "+" << 2 / sinKoaph << "*pi*k � "
					 << ((M_PI - asin(-constant / koaph)) - sinConstant) / sinKoaph << "+" << 2 / sinKoaph << "*pi*k\n";
}
void CSinusFunc::FFindExtremum()
{
	std::cout << "\n����������:";
	std::cout << "\n��������: " << sinKoaph * M_PI / 2 - sinConstant << "+" << 2 / sinKoaph << "*pi*k";
	std::cout << "\n�������: " << (-sinKoaph) * M_PI / 2 - sinConstant << "+" << 2 / sinKoaph << "*pi*k\n";
}
void CSinusFunc::Init()
{
	std::string bigString;
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("������� ��������� ��� ������ (�� ����)", [](double a) {return a != 0; });
		sinKoaph = Vvod<double>("������� ��������� ��� ��������� (�� ����)", [](double a) {return a != 0; });
		sinConstant = Vvod<double>("������� ��������� ��� ��������� ", [](double a) {return true; });
		constant = Vvod<double>("������� ��������� ��� �������", [](double a) {return true; });

		__super::Init();
		bigString = std::to_string(koaph) + "cin(" + std::to_string(sinKoaph) + "x+" + std::to_string(sinConstant) + ")" + std::to_string(constant) + '\n';
		bigString += "\n���������� ������������ ���������� = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 0; } ,"���"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "�� �������� � ��������������� �������?"));
	} while (bYouA����� != 1);
	if (sinConstant > 0) sinConstant -= int(abs(sinConstant) / M_PI) * M_PI;
	else sinConstant += int(abs(sinConstant) / M_PI) * M_PI + M_PI;
	if (koaph < 0 || sinKoaph < 0)
	{
		if (koaph < 0 != sinKoaph < 0)sinConstant = M_PI - sinConstant;
			koaph = abs(koaph);
			sinKoaph = abs(sinKoaph);
	}
}