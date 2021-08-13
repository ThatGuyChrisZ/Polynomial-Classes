/*-------------------------------------------------------------------------------
FILE NAME:      Polynomial.h
DESCRIPTION:    CS 202 - Project 2
USAGE:          ./poly_class               // Interactive mode
COMPILER:       GNU g++ compiler on Linux
NOTES:          Header file for project 2
Modification    History:
Author                  Date            Version
------------------      -----------     -----------
Christopher Zinser      2020-10-20      v1 Converted from Lab 5
						2020-10-21		v2 Added Addition, Subtraction, and multiplication
						2020-10-23		v2 Added Equality Testing
						2020-11-3		v3 Added Documentation
						2020-11-5		v4 Added Differentiation
-------------------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

class Polynomial										//Polynomial class definition
{
	private:
		int degree;										//Degree of the polynomial
		int coef[9];									//Array of coefficents
	public:
		Polynomial();
		~Polynomial();
		Polynomial(const Polynomial &p1);
		Polynomial(int*);
		Polynomial operator + (const Polynomial &);		// Overload + operator
		Polynomial operator - (const Polynomial &);		// Overload - operator
		Polynomial operator * (const Polynomial &);		// Overload * operator
		Polynomial operator = (const Polynomial &);	
		Polynomial operator -- (int);	
		// Overload = operator
		double operator () ();
		bool operator == (const Polynomial &);
		friend ostream& operator << (ostream& ,const Polynomial &);
		friend istream& operator >> (istream&, Polynomial &);

};

#endif


