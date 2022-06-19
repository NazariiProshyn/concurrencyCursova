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

void Matrix::setSize(int raws, int columns, int sign, bool isMatrixResult)
{
	this->raws = raws;
	this->columns = columns;
	this->sign = sign;
	for (size_t i = 0; i < sign; ++i)
	{
		range *= 10;
	}
	createMatrix(isMatrixResult);
}

void Matrix::setPath(std::string path)
{
	this->path = path;
}

void Matrix::setElement(int raw, int column, double element)
{
	matrix[raw][column] = element;
}

void Matrix::setMElement(int raw, int column, double element)
{
	std::lock_guard<std::mutex> guard(mtx);
	matrix[raw][column] = element;
}

double Matrix::getElement(int raw, int column)
{
	return matrix[raw][column];
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
	double temp;
	srand(time(NULL));
	matrix = new double* [raws];
	for (size_t i = 0; i < raws; ++i)
	{
		matrix[i] = new double[columns];
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
				temp = rand() % range;
				range /= 10;
				temp /= range;
				range *= 10;
				matrix[i][j] = temp;
			} 
		}
	}
}
