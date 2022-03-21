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
	int x;
	int y;
	int width;
	int height;
	double leftIntegr;
	double rightIntegr;
	virtual float FCalculate();
	virtual void FSLDVisualFunc(bool bOn); // ������ � SDL
	virtual void FOpredIntegral(); // ���������� ������������ ��������� �� �������
	virtual void FFindCor(); // ����� ����� ��� y=0
	virtual void FFindExtremum(); // ����� ����������
	virtual void Init();

};