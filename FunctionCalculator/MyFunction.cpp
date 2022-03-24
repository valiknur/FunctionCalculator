#include "MyFunction.h"
#include "Change.h"

#include "DegreePlynomial.h"
#include "Degree.h"
#include "Demonstration.h"
#include "Logarithm.h"
#include "SinusFunc.h"
#include "CosinFunc.h"
int StartFunction()
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
	return 0;
}