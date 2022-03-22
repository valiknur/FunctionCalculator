#include "DegreePlynomial.h"
#include "Change.h"

int CDegreePlynomial::FDegreePolynomial()
{
	CDegreePlynomial func;
	func.Init();

	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDegreePlynomial::FCalculate(double x) { return 0.0f; }
void CDegreePlynomial::FSLDVisualFunc(bool bOn)
{
	if (bOn)
	{

	}
	else
	{

	}
}
void CDegreePlynomial::FOpredIntegral()
{
	__super::FOpredIntegral();
	double delta = 0;
	double deltaleft = this->leftIntegr;
	double deltaright = this->rightIntegr;
	for (size_t i = 0; i < this->size; i++)
	{
		delta += this->arr[i] / (i + 1) * deltaright;
		delta -= this->arr[i] / (i + 1) * deltaleft;
		deltaleft *= this->leftIntegr;
		deltaright *= this->rightIntegr;
	}
	std::cout << delta;
}
void CDegreePlynomial::FFindCor()
{
}
void CDegreePlynomial::FFindExtremum()
{
}
void CDegreePlynomial::Init()
{
	int bYouA����� = 0;
	do
	{
		CLEARCONSOLE;
		size = Vvod<size_t>("������� ���������� ���������� �� 1 �� 9", [](size_t a) {return a > 0 || a < 10; });
		std::cout << "������� " << size << " ��������\n";
		double delta;
		for (size_t i = 0; i < size; i++)
		{
			std::cin >> delta;
			this->arr.push_back(delta);
		}
		__super::Init();

		std::cout << '\n' << arr[0];
		for (size_t i = 1; i < size; i++)
		{
			std::cout << (arr[i] < 0 ? " - " : " + ") << abs(arr[i]) << "*x^" << i;
		}

		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 2; } ,"���"},
			},
			std::string("�� �������� � ��������������� �������?"),
			NONEEXIT | ONETIME);
	} while (bYouA����� != 2);
}