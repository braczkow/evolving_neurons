#pragma once

class ISource;

class ISink {
public:
	virtual void connectSource(ISource* source) = 0;
};