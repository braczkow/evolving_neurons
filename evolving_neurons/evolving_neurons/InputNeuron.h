#pragma once
#include "ISource.h"

class InputNeuron : public ISource
{
public:
	InputNeuron(float value = 0.0f);

	~InputNeuron();

	virtual float getValue();

	void setInputValue(float value);

private:
	float m_value;
};