/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: A1 – GradeBook modification
  File: GradeBook.h
  Purpose: Add instructorName member; provide set/get; modify constructor to accept
           course and instructor; update displayMessage per assignment.
*/


// GradeBook.h
// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook(std::string courseName, std::string instructorName); // constructor initialize courseName and instructorName
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void setInstructorName(std::string name);  // sets the instructor name
   std::string getInstructorName() const; // retrieves the instructor name
   void displayMessage() const; // displays a welcome message
private:
   std::string courseName; // course name for this GradeBook
   std::string instructorName;
}; // end class GradeBook  


