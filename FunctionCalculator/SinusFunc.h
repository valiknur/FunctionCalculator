#pragma once
#include "Function.h"
class CSinusFunc : public CFunction // Синусоида
{
public:
	static int FSinusFunc();
protected:
	double koaph = 0.0;
	double sinKoaph = 0.0;
	double sinConstant = 0.0;
	double constant = 0.0;

	float FCalculate() override;
	void FSLDVisualFunc(bool bOn) override;
	void FOpredIntegral() override;
	void FFindCor() override;
	void FFindExtremum() override;
	void Init() override;
};