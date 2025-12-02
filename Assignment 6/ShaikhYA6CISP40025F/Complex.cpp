/*
  Name: Yunus Shaikh
  Course: CISP 400 Object Oriented Programming in C++
  Assignment: A6 
  File: complex.cpp
  Purpose: Definitions of Complex class member functions and overloaded operators.
*/


// Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
using namespace std;

// Constructor
Complex::Complex( double realPart, double imaginaryPart ) 
   : real( realPart ),
   imaginary( imaginaryPart ) 
{ 
   // empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
      imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
      imaginary - operand2.imaginary );
} // end function operator-

// (a+bi) * (c+di) = (ac − bd) + (ad + bc)i
Complex Complex::operator*(const Complex& operand2) const {
    return Complex(real * operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real);
}

// (a+bi) / (c+di) = ((ac + bd)/(c² + d²)) + ((bc − ad)/(c² + d²)) i
Complex Complex::operator/(const Complex& operand2) const
{
	// Check for division by zero
    double denom = operand2.real * operand2.real + operand2.imaginary * operand2.imaginary;
    if (denom == 0.0) {
		std::cout << "infinite: ";     // print infinite message
		return Complex(0.0, 0.0); // return zero complex number
    }
	// Perform division
	// Return the result as a new Complex object
    return Complex((real * operand2.real + imaginary * operand2.imaginary) / denom,
        (imaginary * operand2.real - real * operand2.imaginary) / denom);
}

// equality operator 
bool Complex::operator==(const Complex& operand2) const
{
	// Compare real and imaginary parts
    if (real == operand2.real && imaginary == operand2.imaginary)
        return true;
    else
        return false;
}// end function operator==

// inequality operator
bool Complex::operator!=(const Complex& operand2) const
{
	// Compare real and imaginary parts
    if (real != operand2.real || imaginary != operand2.imaginary)
        return true;
    else
        return false;
} // end function operator!=

// assignment operator
Complex& Complex::operator=(const Complex& operand2)
{
	// Assign real and imaginary parts
    real = operand2.real;
	// Assign imaginary part
    imaginary = operand2.imaginary;
	// Return the current object
    return *this;
} // end function operator=

// output stream operator
ostream& operator<<(ostream& outstream, const Complex& output)
{
	// Output real part
	outstream << output.real;
	
	// Output imaginary part with appropriate sign
	if (output.imaginary >= 0)
		outstream << " + " << output.imaginary << 'i';
	else
		outstream << " - " << -output.imaginary << 'i';

	return outstream;
}

// input stream operator
istream& operator>>(istream& instream, Complex& input)
{
	// Read input in the format (a, b)
    char ch;
    instream >> ch;                  // read '('
    instream >> input.real;          // read first number
    instream >> ch;                  // read ',' 
    instream >> input.imaginary;     // read second number
    instream >> ch;                  // read ')'
    return instream;
}


