/*-------------------------------------------------------------------------------
FILE NAME:      Polynomial.cpp
DESCRIPTION:    CS 202 - Project 2
USAGE:          ./poly_class              // Interactive mode
COMPILER:       GNU g++ compiler on Linux
NOTES:          Holds class overrides
Modification    History:
Author                  Date            Version
------------------      -----------     -----------
Christopher Zinser      2020-10-20      v1 Converted from Lab 5
						2020-10-21		v2 Added Addition, Subtraction, and multiplication
						2020-10-23		v2 Added Equality Testing
						2020-11-3		v3 Added Documentation
						2020-11-5		v4 Added Differentiation
-------------------------------------------------------------------------------*/
#include "Polynomial.h"

 /* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Polynomial class constructor
 RETURNS:           0
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
 Polynomial::Polynomial(){
	 degree = 0;
	
	for(int i = 0; i < ARRAY_SIZE(coef); i++)
		coef[i] = 0;

}
 /* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Polynomial overload constructor
 RETURNS:           0
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
 Polynomial::Polynomial(int* arr){
	degree = ARRAY_SIZE(coef);
	for(int i = 0; i < ARRAY_SIZE(coef) && i < ARRAY_SIZE(arr); i++)
		coef[i] = arr[i];

}
 /* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Polynomial copy constructor
 RETURNS:           0
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
Polynomial::Polynomial(const Polynomial &p1) {
	
	//cout<< "Inputted Poly: " << p1 << endl;
 	
	degree = p1.degree;
	
	for(int i = p1.degree; i>=0; i--){
		
			//cout<< p1.coef[i] << endl;
			coef[i] = p1.coef[i];
		
		
	}
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          ~Polynomial()
 DESCRIPTION:       Polynomial class deconstructor
 RETURNS:           0
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
Polynomial::~Polynomial() {
   

}


 /* -----------------------------------------------------------------------------
 FUNCTION:          +
 DESCRIPTION:       Operator overload for adding polynomials
 RETURNS:           Polynomial
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */

Polynomial Polynomial::operator + (const Polynomial &p1){
	
	Polynomial p2;
	
	
	p2.degree = MAX(degree,p1.degree);
	
	for(int i = p2.degree; i>=0; i--)
		p2.coef[i] = coef[i] + p1.coef[i];
	
	//cout<< "Exiting p2: " << p2 << endl;
	return p2;
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          -
 DESCRIPTION:       Polynomial class constructor
 RETURNS:           Polynomial
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
Polynomial Polynomial::operator - (const Polynomial &p1){
	
	Polynomial p2;
	
	
	p2.degree = MAX(degree,p1.degree);
	
	for(int i = p2.degree; i>=0; i--)
		p2.coef[i] = coef[i] - p1.coef[i];
	
	//cout<< "Exiting p2: " << p2 << endl;
	
	return p2;
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          *
 DESCRIPTION:       Polynomial class constructor
 RETURNS:           Polynomial
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
Polynomial Polynomial::operator * (const Polynomial &p1){
	
	Polynomial p2;
	
	
	p2.degree = degree+p1.degree;
	
	for(int i = degree; i>=0; i--){
		for(int j = p1.degree;j>=0;j--){
			
			p2.coef[i+j] += coef[i] * p1.coef[j];
		}
		
	}
	//cout<< "Exiting p2: " << p2 << endl;
	return p2;
}
Polynomial Polynomial::operator -- (int){
	
	Polynomial p2;
	
	int temp;
	temp = coef[degree];
	//p2.degree = degree+p1.degree;
	cout<< "Degree: "<< *this << endl;
	for(int i = degree; i>=0; i--){
			coef[i] = coef[i] * i;
	}
	for(int i = 0; i<=degree; i++){
		coef[i] = coef[i+1];
	}
	degree-=1;
	//cout<< "Exiting p2: " << p2 << endl;
	return p2;
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          =
 DESCRIPTION:       Polynomial class constructor
 RETURNS:           Polynomial
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
Polynomial Polynomial::operator = (const Polynomial &p1){
	
	Polynomial p2;
	//cout<< "Inputted Poly: " << p1 << endl;
 	
	degree = p1.degree;
	
	for(int i = p1.degree; i>=0; i--){
		
			//cout<< p1.coef[i] << endl;
			coef[i] = p1.coef[i];
		
		
	}
	//cout<<"Returning: "<< p2;
	return p2;
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          ()
 DESCRIPTION:       Evaluates a polynomial with an inputted value
 RETURNS:           double
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
double Polynomial::operator () (){
	
	double value = 0;
	double input;
	double mult=0;
	cout << "Enter the number you would like to evaluate: ";
	cin >> input;
	cout<<input;
	cout<< endl;
	for(int i = degree; i>=0; i--){
		
			
		
			value= pow(input,degree-(degree-i));
			mult += coef[i]*value;
		
		
	}
	return mult;
	
	
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          ==
 DESCRIPTION:       Compares Polynomials
 RETURNS:           boolean value of either 0 or 1
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
bool Polynomial::operator == (const Polynomial &p1){
	bool compare = true;
	Polynomial p2;
	
	

	if(degree!=p1.degree){
		
		compare = false;
	}
	
	for(int i = degree; i>=0; i--){
		
			
			if( coef[i] != p1.coef[i]){
				//cout<< coef[i] << "!="<< p1.coef[i]<<endl; 
					compare = false;
			}else{
				//cout<< coef[i] << "=="<< p1.coef[i]<<endl;
			}
		
		
	}

	return compare;
	

}
 /* -----------------------------------------------------------------------------
 FUNCTION:          <<
 DESCRIPTION:       Polynomial class output
 RETURNS:           n/a
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
ostream& operator << (ostream& os,const Polynomial &p1){
	static int n;
	
	//cout << "\nPolynomial #" << ++n << " is: ";

	for(int i =  p1.degree; i>= 0; i--){
		if(i < p1.degree){
			if(p1.coef[i] >= 0) os << " +";
			else os << " ";
		}
		os << p1.coef[i];

		if(i>1) os << "x^" << i;
		if(i==1) os << "x";

	}
	
}
 /* -----------------------------------------------------------------------------
 FUNCTION:          >>
 DESCRIPTION:       Polynomial class input
 RETURNS:           n/a
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
istream& operator >> (istream& is, Polynomial &p1){
	cout << "\nDegree of polynomial: ";
	is>> p1.degree;
	cout << "\n Enter " <<  p1.degree+1 << " coefficents: ";
	
	for(int i = p1.degree; i>=0; i--)
		is>> p1.coef[i];
}

