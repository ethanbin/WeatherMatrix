#pragma once

class Matrix
{
public:
	Matrix(int,int);
	~Matrix();
	void operator = (const Matrix &);
	//double monthAvg()


private:
	double **_myArr;
	int _length, _height;
};