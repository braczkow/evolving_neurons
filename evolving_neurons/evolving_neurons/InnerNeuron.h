#pragma once

#include "ISink.h"
#include "ISource.h"
#include <vector>

class ITransferFunction;

typedef std::vector<float> floats;

class InnerNeuron : public ISource, public ISink
{
public:
	InnerNeuron(ITransferFunction* transferFunction, float initialValue = 0);

	virtual ~InnerNeuron();

	virtual float getValue();

	virtual void connectSource(ISource* source);

	void changeWeight();

	void collectInputs();

	void update();

	void setTransferFunction(ITransferFunction* transferFunction);

private:
	ITransferFunction* m_transferFunction;

	std::vector<ISource*> m_connectedSources;

	floats m_weights;

	floats m_collectedInputs;

	float m_value;
};
