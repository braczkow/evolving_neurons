#pragma once

#include "INetStructure.h"

#include <vector>

class NetStructureImpl : public INetStructure
{
public:
	NetStructureImpl(void);
	virtual ~NetStructureImpl(void);

	virtual void addInput(IInput* input);

	virtual void addOutput(IOutput* output);

private:
	std::vector<IInput*> m_inputs;

	std::vector<IOutput*> m_outputs;

};

