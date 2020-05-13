#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>  
#include <fstream>
#include <string.h>
using namespace std;

class complex {

	//declare the two private variables real and imaginary number
private:
	double real, imag;
	
public:
	//constructors
	complex();					 //default -- no argument
	complex(double x);           //1 argument
	complex(double x, double y); //2 arguments

	//method functions
	double getReal() const;
	double getImaginary() const;

	//Math operators
	complex operator+(const complex& complex) const;    //addition
	complex operator-(const complex& complex) const;	//subtraction
	complex operator*(const complex& complex) const;	//multiply
	complex operator/(const complex& complex) const;	//division

	//Conjugate
	complex conjugate();		//conjugate flip the sign for imag part

	//Comparison
	bool operator==(const complex& complex) const;
	bool operator!=(const complex& complex) const;

	//Assignment operator
	complex& operator+=(const complex& complex);
	complex& operator-=(const complex& complex);
	complex& operator*=(const complex& complex);
	complex& operator/=(const complex& complex);


	//Stream I/O 
	friend ostream& operator<<(ostream& outStream, const complex& c);
	friend istream& operator>>(istream& inStream, complex& c);	
};

#endif