/*
  Name: Yunus Shaikh
  Course: CISP 400 	6 Object Oriented Programming in C++
  Assignment: A4 	6 Date/Time composition and tick
  File: Date.h
  Purpose: Declares the Date class which stores month/day/year and a
           composed Time object. 
*/

// Date.h 
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H

#include "Time.h" // composition: Date now contains a Time object

class Date 
{
public:
   static const unsigned int monthsPerYear = 12; // months in a year
   explicit Date(int = 1, int = 1, int = 1900, const Time & = Time()); // default constructor
   void print() const; // print date in month/day/year format and time
   void tick(); // increment the time stored in this Date by one second
   ~Date(); // provided to confirm destruction order
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year

   // utility function to check if day is proper for month and year
   unsigned int checkDay( int ) const; 

   Time currentTime; // composition: Time object stored inside Date

   // advance the date by one day (adjust month/year as needed)
   void increaseADay();
}; // end class Date

#endif
