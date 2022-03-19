#include "MyFunction.h"
#include "Change.h"
int main(int argc, char* args[])
{
	return 0;
}

void StartFunction()
{
	Foo arr(  CDegreePlynomial::FDegreePolynomial, "Полином степени");
	Change(
		6,
		{
			{CDegreePlynomial::FDegreePolynomial,"Полином степени"},
			{CDegree::FDegree,"Степенная функция"}
		}
		);
}

void funcText();
float CDegreePlynomial::FCalculate()
{
	return 0.0f;
}

void CDegreePlynomial::FDegreePolynomial()
{

}

float CDegree::FCalculate()
{
	return 0.0f;
}

void CDegree::FDegree()
{

}

float CDemonstration::FCalculate()
{
	return 0.0f;
}
void CDemonstration::FDemonstration()
{

}

float CLogarithm::FCalculate()
{
	return 0.0f;
}
void CLogarithm::FLogarithm()
{

}

float CSinusFunc::FCalculate()
{
	return 0.0f;
}

void CSinusFunc::FSinusFunc()
{

}

float CCosinFunc::FCalculate()
{
	return 0.0f;
}

void CCosinFunc::FCosinFunc()
{

}

void FSLDVisualFunc(CFunction function)
{
}

void FOpredIntegral()
{
}

void FFindCor()
{
}

void FFindExtremum()
{
}