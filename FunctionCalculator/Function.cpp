#include "Function.h"
#include "Change.h"

double CFunction::FCalculate(double x) { return x; }
void CFunction::FSLDVisualFunc(bool bOn)
{
	if (bOn)
	{
		SDL_Point arr[1000];
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
		for (int i = 0; i < 1000; i++)
		{
			arr[i] = { i,int(400 - 50 * FCalculate(-10 + 0.02 * i)) };
		}
		SDL_SetRenderDrawColor(renderer, 200, 0, 0, 0);
		SDL_RenderDrawLines(renderer, arr, 1000);
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

CFunction::~CFunction()
{
	if (wind != NULL) SDL_DestroyWindow(wind);
}
