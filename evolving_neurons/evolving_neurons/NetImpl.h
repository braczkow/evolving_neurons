#pragma once

#include "INet.h"

#include <vector>

typedef std::vector<float> floats;

class ISource {
public:
	virtual float getValue() = 0;
};

class ISink {
public:
	virtual void connectSource(ISource* source) = 0;
};

class InputNeuron : public ISource
{
public:
	virtual float getValue();

	void setInputValue(float value);
};

class InnerNeuron : public ISource, public ISink
{
public:
	virtual float getValue();

	virtual void connectSource(ISource* source);

	void collectInputs();

	void update();
};

class OutputNeuron : public ISink
{
public:
	virtual void connectSource(ISource* source);

	float readOutputValue();

	void collectInputs();

	void update();
};

class NetImpl : public INet
{
public:
	NetImpl(int inputs = 1, int outputs = 1);
	~NetImpl(void);

	virtual void evolve()
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

	virtual floats step(floats inputs)
	{
		m_collectInputs(inputs);

		m_updateLayers();

		return m_readOutputs();
	}

	virtual void setEvolutionSelector(IEvolutionSelector* selector)
	{
		delete m_evolutionSelector;

		m_evolutionSelector = selector;
	}

private:

	EEvolutionType m_chooseEvoltionType()
	{
		return m_evolutionSelector->getEvolution();
	}

	void m_addNeuron()
	{
		m_innerLayer.push_back(new InnerNeuron());
	}

	void m_addConnection()
	{
		std::vector<ISource*> sources(m_innerLayer.begin(), m_innerLayer.end());
		sources.insert(sources.begin(), m_innerLayer.begin(), m_innerLayer.end());

		std::vector<ISink*> sinks(m_innerLayer.begin(), m_innerLayer.end());
		sinks.insert(sinks.begin(), m_outputLayer.begin(), m_outputLayer.end());

		int sourcesCount = sources.size();
		int sinksCount = sinks.size();
		

	}

	void m_changeWeight();

	void m_collectInputs(floats inputs)
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

		std::vector<OutputNeuron*>::iterator outputIter = m_outputLayer.begin();
		for ( ; outputIter != m_outputLayer.end(); outputIter++)
		{
			(*outputIter)->collectInputs();
		}
	}

	void m_updateLayers()
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

	floats m_readOutputs()
	{
		floats result;

		std::vector<OutputNeuron*>::iterator outputIter = m_outputLayer.begin();
		for ( ; outputIter != m_outputLayer.end(); outputIter++)
		{
			result.push_back((*outputIter)->readOutputValue());
		}
	}

	std::vector<InputNeuron*> m_inputLayer;

	std::vector<InnerNeuron*> m_innerLayer;

	std::vector<OutputNeuron*> m_outputLayer;

	IEvolutionSelector* m_evolutionSelector;

};

