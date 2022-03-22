#pragma once
#include "Function.h"
class CLogarithm : public CFunction // Логарифмическая
{
public:
	static int FLogarithm();
protected:

	double koaph = 0.0;
	double koaphLog = 0.0;
	double constant = 0.0;

	double FCalculate(double x) override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

