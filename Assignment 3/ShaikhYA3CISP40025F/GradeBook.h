/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: A3 – Gradebook
  File: Gradebook.h
  Purpose: Provide the GradeBook class interface used to count and report letter
           grades.
*/

//  GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initialize course name
   ~GradeBook(); // destructor
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void initializeData(); // initialize countGrades array to zero
   void displayMessage() const; // display a welcome message
   void inputGrades(); // input arbitrary number of grades from user
   void displayGradeReport() const;  // display report based on user input
   void displayInputs(); // display all the inputs entered by user
   double calculateGrade() const; // determine class average based on grades entered
private:
   std::string courseName; // course name for this GradeBook
   char letterGrades[100];
   int  countGrades[6];
}; // end class GradeBook  