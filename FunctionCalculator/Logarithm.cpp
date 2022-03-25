#include "Logarithm.h"
#include "Change.h"

#define LN log()
int CLogarithm::FLogarithm()
{
	CLogarithm func;
	func.Init();

	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	std::cout << "конец";
	system("pause");
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CLogarithm::FCalculate(double x) 
{
	return koaph * log(koaphLog * x) + constant;
}
void CLogarithm::FSLDVisualFunc(bool bOn)
{
	if (bOn)
	{
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 0);
		SDL_RenderClear(renderer);
		SDL_Point arr[499];
		// -10 .. 10; -10C = 0P; 0C = 500P; 10C = 1000P; 
		// -8 .. 8; 8C = 0P; 0C = 400P; -8C = 800P; 
		wind = SDL_CreateWindow("Graphic",
			400,
			100,
			1000,
			800,
			NULL);
		renderer = SDL_CreateRenderer(wind, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderDrawLine(renderer, 0, 400, 1000, 400);
		SDL_RenderDrawLine(renderer, 500, 0, 500, 800);
		if (koaphLog > 0)
		{
			for (int i = 501; i < 1000; i++)
			{
				arr[i - 501] = { i,int(400 - 50 * FCalculate(-10 + 0.02 * i)) };
			}
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLines(renderer, arr, 499);
		}
		else
		{
			for (int i = 0; i < 500; i++)
			{
				arr[i] = { i,int(400 - 50 * FCalculate(-10 + 0.02 * i)) };
			}
			SDL_SetRenderDrawColor(renderer, 200, 0, 0, 0);
			SDL_RenderDrawLines(renderer, arr, 499);
		}
		SDL_RenderPresent(renderer);
	}
	else
	{
		if (renderer != nullptr)
		{
			SDL_DestroyRenderer(renderer);
		}
		if (wind != nullptr)
		{
			SDL_DestroyWindow(wind);
		}
	}
}
void CLogarithm::FOpredIntegral()
{
	__super::FOpredIntegral();
	std::cout << koaph / log(koaphLog * rightIntegr) *  rightIntegr + koaph * rightIntegr * log(koaphLog * rightIntegr) + (constant - koaph) * rightIntegr -
				 koaph / log(koaphLog * leftIntegr) * leftIntegr - koaph * leftIntegr * log(koaphLog * leftIntegr) - (constant - koaph) * leftIntegr;
}
void CLogarithm::FFindCor()
{
	std::cout << "\nкорень = " << pow(exp(1), -constant / koaph) / koaphLog;
}
void CLogarithm::FFindExtremum()
{
	std::cout << "\nэкстремумов нет\n";
}
void CLogarithm::Init()
{
	std::string bigString;
	int bYouAагрее = 0;
	do
	{
		CLEARCONSOLE;
		koaph = Vvod<double>("Введите коэфицент для логарифма (не нуль)", [](double a) {return a!=0; });
		koaphLog = Vvod<double>("Введите коэфицент для аргуметна(не нуль)", [](double a) {return a!=0; });
		constant = Vvod<double>("Введите константу", [](double a) {return true; });

		__super::Init();
		bigString = std::to_string(koaph) + "ln(" + std::to_string(koaphLog) + "x)" + std::to_string(constant) + '\n';
		bigString += "\nПромежуток определённого интегралла = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 0; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
};