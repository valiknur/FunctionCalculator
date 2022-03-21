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


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
float CDemonstration::FCalculate() { return 0.0f; }
void CDemonstration::FSLDVisualFunc(bool bOn)
{
}
void CDemonstration::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CDemonstration::FFindCor()
{
}
void CDemonstration::FFindExtremum()
{
}
void CDemonstration::Init()
{
	__super::Init();
	koaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	osnow = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	stepKoaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	constant = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
}