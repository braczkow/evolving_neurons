#include "NetImpl.h"

#include "InputNeuron.h"
#include "OutputNeuron.h"
#include "InnerNeuron.h"

#include "NeuronFactory.h"

#include "Utils.h"

#include <cstdlib>

NetImpl::NetImpl(int inputs /* = 1 */, int outputs /* = 1*/)
{
	for (int i = 0; i < inputs; i++)
	{
		m_inputLayer.push_back(new InputNeuron());
	}

	for (int i = 0; i < outputs; i++)
	{
		m_outputLayer.push_back(new OutputNeuron());
	}
}


NetImpl::~NetImpl(void)
{
	{ //delete all input neurons
		std::vector<InputNeuron*>::iterator iter = m_inputLayer.begin();
		for ( ; iter != m_inputLayer.end(); iter++)
		{
			delete *iter;
		}
	}

	{ //delete all inner neurons
		std::vector<InnerNeuron*>::iterator iter = m_innerLayer.begin();
		for ( ; iter != m_innerLayer.end(); iter++)
		{
			delete *iter;
		}
	}

	{ //delete all output neurons
		std::vector<OutputNeuron*>::iterator iter = m_outputLayer.begin();
		for ( ; iter != m_outputLayer.end(); iter++)
		{
			delete *iter;
		}
	}

	delete m_evolutionSelector;
}

void NetImpl::evolve()
{
	EEvolutionType evolutionType = m_chooseEvoltionType();

	switch (evolutionType)
	{
		case AddNeuron : m_addNeuron(); break;

		case AddConnection : m_addConnection(); break;

		case ChangeWeight : m_changeWeight(); break;

		default:
			break;
	}
}


floats NetImpl::step(floats inputs)
{
	m_collectInputs(inputs);

	m_updateLayers();

	return m_readOutputs();
}

void NetImpl::setEvolutionSelector(IEvolutionSelector* selector)
{
	delete m_evolutionSelector; //?

	m_evolutionSelector = selector;
}

EEvolutionType NetImpl::m_chooseEvoltionType()
{
	return m_evolutionSelector->getEvolution();
}

void NetImpl::m_addNeuron()
{
	m_innerLayer.push_back( NeuronFactory::createInnerNeuron() );
}

void NetImpl::m_addConnection()
{
	std::vector<ISource*> sources(m_innerLayer.begin(), m_innerLayer.end());
	sources.insert(sources.begin(), m_innerLayer.begin(), m_innerLayer.end());

	std::vector<ISink*> sinks(m_innerLayer.begin(), m_innerLayer.end());
	sinks.insert(sinks.begin(), m_outputLayer.begin(), m_outputLayer.end());

	int source = m_choose(sources.size());
	int sink = m_choose(sinks.size());

	sinks[sink]->connectSource(sources[source]);	
}

void NetImpl::m_changeWeight()
{
	int neuron = m_choose(m_innerLayer.size());

	m_innerLayer[neuron]->changeWeight();
}

void NetImpl::m_collectInputs(floats inputs)
{
	std::vector<InputNeuron*>::iterator inputIter = m_inputLayer.begin();
	floats::iterator inputsIter = inputs.begin();
	for ( ; inputIter != m_inputLayer.end(); inputIter++, inputsIter++)
	{
		(*inputIter)->setInputValue(*inputsIter);
	}

	std::vector<InnerNeuron*>::iterator innerIter = m_innerLayer.begin();
	for ( ; innerIter != m_innerLayer.end(); innerIter++)
	{
		(*innerIter)->collectInputs();
	}

	//std::vector<OutputNeuron*>::iterator outputIter = m_outputLayer.begin();
	//for ( ; outputIter != m_outputLayer.end(); outputIter++)
	//{
	//	(*outputIter)->collectInputs();
	//}
}

void NetImpl::m_updateLayers()
{
	std::vector<InnerNeuron*>::iterator innerIter = m_innerLayer.begin();
	for ( ; innerIter != m_innerLayer.end(); innerIter++)
	{
		(*innerIter)->update();
	}

	std::vector<OutputNeuron*>::iterator outputIter = m_outputLayer.begin();
	for ( ; outputIter != m_outputLayer.end(); outputIter++)
	{
		(*outputIter)->update();
	}
}

floats NetImpl::m_readOutputs()
{
	floats result;

	std::vector<OutputNeuron*>::iterator outputIter = m_outputLayer.begin();
	for ( ; outputIter != m_outputLayer.end(); outputIter++)
	{
		result.push_back((*outputIter)->readOutputValue());
	}

	return result;
}

int NetImpl::m_choose(int max)
{
	return Utils::chooseUniformly(max);
}