#include "InputNeuron.h"

InputNeuron::InputNeuron(float value /*=0.0f*/) : 
	m_value(value)
{
}

InputNeuron::~InputNeuron(void)
{
}

float InputNeuron::getValue()
{
	return m_value;
}

void InputNeuron::setInputValue(float value)
{
	m_value = value;
}
