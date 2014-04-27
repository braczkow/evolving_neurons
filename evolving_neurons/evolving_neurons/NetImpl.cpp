#include "NetImpl.h"


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
