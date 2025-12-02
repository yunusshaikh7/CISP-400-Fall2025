/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: A1 – GradeBook modification
  File: GradeBook.cpp
  Purpose: Implement GradeBook class with instructorName support and the required
           formatted output for displayMessage().
*/



// GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName and instructorName with string supplied as argument
GradeBook::GradeBook(string course, string instructor)
	: courseName(course), instructorName(instructor) // member initializer to initialize courseName and instructorName
{                                                                      
   // empty body
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
   courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
    cout << "  " << "Welcome to the grade book for\n"
        << "   " << getCourseName() << "\n" "  "
        << "This course is presented by: " << instructorName << "\n\n";
} // end function displayMessage

void GradeBook::setInstructorName(string name) 
{ 
   instructorName = name; 
}
string GradeBook::getInstructorName() const 
{ 
   return instructorName; 
}

