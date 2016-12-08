#pragma once
#include<fstream>
#include<iostream>
//using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int,int);
	~Matrix();

	std::string testProperReadin();

	void operator = (const Matrix &);
	friend std::istream &operator >> (std::istream  &input, Matrix &M) {
		if (M._columnCount == M._length || M._rowCount == M._height)
			throw("Istream operator input exceeded Matrix bounds");

		input >> M._myArr[M._rowCount][M._columnCount];
		M._columnCount++;
		if (M._columnCount % 12 == 0)
		{
			M._rowCount++;
			M._columnCount = 0;
		}

		return input;
	}

private:
	double **_myArr;
	int _length, _height;
	int _columnCount = 0, _rowCount = 0;

public:
	int length() const { return _length;}
	int column() const { return _length; }

	int height() const { return _height; }
	int row() const { return _height;}
};