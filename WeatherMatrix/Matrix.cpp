#include"Matrix.h"

Matrix::Matrix(int l, int h)
{
	_length = l;
	_height = h;

	_myArr = new double*[_height];

	for (int i = 0; i < _height; i++)
		_myArr[i] = new double[_length];
}

Matrix::~Matrix()
{
	for (int i = 0; i < _height; i++)
		delete[] _myArr[i];
	delete[] _myArr;
}

void Matrix::operator = (const Matrix & copyFrom)
{
	_myArr = new double*[_height];

	for (int i = 0; i < _height; i++)
		_myArr[i] = new double[_length];

	_length = copyFrom._length;
	_height = copyFrom._height;

	for (int i = 0; i < _length; i++)
		for (int j = 0; j < _height; j++)
			_myArr[i][j] = copyFrom._myArr[i][j];
}

//double Matrix::