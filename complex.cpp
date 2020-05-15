//Author : Aashima Mehta
//Complex functions
#include "complex.h"
#include <iostream>
using namespace std;

//------------------------Complex-----------------------
//Constructors
complex::complex(){
	this->real = 0.0;
	this->imag = 0.0;
}
complex::complex(double x) {
	this->real = x;
	this->imag = 0.0;
}
complex::complex(double x, double y) {
	this->real = x;
	this->imag = y;
}

//Method functions

double complex::getReal() const{
	return this->real;
}

double complex::getImaginary() const{
	return this->imag;
}

//Math operations +, -, *, /

complex complex::operator+(const complex& c) const {
	complex sum;
	sum.real = this->real + c.real;
	sum.imag = this->imag + c.imag;
	return sum;
}
complex complex::operator-(const complex& c) const {
	complex sub;
	sub.real = this->real - c.real;
	sub.imag = this->imag - c.imag;
	return sub;
}
complex complex::operator*(const complex& c) const {
	complex mul;
	mul.real = (c.real * this->real) - (c.imag * this->imag);
	mul.imag = (c.imag * this->real) + (c.real * this->imag);
	return mul;
}
complex complex::operator/(const complex& c) const {
	complex div;
	if (((c.real * c.real) + (c.imag * c.imag)) != 0) 
		
	{
		div.real = ((this->real * c.real) + (this->imag * c.imag)) / ((c.real * c.real) + (c.imag * c.imag));
		div.imag = ((this->imag * c.real)-(this->real * c.imag)) / ((c.real * c.real)+(c.imag * c.imag));
	}
	else {
		cout << "Error: Cannot divide by zero" << endl;
		div = 0;
	}
	return div;
}

//Conjugate Method
complex complex::conjugate() {
	complex conj;
	conj.real = this->real;
	conj.imag = this->imag * (-1);
	return conj;
}

//Comparison functions == and !=

bool complex::operator==(const complex& c) const {
	if (this->real == c.real && this->imag == c.imag)
		return true;
	return false;
}
bool complex::operator!=(const complex& c) const {
	return !(*this == c);
}

//Assignment operations +=, -=, *=, /=

complex& complex::operator+=(const complex& c) { // c3 += c5 ---> c3 = c3 + c5
	complex mul;
	*this = *this + c;
	//*this = mul;
	cout << *this;
	return *this; 
}
complex& complex::operator-=(const complex& c) {
	complex sub;
	sub = *this - c;
	*this = sub;
	return *this;
}
complex& complex::operator*=(const complex& c) {
	complex mul;
	mul = *this * c;
	*this = mul;
	return *this;
}
complex& complex::operator/=(const complex& c){
	complex div;
	if (c.real != 0 && this->real != 0 &&
		c.imag != 0 && this->imag != 0)
	{
		div = *this / c;
		*this = div;
	}
	else {
		cout << "Error: Cannot divide by zero" << endl;
		div = 0;
	}
	return *this;
}

//Stream I/O operators

ostream& operator<<(ostream& ostr, const complex& c) {
	//when real == 0
	if (c.getReal() == 0 && c.getImaginary() == 1)
		ostr << "i" << endl;
	//when real != 0 and imaginary == 1
	else if (c.getReal() != 0 && c.getImaginary() == 1)
		ostr << c.getReal() << "+i" << endl;
	else if (c.getReal() != 0 && c.getImaginary() == -1)
		ostr << c.getReal() << "-i" << endl;
	else if (c.getReal() == 0 && c.getImaginary() == -1)
		ostr << "-i" << endl;
	else if (c.getReal() == 0 && c.getImaginary() == 1)
		ostr << "i" << endl;
	//when both of them are zero
	else if (c.getReal() == 0 && c.getImaginary() == 0)
		ostr << 0 << endl;
	//when getIMAG is negative
	else if (c.getReal() != 0 && (c.getImaginary() < 0))
		ostr << c.getReal() << c.getImaginary() << "i" << endl;
	//when its a regular postive function
	else if (c.getReal() != 0 && c.getImaginary() != 0 && c.getImaginary() != 1)
		ostr << c.getReal() << "+" << c.getImaginary() << "i" << endl;
	//when real != 0
	else if(c.getReal() == 0 && c.getImaginary() != 0 && c.getImaginary() != 1)
		ostr << c.getImaginary() << "i" << endl;
	else if (c.getReal() != 0 && (c.getImaginary() == 0))
		ostr << c.getReal() << endl;
	return ostr;
}

istream& operator>>(istream& istr, complex& c) {
	return istr >> c.real >> c.imag;
}

