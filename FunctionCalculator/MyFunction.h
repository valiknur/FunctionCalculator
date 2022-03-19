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
	void FDegreePolynomial(); // ������� �������
};

class CDegree : public CFunction
{
public:
	float FCalculate() override;
	void FDegree(); // ���������
};

class CDemonstration : public CFunction
{
public:
	float FCalculate() override;
	void FDemonstration(); // �������������
};

class CLogarithm : public CFunction
{
public:
	float FCalculate() override;
	void FLogarithm(); // ���������������
};

class CSinusFunc : public CFunction
{
public:
	float FCalculate() override;
	void FSinusFunc(); // ���������
};

class CCosinFunc : public CFunction
{
public:
	float FCalculate() override;
	void FCosinFunc(); // ����������
};
void FSLDVisualFunc(CFunction function); // ������ � SDL
void FOpredIntegral(); // ���������� ������������ ��������� �� �������
void FFindCor(); // ����� ����� ��� y=0
void FFindExtremum(); // ����� ����������