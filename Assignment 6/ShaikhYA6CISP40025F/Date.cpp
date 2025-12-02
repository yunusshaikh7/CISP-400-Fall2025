/*
  Name: Yunus Shaikh
  Course: CISP 400 	6 Object Oriented Programming in C++
  Assignment: A6
  File: Date.cpp
  Purpose: Implements the Date class functions (constructor, destructor,
           print, tick, increaseADay, checkDay). 
*/

// Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mn, int dy, int yr)
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
                 
} // end Date constructor

// print Date object in form month/day/year and time in both formats
void Date::print() const
{
   // Print date then standard and universal time; tabs used for alignment
   cout << month << '/' << day << '/' << year << '\t';
} // end function print

// tick advances the composed Time object by one second. When the time
// rolls past 23:59:59 it resets the hour to 0 and advances the date by one day.
void Date::tick()
{
    increaseADay();
}


// output Date object to show when its destructor is called
Date::~Date()
{ 
   // Print a message then the date/time on the same line
} // end ~Date destructor

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay( int testDay ) const
{
   static const array< int, monthsPerYear + 1 > daysPerMonth = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // February 29 check for leap year 
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 || 
      ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   throw invalid_argument( "Invalid day for current month and year" );
} // end function checkDay

/* increase the stored date by one day, adjusting month and year as necessary */
void Date::increaseADay()
{
    // Days per month for a non-leap year; index 0 unused to allow 1-based months
    static const array< int, monthsPerYear + 1 > daysPerMonth =
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Determine how many days are in the current month.
    // Use an int for easy arithmetic; will compare to unsigned `day` later.
    int daysThisMonth = daysPerMonth[ month ];

    // If February, apply leap-year rules to potentially add one day.
    // Leap year if divisible by 400, or divisible by 4 but not by 100.
    if ( month == 2 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) ) {
        ++daysThisMonth;
    }

    // Advance to the next day.
    ++day;

    // If we've advanced past the last day of the month, roll over.
    if ( day > static_cast< unsigned int >( daysThisMonth ) ) {
        // Informational message showing the overflow and reset behavior.
        cout << "day (" << day << ") set to 1." << endl;

        // Reset day to the first of the next month.
        day = 1;

        // If not December, just advance the month.
        if ( month < monthsPerYear ) {
            ++month;
        }
        else {
            // If December, roll over to January and increment the year.
            month = 1;
            ++year;
        }
    }
}

ostream& operator<<(ostream& outstream, const Date& output)
{
    // Array of month names
    static const array<string, 13> monthNames = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Output in format: Month day, year
    outstream << monthNames[output.month] << " " << output.day << ", " << output.year;

    return outstream;
}

bool Date::operator==(const Date& date2) const
{
    // Compare real and imaginary parts
    if (day == date2.day && month == date2.month && year == date2.year)
        return true;
    else
        return false;
}// end function operator==