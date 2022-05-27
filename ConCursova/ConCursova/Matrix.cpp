#include "Matrix.h"

#include <cstdlib>
#include <ctime>
#include <fstream>

Matrix::~Matrix()
{
	for (size_t i = 0; i < raws; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::setSize(int raws, int columns, bool isMatrixResult)
{
	this->raws = raws;
	this->columns = columns;

	createMatrix(isMatrixResult);
}

void Matrix::setPath(std::string path)
{
	this->path = path;
}

void Matrix::getMatrix()
{
	std::ofstream fileIn(path);
	for (size_t i = 0; i < raws; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			fileIn << matrix[i][j] << ' ';
		}
		fileIn << '\n';
	}
}

void Matrix::createMatrix(bool isMatrixResult)
{
	srand(time(NULL));
	matrix = new int* [raws];
	
	for (size_t i = 0; i < raws; ++i)
	{
		matrix[i] = new int[columns];
	}
	if (isMatrixResult)
	{
		for (size_t i = 0; i < raws; ++i)
		{
			for (size_t j = 0; j < columns; ++j)
			{
				matrix[i][j] = 0;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < raws; ++i)
		{
			for (size_t j = 0; j < columns; ++j)
			{
				matrix[i][j] = (rand() % 9) + 1;
			}
		}
	}
}
