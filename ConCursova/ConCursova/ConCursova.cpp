#include "Cursova.h"
#include <iostream>
int main()
{
	int numOfThreads = 0;
	std::cout << "Input num of threads:";
	std::cin >> numOfThreads;
	if (numOfThreads > 0)
	{
		Cursova cursova(numOfThreads);
		

		if (cursova.inputSize())
		{
			cursova.creatingMatrixs();
			cursova.simpleMultiplication();
			cursova.multihMultiplication();
		}
		cursova.printMatrix();
		//std::cout << "RESULTS ARE EQUAL" << '\n';
	}
	return 0;
}
