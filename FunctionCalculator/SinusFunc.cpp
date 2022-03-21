#include "SinusFunc.h"
#include "Change.h"

int CSinusFunc::FSinusFunc()
{
	CSinusFunc func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
float CSinusFunc::FCalculate() { return 0.0f; }
void CSinusFunc::FSLDVisualFunc(bool bOn)
{
}
void CSinusFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CSinusFunc::FFindCor()
{
}
void CSinusFunc::FFindExtremum()
{
}
void CSinusFunc::Init()
{
	__super::Init();
	koaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	sinKoaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	sinConstant = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	constant = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
}