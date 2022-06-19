#include "Cursova.h"

#include <thread>
#include <math.h>

namespace NSStatusText
{
	const std::string zeroSize   = "One of parametrs is zero!\n";
	const std::string negSize    = "One of parametrs is negative!\n";
	const std::string notEqSizes = "Matrix parameters don't satisfy the requirements!\n";
	const std::string validSigns = "Invalid paramets of sign after coma:\n";
	const std::string validSizes = "Checked: good, start generating matrixs:\n";
};

namespace NSPathAndNames
{
	const std::string matrixA = "Matrixs/matrixA.md";
	const std::string matrixB = "Matrixs/matrixB.md";
	const std::string Result1 = "Matrixs/result1.md";
	const std::string Result2 = "Matrixs/result2.md";
};



Cursova::Cursova(int threads):threadpool(threads)
{
	std::cout << "Glory to Ukraine!\n";
}

bool Cursova::inputSize()
{
	std::cout << "Input number of sign after coma: ";
	std::cin >> sign;

	std::cout << "Input number of raws for matrix A: ";
	std::cin >> ARaws;

	std::cout << "Input number of columns for matrix A: ";
	std::cin >> AColumns;

	std::cout << "Input number of raws for matrix B: ";
	std::cin >> BRaws;

	std::cout << "Input number of columns for matrix B: ";
	std::cin >> BColumns;
	
	checkSizes();

	std::cout << statusMsg << '\n';

	return validSizes;
}

void Cursova::creatingMatrixs()
{
	A.setSize(ARaws, AColumns, sign, false);
	C.setSize(ARaws, BColumns, sign, true);
	D.setSize(ARaws, BColumns, sign, true);
	B.setSize(BRaws, BColumns, sign, false);

	A.setPath(NSPathAndNames::matrixA);
	B.setPath(NSPathAndNames::matrixB);
	C.setPath(NSPathAndNames::Result1);
	D.setPath(NSPathAndNames::Result2);
}

void Cursova::printMatrix()
{
	A.getMatrix();
	B.getMatrix();
	C.getMatrix();
	D.getMatrix();
}

void Cursova::simpleMultiplication()
{
	unsigned int start_time = clock();
	for (size_t i = 0; i < C.getRaws(); ++i)
	{
		for (size_t j = 0; j < C.getColumns(); ++j)
		{
			C.setElement(i, j, scalarMult(i,j));
		}
	}
	unsigned int end_time = clock();
	simpleMult = end_time - start_time; 
	std::cout << "Simple Multiplication: " << simpleMult << '\n';
}


void Cursova::checkSizes()
{
	if(ARaws == 0 || AColumns == 0 || BRaws == 0 || BColumns == 0)
	{ 
		statusMsg  = NSStatusText::zeroSize;
		validSizes = false;
	}
	else if (ARaws < 0 || AColumns < 0 || BRaws < 0 || BColumns < 0)
	{
		statusMsg  = NSStatusText::negSize;
		validSizes = false;
	}
	else if (AColumns != BRaws)
	{
		statusMsg  = NSStatusText::notEqSizes;
		validSizes = false;
	}
	else if (sign > 8 || sign < 0)
	{
		statusMsg = NSStatusText::validSigns;
		validSizes = false;
	}
	else
	{
		statusMsg  = NSStatusText::validSizes;
		validSizes = true;
	}
}

double Cursova::scalarMult(int i, int j)
{
	scalar = 0.0;

	for (size_t a = 0; a < AColumns; ++a)
	{
		scalar += A.getElement(i, a) * B.getElement(a, j);
	}
	return scalar;
}

void Cursova::plusplus(int i)
{
	 ++a;
	 std::cout << a << ' ' << i << '\n';
}

int plus(int i)
{
	int a = 0;
	++a;
	std::cout << a << ' ' << i << '\n';
	return 0;
}
void funct(std::function<void(Cursova&, int)>) {
	
	//std::cout << ++i;
}



 void Cursova::multihMultiplication()
{	
	unsigned int start_time = clock();
	for (size_t i = 0; i < C.getRaws(); ++i)
	{
		for (size_t j = 0; j < C.getColumns(); ++j)
		{
			threadpool.submit(D.setElement(i, j, scalarMult(i, j)));
		}
	}
	while (!threadpool.cheskStatusofTasks()) {}
	unsigned int end_time = clock();
	multMult = end_time - start_time;
	std::cout << "Mult Multiplication: " << multMult << '\n';
	status = checkResult();
}

 void Cursova::setNumOfTask()
 {
	 threadpool.setNumOfTasks(C.getColumns() * C.getRaws());
 }

 bool Cursova::checkResult()
 {
	 double temp = 0.0;
	 for (size_t i = 0; i < sign; ++i)
	 {
		 range /= 10;
		 negativeRange /= 10;
	 }
	 for (size_t i = 0; i < C.getRaws(); ++i)
	 {
		 for (size_t j = 0; j < C.getColumns(); ++j)
		 {
			 temp = C.getElement(i, j) - D.getElement(i, j);
			 if (temp > range || temp < negativeRange)
			 {
				 std::cout << "RESULTS ARE NOT EQUAL" << '\n';
				 return false;
			 }
		 }
	 }
	 std::cout << "RESULTS ARE EQUAL" << '\n';
	 return true;
 }

