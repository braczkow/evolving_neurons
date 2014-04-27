#pragma once

class IInput;
class IOutput;

class INetStructure
{
public:
	INetStructure(void) {}
	virtual ~INetStructure(void){}

	virtual void addInput(IInput* input) = 0;

	virtual void addOutput(IOutput* output) = 0;
};

