#include "OutputNeuron.h"
#include "ISource.h"

void OutputNeuron::connectSource(ISource* source)
{
	if (!m_connectedSource)
	{
		m_connectedSource = source;
	}
}

float OutputNeuron::readOutputValue()
{
	return m_value;
}

void OutputNeuron::update()
{
	m_value = m_connectedSource->getValue();
}