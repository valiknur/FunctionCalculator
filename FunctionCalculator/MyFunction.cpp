#include "MyFunction.h"
#include "Change.h"

int main(int argc, char* args[])
{
	setlocale(0, "");
	std::cout << "\033[2J\033[1;1H";
	StartFunction();
	return 0;
}

void StartFunction()
{
	Change(
		{
			{CDegreePlynomial::FDegreePolynomial,"Полином степени"},
			{CDegree::FDegree,"Степенная функция"},
			{CDemonstration::FDemonstration,"Показательная"},
			{CLogarithm::FLogarithm,"Логарифмическая"},
			{CSinusFunc::FSinusFunc,"Синусоида"},
			{CCosinFunc::FCosinFunc,"Косинусоида"}
		});
}