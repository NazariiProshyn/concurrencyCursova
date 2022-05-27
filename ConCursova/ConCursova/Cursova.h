#pragma once

#include <iostream>
#include "Matrix.h"

class Cursova
{
public:
	Cursova();
	~Cursova() = default;
	bool inputSize();
	void creatingMatrixs();
	void printMatrix();
private:

	bool validSizes = true;
	std::string statusMsg = "";

	void checkSizes();
	
	int ARaws = 0;
	int AColumns = 0;
	int BRaws = 0;
	int BColumns = 0;

	Matrix A;
	Matrix B;
	Matrix C;
	Matrix D;
};

