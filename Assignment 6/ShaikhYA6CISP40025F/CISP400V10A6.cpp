/*
  Name: Yunus Shaikh
  Course: CISP 400 	6 Object Oriented Programming in C++
  Assignment: A6
  File: CISP400V10A6.cpp
  Purposse: Test the function template isEqualTo with various data types
		   including int, char, double, Complex class, string class, and Date class.
*/

// CISP400V10A6.cpp
#include <iostream> 
#include <string>
using std::cout; 
using std::endl; 

#include "Complex.h" // include Time class definition
#include "Date.h" // include Date class definition

// function template to determine whether two values are equal
template <typename T> // function template header
bool isEqualTo(const T& first, const T& second)
{
	// display the values being compared
	cout << first << " and " << second;
	// determine and display whether values are equal
	if (first == second)
	{
		// values are equal
		cout << " are equal" << endl;
		return true;
	}
	else
	{
		// values are not equal
		cout << " are \"NOT\" equal" << endl;
		return false;
	}
}

int main()
{
	// test isEqualTo with integers
	cout << "*** Integers Tests ***" << endl;
	cout << "Integers: "; isEqualTo(1, 1); 
	cout << "Integers: "; isEqualTo(2, 4);
	cout << "Integers: "; isEqualTo(-1, 1);
	cout << "Integers: "; isEqualTo(-1, -1);
	cout << endl;

	// test isEqualTo with chars
	cout << "*** Chars Tests ***" << endl;
	cout << "Characters: "; isEqualTo('a', 'a');
	cout << "Characters: "; isEqualTo('a', 'c');
	cout << "Characters: "; isEqualTo('c', 'a');
	cout << "Characters: "; isEqualTo('c', 'c');
	cout << endl;

	// test isEqualTo with doubles
	cout << "*** Double Tests ***" << endl;
	cout << "Double numbers: "; isEqualTo(2.2, 2.2);
	cout << "Double numbers: "; isEqualTo(2.2, 2.3);
	cout << "Double numbers: "; isEqualTo(-2.2, 2.2);
	cout << "Double numbers: "; isEqualTo(-2.2, -2.2);
	cout << endl;

	// test isEqualTo with Complex class objects
	cout << "*** Complex Tests ***" << endl;
	cout << "Class objects: "; isEqualTo(Complex(10, 5), Complex(10, 5));
	cout << "Class objects: "; isEqualTo(Complex(10, 5), Complex(10, 54));
	cout << "Class objects: "; isEqualTo(Complex(10, -5), Complex(10, 5));
	cout << "Class objects: "; isEqualTo(Complex(-10, -5), Complex(-10, -5));
	cout << endl;

	// test isEqualTo with string class objects
	cout << "*** String Tests ***" << endl;
	cout << "String objects: "; isEqualTo(std::string("abcdefg"), std::string("abcdefg"));
	cout << "String objects: "; isEqualTo(std::string("abcdefg"), std::string("abcdefh"));
	cout << "String objects: "; isEqualTo(std::string("-abcdefg"), std::string("abcdefg"));
	cout << "String objects: "; isEqualTo(std::string("-abcdefg"), std::string("-abcdefg"));
	cout << endl;

	// test isEqualTo with Date class objects
	cout << "*** Date Tests ***" << endl;
	cout << "Date objects: "; isEqualTo(Date(2, 1, 2017), Date(2, 1, 2017));
	cout << "Date objects: "; isEqualTo(Date(2, 13, 2017), Date(2, 14, 2017));
	cout << "Date objects: "; isEqualTo(Date(1, 13, 2017), Date(2, 13, 2017));
	cout << "Date objects: "; isEqualTo(Date(1, 13, 2017), Date(1, 13, 2017));
	cout << endl;

	// pause program before end
	system("PAUSE");
   return 0;
} // end main
