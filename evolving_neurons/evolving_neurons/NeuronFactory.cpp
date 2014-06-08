#include "NeuronFactory.h"

#include "InputNeuron.h"
#include "InnerNeuron.h"
#include "OutputNeuron.h"

#include "SigmoidTransferFunction.h"

NeuronFactory::~NeuronFactory(void)
{
}

InputNeuron* NeuronFactory::createInputNeuron()
{
	return new InputNeuron();
}

InnerNeuron* NeuronFactory::createInnerNeuron()
{
	return new InnerNeuron(new SigmoidTransferFunction());
}

OutputNeuron* NeuronFactory::createOutputNeuron()
{
	return new OutputNeuron();
}