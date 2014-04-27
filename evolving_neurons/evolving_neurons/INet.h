#pragma once

class INetStructure;

enum EEvolutionType
{
	AddNeuron,
	AddConnection,
	ChangeWeight,

	EvolutionTypeMax
};

class IEvolutionSelector
{
public:
	virtual EEvolutionType getEvolution() = 0;
};

class INet
{
public:
	INet(void) {}
	virtual ~INet(void) {}

	virtual void evolve() = 0;

	virtual void step() = 0;

	virtual void setEvolutionSelector(IEvolutionSelector* selector) = 0;
};

