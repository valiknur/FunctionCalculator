#pragma once
#include "Function.h"
class CDemonstration : public CFunction // Показательная
{
public:
	static int FDemonstration();
protected:

	double koaph = 0.0;
	double osnow = 0.0;
	double stepKoaph = 0.0;
	double constant = 0.0;

	double FCalculate(double x) override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};