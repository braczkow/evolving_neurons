#pragma once

#include "ITransferFunction.h"

class SigmoidTransferFunction : public ITransferFunction
{
public:
	SigmoidTransferFunction(float beta = 1.0f);
	virtual ~SigmoidTransferFunction(void);

	virtual float operator()(floats input);


private:
	float m_beta;
};

