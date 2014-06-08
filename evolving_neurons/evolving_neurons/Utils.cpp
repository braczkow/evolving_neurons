#include "Utils.h"

#include <cstdlib>

Utils::~Utils(void)
{
}

int Utils::chooseUniformly(int max)
{
	return rand() % max;
}
