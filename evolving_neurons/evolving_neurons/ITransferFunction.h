#pragma once

#include <vector>

typedef std::vector<float> floats;

class ITransferFunction 
{
public:
	virtual float operator()(floats input) = 0;
};