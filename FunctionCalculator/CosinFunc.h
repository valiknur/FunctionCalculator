#pragma once
#include "Function.h"
class CCosinFunc : public CFunction // Коинусоида
{
public:
	static int FCosinFunc();
protected:
	double koaph = 0.0;
	double cosKoaph = 0.0;
	double cosConstant = 0.0;
	double constant = 0.0;

	double FCalculate(double x) override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};

