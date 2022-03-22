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


	system("pause");
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDegreePlynomial::FCalculate(double x) 
{ 
	double summ = 0.0;
	double dx = 1;
	for (size_t i = 0; i < arr.size(); i++)
	{
		summ += arr[i] * dx;
		dx *= x;
	}
	return summ; 
}
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
	int bYouAагрее = 0;
	std::string bigString = "";
	do
	{
		bigString = "";
		CLEARCONSOLE;
		size = Vvod<size_t>("Введите количество параметров от 1 до 9", [](size_t a) {return a > 0 || a < 10; });
		std::cout << "Вводите " << size << " значения\n";
		double delta;
		for (size_t i = 0; i < size; i++)
		{
			delta = Vvod<double>();
			this->arr.push_back(delta);
		}
		__super::Init();

		bigString += "\n" + std::to_string(arr[0]);
		for (size_t i = 1; i < size; i++)
		{
			bigString += (arr[i] < 0 ? " - " : " + ") + std::to_string(abs(arr[i])) + "*x^" + std::to_string(i);
		}
		bigString += "\nПромежуток определённого интегралла = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 2; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
}