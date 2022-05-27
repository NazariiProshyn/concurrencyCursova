#pragma once

#include <iostream>

class Matrix
{
public:
	Matrix() = default;
	~Matrix();
	void setSize(int raws, int columns, bool isMatrixResult);
	void setPath(std::string path);
	int  getRaws() { return raws; }
	int  getColumns() { return columns; }
	void getMatrix();
private:
	std::string path = "";
	void createMatrix(bool isMatrixResult);
	int raws = 0;
	int columns = 0;
	int** matrix = nullptr;
};

