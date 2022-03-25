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


	std::cout << "конец";
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
		std::cout << "\nкорень = " << log(constant / koaph) / log(osnow) - stepKoaph;
	}
}
void CDemonstration::FFindExtremum()
{
	std::cout << "\nэкстремумов нет\n";
}
void CDemonstration::Init()
{
	std::string bigString;
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент (больше 0)", [](double a) {return a>0; });
		osnow = Vvod<double>("Введите основу (больше 0)", [](double a) {return a>0; });
		stepKoaph = Vvod<double>("Введите коэфицент степени (не нуль)", [](double a) {return a!=0; });
		constant = Vvod<double>("Введите константу", [](double a) {return true; });
		__super::Init();
		bigString = std::to_string(koaph) + std::to_string(osnow) + "^" + std::to_string(stepKoaph) + std::to_string(stepKoaph) + ")" + std::to_string(constant) + '\n';
		bigString += "\nПромежуток определённого интегралла = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 0; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string("Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
}