#include"Matrix.h"

Matrix::Matrix(int l, int h)
{
	_length = l;
	_height = h;

	myArr = new int*[_height];

	for (int i = 0; i < _height; i++)
		myArr[i] = new int[_length];
}

Matrix::~Matrix()
{
	for (int i = 0; i < _height; i++)
		delete[] myArr[_height];
	delete[] myArr;
}


