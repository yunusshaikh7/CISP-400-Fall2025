/*
  Name: Yunus Shaikh
  Course: CISP 400 Object Oriented Programming in C++
  Assignment: A5 Complex class I/O and operator overloading
  File: complex.h
  Purpose: Complex class definition with overloaded operators.
*/

// Complex class definition.
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
   explicit Complex( double = 0.0, double = 0.0 ); // constructor
   Complex operator+( const Complex & ) const; // addition overload
   Complex operator-(const Complex&) const; // subtraction overload
   Complex operator*(const Complex&) const; // multiplication overload
   Complex operator/(const Complex&) const; // division overload
   bool operator==(const Complex&) const; // equality overload
   bool operator!=(const Complex&) const; // inequality overload
   Complex& operator=(const Complex&); // assignment overload
   

   // stream operators 
   friend std::ostream& operator<<(std::ostream& outstream, const Complex& output); // output overload
   friend std::istream& operator>>(std::istream& instream, Complex& input); // input overload 
private:
   double real; // real part
   double imaginary; // imaginary part
}; // end class Complex

#endif
