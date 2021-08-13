/*-------------------------------------------------------------------------------
FILE NAME:      poly_class
DESCRIPTION:    CS 202 - Project 2
USAGE:          ./poly_class              // Interactive mode
COMPILER:       GNU g++ compiler on Linux
NOTES:          This file contains the programs driver 
Modification    History:
Author                  Date            Version
------------------      -----------     -----------
Christopher Zinser      2020-10-20      v1 Converted from Lab 5
						2020-10-21		v2 Added Addition, Subtraction, and multiplication
						2020-10-23		v2 Added Equality Testing
						2020-10-25		v3 Optimized a bit. Same functionality with more efficent code
						2020-11-3		v3 Added Documentation
						2020-11-5		Added Differentiation
-------------------------------------------------------------------------------*/
#include "Polynomial.h"

const char PROGRAMMER_NAME[] = "Christopher Zinser"; 
 /* -----------------------------------------------------------------------------
 FUNCTION:          main()
 DESCRIPTION:       The programs driving function
 RETURNS:           0
 NOTES:             Optional notes on this function
 ------------------------------------------------------------------------------- */
int main()
{
	Polynomial poly[3];
	for (int n = 0; n<2; n++){
		cin>>poly[n];
		
		cout<< poly[n];

	}
	cout<<endl<<endl <<"Copy Constructor Test: ";
	Polynomial poly2 = poly[0];
	cout<< poly2 ;
	
	cout<< "\nAdding 2 Polynomials: "<<endl;
	poly[2] = poly[0] + poly[1];
	cout<< poly[2];
	cout<< "\nSubtracting 2 Polynomials: "<<endl;
	poly[2] = poly[0] - poly[1];
	cout<< poly[2];
	cout<< "\nMultiplying 2 Polynomials: "<<endl;
	poly[2] = poly[0] * poly[1];
	cout<< poly[2];
	

	
	
	cout<< "\nTesting Equality: "<<endl;
	if(poly[0]==poly[1]){
		cout <<"The Polonomials are equal" << endl;
	}
	poly[2]--;
	cout<<"Differentiated Equation: "<<poly[2] <<endl;
	cout<< "Evaluating poly[0]: " << poly[0]() << endl;
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";cout << __DATE__ << "  " __TIME__ << endl;cout << endl;
	cout<< endl;
	
	return 0;
}
 