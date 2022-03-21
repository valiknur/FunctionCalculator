#include "CosinFunc.h"
#include "Change.h"

int CCosinFunc::FCosinFunc()
{
	CCosinFunc func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
	return 0;
}
float CCosinFunc::FCalculate() { return 0.0f; }
void CCosinFunc::FSLDVisualFunc(bool bOn)
{
}
void CCosinFunc::FOpredIntegral()
{
	__super::FOpredIntegral();
}
void CCosinFunc::FFindCor()
{
}
void CCosinFunc::FFindExtremum()
{
}
void CCosinFunc::Init()
{
	__super::Init();
	koaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	cosKoaph = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	cosConstant = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
	constant = Vvod<double>("¬ведите левую границу", [](double a) {return true; });
}