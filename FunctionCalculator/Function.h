#pragma once
#include "Resourse.h"
class CFunction
{
protected:
	enum OnOff
	{
		OFF = 0,
		ON = 1
	};
	SDL_Window* wind = NULL;
	SDL_Surface* pictures = NULL;
	SDL_Renderer* renderer = NULL;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	double leftIntegr = 0.0;
	double rightIntegr = 0.0;
	virtual double FCalculate(double x);
	virtual void FSLDVisualFunc(bool bOn); // ������ � SDL
	virtual void FOpredIntegral(); // ���������� ������������ ��������� �� �������
	virtual void FFindCor(); // ����� ����� ��� y=0
	virtual void FFindExtremum(); // ����� ����������
	virtual void Init();
	~CFunction();
};