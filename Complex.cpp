#include "Complex.h"

Complex::Complex()
{
	a = 0;
	b = 0;
}
Complex::~Complex()
{
}
Complex::Complex(double A, double B)
{
	a = A;
	b = B;
}
double Complex::getA()
{
	return a;
}
double Complex::getB()
{
	return b;
}
void Complex::setA(double A)
{
	a = A;
}
void Complex::setB(double B)
{
	b = B;
}
Complex Complex::operator+(const Complex & p) const
{
	return Complex(this->a + p.a, this->b + p.b);
}
Complex Complex::operator-(const Complex & p) const
{
	return Complex(this->a - p.a, this->b - p.b);
}
Complex Complex::operator*(double number) const
{
	return Complex(this->a*number, this->b*number);
}
Complex Complex::operator*(const Complex & p) const
{
	double temp1;
	double temp2;
	temp1 = this->a*p.a - this->b*p.b;
	temp2 = this->b*p.a + this->a*p.b;
	return Complex(temp1, temp2);
}
Complex Complex::operator/(const Complex & p) const
{
	double temp1;
	double temp2;
	temp1 = (this->a*p.a + this->b*p.b) / (this->a*this->a + p.b*p.b);
	temp2 = (this->b*p.a - this->a*p.b) / (this->a*this->a + p.b*p.b);
	return Complex(temp1, temp2);
}
std::istream & operator>>(std::istream & iStream, Complex & number)
{
	iStream >> number.a >> number.b;
	return iStream;
}
std::ostream & operator<<(std::ostream & oStream, const Complex & number)
{
	oStream << number.a << " " << number.b <<"i" ;
	return oStream;
}
