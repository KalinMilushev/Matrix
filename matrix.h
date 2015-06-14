#include <iostream>
#include "Complex.h"
using namespace std;
#pragma once

class Matrix
{
private:
	int m, n;
public:
	double **p;
	Matrix();
	Matrix(const int row_count, const int column_count);
	Matrix(const Matrix & a);
	~Matrix();
	double & operator()(const int r, const int c);
	double get(const int r, const int c) const;
	Matrix & operator=(const Matrix & a);
	Matrix & Add(const double v);
	Matrix & Subtract(const double v);
	Matrix & Multiply(const double v);
	Matrix & Divide(const double v);
	Matrix operator+(const Matrix& b);
	Matrix operator+(const double b);
	Matrix operator-(const Matrix& b);
	Matrix operator-(const double b);
	Matrix operator*(const Matrix& b);
	Matrix operator*(const double b);
	Matrix operator/(const Matrix& b);
	Matrix operator/(const double b);
	Matrix Minor(const int row, const int col) const;
	int Matrix::Size(const int i) const;
	int Matrix::GetRows() const;
	int Matrix::GetCols() const;
	Matrix Diag(const int n);
	Matrix Diag(const Matrix& v);
	double Det() const;
	void Swap(double& a, double& b);
	Matrix CoFactor();
	Matrix Adjoint();
	Matrix Transpose();
	Matrix Inverse();
	void accept();
	void display();
	void Matrix::CopyToFile();
};
