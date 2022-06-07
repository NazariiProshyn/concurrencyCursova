#pragma once

#include <iostream>
#include <mutex>
class Matrix
{
public:
	Matrix() = default;
	~Matrix();
	void setSize(int raws, int columns, int sign, bool isMatrixResult);
	void setPath(std::string path);
	void setElement(int raw, int column, double element);//асинхронний запис елемента
	void setMElement(int raw, int column, double element);//синхронний
	double  getElement(int raw, int column);
	int  getRaws() { return raws; }
	int  getColumns() { return columns; }
	void getMatrix();
private:
	std::string path = "";
	void createMatrix(bool isMatrixResult);
	int raws = 0;
	int columns = 0;
	double** matrix = nullptr;
	std::mutex mtx;
	int sign = 0;
	int range = 10;
};

