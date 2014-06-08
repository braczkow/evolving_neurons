#pragma once

class INetStructure;

class IEvolutionSelector;

class INet
{
public:
	INet(void) {}
	virtual ~INet(void) {}

	virtual void evolve() = 0;

	virtual void step() = 0;

	virtual void setEvolutionSelector(IEvolutionSelector* selector) = 0;
};

