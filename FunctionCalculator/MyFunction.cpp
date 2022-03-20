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
	Change(6,
		{
			{CDegreePlynomial::FDegreePolynomial,"Полином степени"},
			{CDegree::FDegree,"Степенная функция"},
			{CDemonstration::FDemonstration,"Показательная"},
			{CLogarithm::FLogarithm,"Логарифмическая"},
			{CSinusFunc::FSinusFunc,"Синусоида"},
			{CCosinFunc::FCosinFunc,"Косинусоида"}
		});
}
float CFunction::FCalculate() { return 0.0f; }
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
	std::cout << "Значение определённого интегралла:";
}
void CFunction::FFindCor() {}
void CFunction::FFindExtremum() {}
void CFunction::Init()
{
	x = 200;
	y = 200;
	width = 1000;
	height = 800;
	leftIntegr = Vvod<double>("Введите левую границу", [](double a) {return true; });
	rightIntegr = Vvod<double>("Введите правую границу", [](double a) {return true; });
	if (leftIntegr > rightIntegr) Swap(leftIntegr, rightIntegr);
}

void CDegreePlynomial::FDegreePolynomial()
{
	CDegreePlynomial func;
	func.Init();
	std::cout << "Ваше уравнение:\n";
	if (func.arr[0] != 0) std::cout << func.arr[0]<<" ";
	for (size_t i = 1; i < func.size; i++)
	{
		if (func.arr[i] == 0) continue;
		std::cout << (func.arr[i] > 0 ? " + " : " - ") << abs(func.arr[i]);
	}
	std::cout << '\n';


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
}
float CDegreePlynomial::FCalculate() { return 0.0f; }
void CDegreePlynomial::FSLDVisualFunc(bool bOn)
{
	if (bOn)
	{

	}
	else
	{

	}
}
void CDegreePlynomial::FOpredIntegral()
{
	__super::FOpredIntegral();
	double delta = 0;
	double deltaleft = this->leftIntegr;
	double deltaright = this->rightIntegr;
	for (size_t i = 0; i < this->size; i++)
	{
		delta += this->arr[i] / (i + 1) * deltaright;
		delta -= this->arr[i] / (i + 1) * deltaleft;
		deltaleft *= this->leftIntegr;
		deltaright *= this->rightIntegr;
	}
	std::cout << delta;
}
void CDegreePlynomial::FFindCor()
{
}
void CDegreePlynomial::FFindExtremum()
{
}
void CDegreePlynomial::Init()
{
	size = Vvod<size_t>("Введите количество параметров от 1 до 9", [](size_t a) {return a>0 || a < 10; });
	std::cout << "Введите значения";
	double delta;
	for (size_t i = 0; i < size; i++)
	{
		std::cin>>delta;
		this->arr.push_back(delta);
	}
	__super::Init();
}

void CDegree::FDegree()
{
	CDegree func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
}
float CDegree::FCalculate() { return 0.0f; }
void CDegree::FSLDVisualFunc(bool bOn)
{
}
void CDegree::FOpredIntegral()
{
}
void CDegree::FFindCor()
{
}
void CDegree::FFindExtremum()
{
}
void CDegree::Init()
{
	__super::Init();
	koaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	step = Vvod<double>("Введите левую границу", [](double a) {return true; });
	constant = Vvod<double>("Введите левую границу", [](double a) {return true; });
}

void CDemonstration::FDemonstration()
{
	CDemonstration func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
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
	koaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	osnow = Vvod<double>("Введите левую границу", [](double a) {return true; });
	stepKoaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	constant = Vvod<double>("Введите левую границу", [](double a) {return true; });
}

void CLogarithm::FLogarithm()
{
	CLogarithm func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
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
	koaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	koaphLog = Vvod<double>("Введите левую границу", [](double a) {return true; });
	constant = Vvod<double>("Введите левую границу", [](double a) {return true; });
}

void CSinusFunc::FSinusFunc()
{
	CSinusFunc func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
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
	koaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	sinKoaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	sinConstant = Vvod<double>("Введите левую границу", [](double a) {return true; });
	constant = Vvod<double>("Введите левую границу", [](double a) {return true; });
}

void CCosinFunc::FCosinFunc()
{
	CCosinFunc func;
	func.Init();


	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	getchar();
	func.FSLDVisualFunc(OFF);
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
	koaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	cosKoaph = Vvod<double>("Введите левую границу", [](double a) {return true; });
	cosConstant = Vvod<double>("Введите левую границу", [](double a) {return true; });
	constant = Vvod<double>("Введите левую границу", [](double a) {return true; });
}

