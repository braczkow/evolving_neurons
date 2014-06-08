#pragma once

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
