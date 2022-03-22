#include "Function.h"
#include "Change.h"

double CFunction::FCalculate(double x) { return x; }
void CFunction::FSLDVisualFunc(bool bOn)
{
	if (bOn)
	{
		wind = SDL_CreateWindow("Graphic", 100, 100, 400, 400, NULL);
	}
	else
	{
	}
}
void CFunction::FOpredIntegral()
{
	std::cout << "«начение определЄнного интегралла:";
}
void CFunction::FFindCor() {}
void CFunction::FFindExtremum() {}
void CFunction::Init()
{
	x = 200;
	y = 200;
	width = 1000;
	height = 800;
	leftIntegr = Vvod<double>("¬ведите левую границу определЄнного интеграла", [](double a) {return true; });
	rightIntegr = Vvod<double>("¬ведите правую границу определЄнного интеграла", [](double a) {return true; });
	if (leftIntegr > rightIntegr) Swap(leftIntegr, rightIntegr);
}