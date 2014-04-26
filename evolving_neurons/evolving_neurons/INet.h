#pragma once

class INetStructure;

class INet
{
public:
	INet(void) {}
	virtual ~INet(void) {}

	virtual void evolve() = 0;

	virtual void step() = 0;

	virtual INetStructure* getStructure() = 0; 
};

