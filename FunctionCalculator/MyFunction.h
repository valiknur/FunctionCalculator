#pragma once
#include <windows.h>
#include <vector>
#include <cstdio>
#include <SDL.h>
#include <iostream>
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
	virtual void FSLDVisualFunc(bool bOn); // График в SDL
	virtual void FOpredIntegral(); // Вычисления определённого интеграла на отрезке
	virtual void FFindCor(); // Найти корни при y=0
	virtual void FFindExtremum(); // Найти экстремумы
	virtual void Init();

};
void StartFunction();

class CDegreePlynomial : public CFunction // Полином степени
{
public:
	static void FDegreePolynomial();
protected:

	size_t size = 0;
	std::vector<double> arr;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

class CDegree : public CFunction // Степенная
{
public:
	static void FDegree();
protected:

	double koaph = 0.0;
	double step = 0.0;
	double constant = 0.0;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

class CDemonstration : public CFunction // Показательная
{
public:
	static void FDemonstration();
protected:

	double koaph;
	double osnow;
	double stepKoaph;
	double constant;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

class CLogarithm : public CFunction // Логарифмическая
{
public:
	static void FLogarithm();
protected:

	double koaph = 0.0;
	double koaphLog = 0.0;
	double constant = 0.0;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

class CSinusFunc : public CFunction // Синусоида
{
public:
	static void FSinusFunc();
protected:
	double koaph;
	double sinKoaph;	
	double sinConstant;
	double constant;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

class CCosinFunc : public CFunction // Коинусоида
{
public:
	static void FCosinFunc();
protected:
	double koaph;
	double cosKoaph;
	double cosConstant;
	double constant;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};
