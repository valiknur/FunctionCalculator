#pragma once
#include "Function.h"
class CDegreePlynomial : public CFunction // Полином степени
{
public:
	static int FDegreePolynomial();
protected:

	size_t size = 0;
	std::vector<double> arr;
	std::vector<double> cor;
	double FCalculate(double x) override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

