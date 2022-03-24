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
			{CDegreePlynomial::FDegreePolynomial,"������� �������"},
			{CDegree::FDegree,"��������� �������"},
			{CDemonstration::FDemonstration,"�������������"},
			{CLogarithm::FLogarithm,"���������������"},
			{CSinusFunc::FSinusFunc,"���������"},
			{CCosinFunc::FCosinFunc,"�����������"}
		});
	return 0;
}