#pragma once

#include "INet.h"
#include "IEvolutionSelector.h"

#include <vector>

typedef std::vector<float> floats;


class InputNeuron;
class InnerNeuron;
class OutputNeuron;



class NetImpl : public INet
{
public:
	NetImpl(int inputs = 1, int outputs = 1);
	~NetImpl(void);

	virtual void evolve();

	virtual floats step(floats inputs);

	virtual void setEvolutionSelector(IEvolutionSelector* selector);

private:

	EEvolutionType m_chooseEvoltionType();

	void m_addNeuron();

	void m_addConnection();

	void m_changeWeight();

	void m_collectInputs(floats inputs);

	void m_updateLayers();

	floats m_readOutputs();

	int m_choose(int max);

	std::vector<InputNeuron*> m_inputLayer;

	std::vector<InnerNeuron*> m_innerLayer;

	std::vector<OutputNeuron*> m_outputLayer;

	IEvolutionSelector* m_evolutionSelector;

};

