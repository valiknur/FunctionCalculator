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
			{CDegreePlynomial::FDegreePolynomial,"������� �������"},
			{CDegree::FDegree,"��������� �������"},
			{CDemonstration::FDemonstration,"�������������"},
			{CLogarithm::FLogarithm,"���������������"},
			{CSinusFunc::FSinusFunc,"���������"},
			{CCosinFunc::FCosinFunc,"�����������"}
		});
}