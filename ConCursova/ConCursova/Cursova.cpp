#include "Cursova.h"

namespace NSStatusText
{
	const std::string zeroSize   = "One of parametrs is zero!\n";
	const std::string negSize    = "One of parametrs is negative!\n";
	const std::string notEqSizes = "Matrix parameters don't satisfy the requirements!\n";
	const std::string validSizes = "Checked: good, start generating matrixs:\n";
};

namespace NSPathAndNames
{
	const std::string matrixA = "Matrixs/matrixA.md";
	const std::string matrixB = "Matrixs/matrixB.md";
	const std::string Result1 = "Matrixs/result1.md";
	const std::string Result2 = "Matrixs/result2.md";
};


Cursova::Cursova()
{
	std::cout << "Glory to Ukraine!\n";
}

bool Cursova::inputSize()
{
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
	A.setSize(ARaws, AColumns, false);
	B.setSize(BRaws, BColumns, false);
	C.setSize(ARaws, BColumns, true);
	D.setSize(ARaws, BColumns, true);

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
	else
	{
		statusMsg  = NSStatusText::validSizes;
		validSizes = true;
	}
}
