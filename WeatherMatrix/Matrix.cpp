#include"Matrix.h"
#include<string>

Matrix::Matrix()
{
	_length = 12; //hardcoded because there will always be 12 months in a year
	_height = 1;
}

Matrix::Matrix(int h, int l)
{
	_height = h;
	_length = l;

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

std::string Matrix::testProperReadin()
{
	std::string sendBack = "";

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _length; j++)
			sendBack += std::to_string(_myArr[i][j]) + "\t";
		sendBack += "\n\n";
	}

	return sendBack;
}

void Matrix::operator = (const Matrix & copyFrom)
{
	_height = copyFrom._height;
	_length = copyFrom._length;

	_myArr = new double*[_height];

	for (int i = 0; i < _height; i++)
		_myArr[i] = new double[_length];

	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _length; j++)
			_myArr[i][j] = copyFrom._myArr[i][j];
}
