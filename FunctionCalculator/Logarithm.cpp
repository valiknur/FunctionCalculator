#include "Logarithm.h"
#include "Change.h"

int CLogarithm::FLogarithm()
{
	CLogarithm func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
float CLogarithm::FCalculate() { return 0.0f; }
void CLogarithm::FSLDVisualFunc(bool bOn)
{
}
void CLogarithm::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CLogarithm::FFindCor()
{
}
void CLogarithm::FFindExtremum()
{
}
void CLogarithm::Init()
{
	__super::Init();
	koaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	koaphLog = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	constant = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
}