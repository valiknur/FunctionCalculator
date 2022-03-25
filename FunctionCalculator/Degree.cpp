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


	std::cout << "конец";
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
	__super::FSLDVisualFunc(bOn);
}
void CDegree::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout <<	koaph / (step + 1) * pow(rightIntegr, step + 1) + constant * rightIntegr -
					koaph / (step + 1) * pow(leftIntegr, step + 1) + constant * leftIntegr;
}
void CDegree::FFindCor()
{
	std::cout << "\nкорень=" << pow(constant, 1 / step) << '\n';
}
void CDegree::FFindExtremum()
{
	std::cout << "\nэкстремум в точке 0\n";
}
void CDegree::Init()
{
	std::string bigString = "";
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент (не нуль)", [](double a) {return a != 0; });
		step = Vvod<double>("Введите степень (не нуль)", [](double a) {return a != 0; });
		constant = Vvod<double>("Введите константу", [](double a) {return true; });

		__super::Init();
		std::cout << koaph << "*x^" << step << " + " << constant;
		bigString = std::to_string(koaph) + "*x^" + std::to_string(step) + " + " + std::to_string(constant);
		bigString += "\nПромежуток определённого интегралла = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 0; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
	std::cout << bigString;
}