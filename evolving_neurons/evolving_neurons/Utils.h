#pragma once
class Utils
{
public:
	~Utils(void);

	//chooses a int from <0, max) due to uniform distribution
	static int chooseUniformly(int max);

private:
	Utils();
	Utils(const Utils&);
	void operator=(const Utils&);
};

