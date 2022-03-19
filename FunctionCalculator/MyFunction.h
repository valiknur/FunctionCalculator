#pragma once
#include <SDL.h>
#include <iostream>
class CFunction
{
public:
	virtual float FCalculate() = 0;
};
void StartFunction();

class CDegreePlynomial : public CFunction
{
public:
	float FCalculate() override;
	void FDegreePolynomial(); // Полином степени
};

class CDegree : public CFunction
{
public:
	float FCalculate() override;
	void FDegree(); // Степенная
};

class CDemonstration : public CFunction
{
public:
	float FCalculate() override;
	void FDemonstration(); // Показательная
};

class CLogarithm : public CFunction
{
public:
	float FCalculate() override;
	void FLogarithm(); // Логарифмическая
};

class CSinusFunc : public CFunction
{
public:
	float FCalculate() override;
	void FSinusFunc(); // Синусоида
};

class CCosinFunc : public CFunction
{
public:
	float FCalculate() override;
	void FCosinFunc(); // Коинусоида
};
void FSLDVisualFunc(CFunction function); // График в SDL
void FOpredIntegral(); // Вычисления определённого интеграла на отрезке
void FFindCor(); // Найти корни при y=0
void FFindExtremum(); // Найти экстремумы