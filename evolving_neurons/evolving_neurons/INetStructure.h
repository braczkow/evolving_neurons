#pragma once
class INetStructure
{
public:
	INetStructure(void) {}
	virtual ~INetStructure(void){}

	virtual void addInput() = 0;
};

