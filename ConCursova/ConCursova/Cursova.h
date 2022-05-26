#pragma once

#include <iostream>

class Cursova
{
public:
	Cursova();
	~Cursova() = default;
	bool inputSize();
	bool creatingMatrixs();
private:
	int ARaws    = 0;
	int AColumns = 0;
	int BRaws    = 0;
	int BColumns = 0;

	bool validSizes = true;
	std::string statusMsg = "";

	void checkSizes();

};

