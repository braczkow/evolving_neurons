#pragma once

class InputNeuron;
class InnerNeuron;
class OutputNeuron;

class NeuronFactory
{
public:
	~NeuronFactory(void);

	static InputNeuron* createInputNeuron();

	static InnerNeuron* createInnerNeuron();

	static OutputNeuron* createOutputNeuron();

private:
	NeuronFactory(void);
	NeuronFactory(const NeuronFactory&);
	void operator=(const NeuronFactory&);
};

