#include <iostream>
#pragma once
using namespace std;

class Complex
{
private:
	double a;
	double b;
public:
	Complex();
	Complex(double A, double B);
	~Complex();
	double getA();
	double getB();
	void setA(double A);
	void setB(double B);
	Complex operator+(const Complex & p) const;
	Complex operator-(const Complex & p) const;
	Complex operator*(double number) const;
	Complex operator*(const Complex & p) const;
	Complex operator/(const Complex & p) const;
	friend std::istream & operator>>(std::istream & iStream, Complex & number);
	friend std::ostream & operator<<(std::ostream & oStream, const Complex & number);

};

