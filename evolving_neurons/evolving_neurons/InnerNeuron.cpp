#include "InnerNeuron.h"

#include <chrono>
#include <random>
#include "Utils.h"
#include "ITransferFunction.h"

InnerNeuron::InnerNeuron(ITransferFunction* transferFunction, float initialValue) :
	m_transferFunction(transferFunction),
	m_value(initialValue)
{
}

InnerNeuron::~InnerNeuron()
{
	delete m_transferFunction;
}

float InnerNeuron::getValue()
{
	return m_value;
}

void InnerNeuron::connectSource(ISource* source)
{
	m_connectedSources.push_back(source);
	m_weights.push_back(0.0f);
}

void InnerNeuron::changeWeight()
{
	int index = Utils::chooseUniformly(m_weights.size());
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);

	std::normal_distribution<float> normal;
	
	m_weights[index] += normal(generator);
}

void InnerNeuron::collectInputs()
{
	m_collectedInputs.clear();

	std::vector<ISource*>::iterator iter = m_connectedSources.begin();
	int i = 0;

	for( ; iter != m_connectedSources.end(); iter++)
	{
		m_collectedInputs.push_back((*iter)->getValue() * m_weights[i]);
		i++;
	}
}

void InnerNeuron::update()
{
	m_value = (*m_transferFunction)(m_collectedInputs);
}

void InnerNeuron::setTransferFunction(ITransferFunction* transferFuntion)
{
	delete m_transferFunction;

	m_transferFunction = transferFuntion;
}