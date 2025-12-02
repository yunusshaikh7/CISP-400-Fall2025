/*
  Name: Yunus Shaikh
  Course: CISP 400 	6 Object Oriented Programming in C++
  Assignment: A6
  File: Date.h
  Purpose: Declares the Date class which stores month/day/year and a
           composed Time object. 
*/

// Date.h 
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H


class Date 
{
public:
   static const unsigned int monthsPerYear = 12; // months in a year
   explicit Date(int = 1, int = 1, int = 1900); // default constructor
   void print() const; // print date in month/day/year format and time
   void tick(); // increment the time stored in this Date by one second
   ~Date(); // provided to confirm destruction order

   friend std::ostream& operator<<(std::ostream& outstream, const Date& output); // output overload
   bool operator==(const Date&) const; // equality overload
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year

   // utility function to check if day is proper for month and year
   unsigned int checkDay( int ) const; 


   // advance the date by one day (adjust month/year as needed)
   void increaseADay();
}; // end class Date

#endif
