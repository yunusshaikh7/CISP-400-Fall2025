/*
  Name: Yunus Shaikh
  Course: CISP 400 Object Oriented Programming in C++
  Assignment: A5 Complex class I/O and operator overloading
  File: CISP400V10A5.cpp
  Purpose: Driver file for A5 project — tests the Complex class and
		   exercises operator overloads (>>, <<, +, -, *, /, ==, !=, =).
*/

#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	// create Complex objects
	Complex x;
	Complex y( 4.3, 8.2 );
	Complex z( 3.3, 1.1 );
	Complex k;
	Complex l;
	Complex m ( 0, 0.1 );

	// input Complex object k
	cout << "Enter complex number in the form: (a, b) for Complex objext k." << endl;
	cout << "<Performing >> operator overloading>" << endl << "? ";
	cin >> k; // use overloaded >> operator
	cout << endl << "The existing Complex object are:" << endl;
	cout << "<Performing << operator overloading>" << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "k: " << k << endl;
	cout << "l: " << l << endl;
	cout << "m: " << m << endl << endl;

	// + operator
	cout << "Performing +, = and << operators overloading." << endl;
	cout << "x = y + z:" << endl;
	x = y + z;
	cout << x << " = " << y << " + " << z << endl << endl;

	// - operator
	cout << "Performing -, = and << operators overloading." << endl;
	cout << "x = y - z:" << endl;
	x = y - z;
	cout << x << " = " << y << " - " << z << endl << endl;

	// * operator
	cout << "Performing *, = and << operators overloading." << endl;
	cout << "x = y * z:" << endl;
	x = y * z;
	cout << x << " = " << y << " * " << z << endl << endl;

	// / operator (normal)
	cout << "Performing /, = and << operators overloading." << endl;
	cout << "x = y / z:" << endl;
	x = y / z;
	cout << x << " = " << y << " / " << z << endl << endl;

	// / operator with divisor (0,0)
	cout << "Performing /, = and << operators overloading with divisor is (0, 0)." << endl;
	cout << "x = y / l:" << endl;
	// l is default-constructed as (0,0)
	x = y / l; // Complex::operator/ should handle division-by-zero
	cout << x << " = " << y << " / " << l << endl << endl;

	// / operator with divisor (0, 0.1) 
	cout << "Performing /, = and << operators overloading with divisor is (0, 0.1)." << endl;
	cout << "x = y / m:" << endl;
	x = y / m;
	cout << x << " = " << y << " / " << m << endl << endl;

	// == operator
	cout << "Performing != and << operators overloading." << endl;
	cout << "check x != k" << endl;
	if (x != k)
		cout << x << " != " << k << endl << endl;

	// = and == operators
	cout << "Performing =, == and << operators overloading." << endl;
	cout << "assign k to x and check x=k statement." << endl;
	cout << " check x == k" << endl;
	x = k;
	if (x == k)
		cout << x << " == " << k << endl << endl;

	cout << "Press enter to exit" << endl;
	cin.ignore();
	cin.get(); // waits for Enter
	return 0;
} // end main


