#include"Matrix.h"
#include<string>
#include<iomanip>

Matrix::Matrix()
{
	_numColumns = 12; //hardcoded because there will always be 12 months in a year
	_numRows = 1;
}

Matrix::Matrix(int h, int l)
{
	_numRows = h;
	_numColumns = l;

	_myArr = new double*[_numRows];

	for (int i = 0; i < _numRows; i++)
		_myArr[i] = new double[_numColumns];
}

Matrix::~Matrix()
{
	for (int i = 0; i < _numRows; i++)
		delete[] _myArr[i];
	delete[] _myArr;
}

std::string Matrix::displayFullTable()
{
	std::string sendBack = "";

	for (int i = 0; i < _numRows; i++)
	{
		for (int j = 0; j < _numColumns; j++)
			sendBack += std::to_string(_myArr[i][j]) + "\t";
		sendBack += "\n\n";
	}

	return sendBack;
}

void Matrix::operator = (const Matrix & copyFrom)
{
	_numRows = copyFrom._numRows;
	_numColumns = copyFrom._numColumns;

	_myArr = new double*[_numRows];

	for (int i = 0; i < _numRows; i++)
		_myArr[i] = new double[_numColumns];

	for (int i = 0; i < _numRows; i++)
		for (int j = 0; j < _numColumns; j++)
			_myArr[i][j] = copyFrom._myArr[i][j];
}

double Matrix::avgOfMonth(int monthIndex) //find average temperature of a month
{
	double average = 0;
	for (int i = 0; i < _numColumns; i++)
		average += _myArr[i][monthIndex];
	average = average / _numColumns;
	average = int(average * 100);
	average = average / 100;
	return average;
}

double Matrix::highestMonth(int monthIndex) //find highest temperature of a month
{
	double highestMonth = _myArr[0][monthIndex];
	for (int i = 0; i < _numRows; i++)
	{
		if (highestMonth < _myArr[i][monthIndex])
			highestMonth = _myArr[i][monthIndex];
	}
	return highestMonth;
}


double Matrix::avgOfyear(int yearIndex) //find average temperature of a year
{
	double average = 0;
	for (int i = 0; i < _numColumns; i++)
		average += _myArr[yearIndex][i];
	average = average / _numColumns;

	average = round(average * 100) / 100;
	//average = average / 100;

	return average;
}

double Matrix::highestInYear(int yearIndex) //find highest monthly temperature within a given year
{
	double highestYear = _myArr[yearIndex][0];
	for (int i = 0; i < _numColumns; i++)
	{
		if (highestYear < _myArr[yearIndex][i])
			highestYear = _myArr[yearIndex][i];
	}
	return highestYear;
}

double Matrix::monthTemp(int yearIndex, int monthIndex)
{
	return _myArr[yearIndex][monthIndex];
}
