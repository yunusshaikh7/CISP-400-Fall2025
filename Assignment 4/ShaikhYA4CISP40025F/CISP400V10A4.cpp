/*
  Name: Yunus Shaikh
  Course: CISP 400 	6 Object Oriented Programming in C++
  Assignment: A4 	6 Date/Time composition and tick
  File: CISP400V10A4.cpp
  Purpose: Driver file for A4 project which creates a Date object
		   composed of a Time object and calls tick to increment time
		   and date.
*/

// CISP400V10A4.cpp
#include <iostream> 
using std::cout; 
using std::endl; 

#include "Time.h" // include Time class definition
#include "Date.h" // include Date class definition

const int MAX_TICKS = 30000;

int main()
{
	Time t(23, 59, 58);// create a time object

  Date d(12, 31, 2024, t); // create date object

   // output Time object t's values 
   for ( int ticks = 1; ticks < MAX_TICKS; ++ticks ) 
   {
      d.print(); // invokes print 
	  cout << endl;
      d.tick(); // invokes function tick
   } // end for
   d.~Date();// call Date destructor
system("PAUSE");
   return 0;
} // end main
