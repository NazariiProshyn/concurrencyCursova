#pragma once

#include <iostream>
#include <vector>

#include "threadPool.h"
#include "Matrix.h"


class Cursova
{
public:
	Cursova(int threads);
	~Cursova() = default;
	bool inputSize();
	void creatingMatrixs();
	void printMatrix();
	void simpleMultiplication();//множенн€ посл≥довне
	void multihMultiplication();
	void setNumOfTask();
	
private:
	bool checkResult();
	bool validSizes = true;
	std::string statusMsg = "";

	void checkSizes();
	double scalarMult(int i, int j);//скал€рний добуток
	double scalar = 0.0;

	int ARaws = 0;
	int AColumns = 0;
	int BRaws = 0;
	int BColumns = 0;
	int sign = 0;
	double range = 1.0;
	double negativeRange = -1.0;
	Matrix A;
	Matrix B;
	Matrix C;
	Matrix D;
	const static size_t numOfThreads = 4;
	unsigned int simpleMult = 0;
	unsigned int multMult = 0;
	bool status = false;
	ThreadPool threadpool;
	int a = 0;
	void plusplus(int i);
	
};
