#include "Cursova.h"

namespace NSStatusText
{
	const std::string zeroSize   = "One of parametrs is zero!\n";
	const std::string negSize    = "One of parametrs is negative!\n";
	const std::string notEqSizes = "Matrix parameters don't satisfy the requirements!\n";
	const std::string validSizes = "Checked: good, start generating matrixs.\n";
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
