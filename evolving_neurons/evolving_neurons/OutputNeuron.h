#pragma once 

#include "ISink.h"

class OutputNeuron : public ISink
{
public:
	virtual void connectSource(ISource* source);

	float readOutputValue();

	void update();

private:
	ISource* m_connectedSource;

	float m_value;
};