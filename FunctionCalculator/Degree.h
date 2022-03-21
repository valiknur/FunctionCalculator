#pragma once
#include "Function.h"
class CDegree : public CFunction // Степенная
{
public:
	static int FDegree();
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

