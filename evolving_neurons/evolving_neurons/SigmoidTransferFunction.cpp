#include "SigmoidTransferFunction.h"

#include <cmath>

SigmoidTransferFunction::SigmoidTransferFunction(float beta /*=1.0f*/) :
	m_beta(beta)
{
}


SigmoidTransferFunction::~SigmoidTransferFunction(void)
{
}

float SigmoidTransferFunction::operator()(floats input)
{
	float output;

	float t = 0.0f;

	floats::iterator iter = input.begin();
	for ( ; iter != input.end(); iter++)
	{
		t += (*iter);
	}

	output = 1.0f / (1.0f + expf(-t * m_beta));

	return output;
}
