/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: A3 – Gradebook
  File: Gradebook.cpp
  Purpose:Implements the GradeBook class functions from gradebook.h
*/


// GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D and F grades.
#include <iostream> // program uses cout and cin
#include <iomanip> // parameterized stream manipulators
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook( string name )
{
    cout << "The Grade Book constructor is called" << endl;
	setCourseName(name); // validate and store course name
	displayMessage(); // display welcome message
	initializeData(); // initialize countGrades array to zero

	cout << "*****The end of Grade Book Constructor.*****\n\n\n";
} // end GradeBook constructor

// GradeBook destructor
GradeBook::~GradeBook()
{
    cout << "Destructor is called" << endl << endl;
}

// function to set the course name; limits name to 30 or fewer characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 30 ) // if name has 30 or fewer characters
      courseName = name; // store the course name in the object
   else // if name is longer than 30 characters
   { // set courseName to first 30 characters of parameter name
      courseName = name.substr( 0, 30); // select first 30 characters
      cerr << "        Name \"" << name << "\"" << endl << "        exceeds maximum length(30).\n\n"
         << "        Limiting courseName to first 30 characters.\n" << endl;
   } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
   return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "        Welcome to the grade book for\n" << "        " << getCourseName() << "!\n"
      << endl;
} // end function displayMessage

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades() 
{
   int grade; // grade entered by user
   int index = 0;

   cout << "        Enter letter grades." << endl
      << "        Or Enter the EOF character to end input." << endl
       << "        (Use Ctl + D, or Ctl + Z)" << endl;

   // loop until user types end-of-file key sequence
   while ( ( grade = cin.get() ) != EOF )
   {
      // determine which grade was entered
      switch ( grade ) // switch statement nested in while
      {
		 // increment appropriate counter
		 // note that cases fall through when no break statement

         case 'A': // grade was uppercase A
         case 'a': // or lowercase a
             cout << "\n        Enter letter grades." << endl
             << "        -->     Or Enter the EOF character to end input." << endl
             << "        (Use Ctl + D, or Ctl + Z)" << endl;
			 ++countGrades[0]; // increment countGrades[0]
			 letterGrades[index++] = grade; // store valid entry
            break; // necessary to exit switch

         case 'B': // grade was uppercase B
         case 'b': // or lowercase b
             cout << "\n        Enter letter grades." << endl
                 << "        -->     Or Enter the EOF character to end input." << endl
                 << "        (Use Ctl + D, or Ctl + Z)" << endl;
			 ++countGrades[1]; // increment countGrades[1]  
             letterGrades[index++] = grade;
            break; // exit switch

         case 'C': // grade was uppercase C
         case 'c': // or lowercase c
             cout << "\n        Enter letter grades." << endl
                 << "        -->     Or Enter the EOF character to end input." << endl
                 << "        (Use Ctl + D, or Ctl + Z)" << endl;
            ++countGrades[2]; // increment countGrades[2]   
            letterGrades[index++] = grade;
            break; // exit switch

         case 'D': // grade was uppercase D
         case 'd': // or lowercase d
             cout << "\n        Enter letter grades." << endl
                 << "        -->     Or Enter the EOF character to end input." << endl
                 << "        (Use Ctl + D, or Ctl + Z)" << endl;
            ++countGrades[3]; // increment countGrades[3]   
            letterGrades[index++] = grade;
            break; // exit switch

         case 'F': // grade was uppercase F
         case 'f': // or lowercase f
             cout << "\n        Enter letter grades." << endl
                 << "        -->     Or Enter the EOF character to end input." << endl
                 << "        (Use Ctl + D, or Ctl + Z)" << endl;
            ++countGrades[4]; // increment countGrades[4]  
            letterGrades[index++] = grade;
            break; // exit switch

         case '\n': // ignore newlines,  
         case '\t': // tabs, 
         case ' ': // and spaces in input
            break; // exit switch

         default: // catch all other characters
			 // add 1 to error count
             ++countGrades[5];
			 // store incorrect entry
             letterGrades[index++] = grade;
             cout << "        XXXX Incorrect letter grade entered XXXX\n"
				 << "        \"" << static_cast<char>(grade) << "\"" << " is not a proper letter grade." << endl; // display error message
             cout << "\n        Enter letter grades." << endl
                 << "        -->     Or Enter the EOF character to end input." << endl
                 << "        (Use Ctl + D, or Ctl + Z)" << endl << endl;
 
            break; // optional; will exit switch anyway
      } // end switch
   } // end while
} // end function inputGrades

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
	// display number of students that received each grade
	int numOfStudents = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4];
	// calculate total number of grades entered
	int numOfData = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] + countGrades[5];

	// display summary of results
	cout << "\n\nThe total number of data entered is " << numOfData << endl;
    cout << "The total number of student receive grades is entered is " << numOfStudents << endl;
	cout << "The number of students who recieved each letter grade: " << endl;
	cout << "A:       " << countGrades[0] << endl; // display number of A grades
	cout << "B:       " << countGrades[1] << endl; // display number of B grades
	cout << "C:       " << countGrades[2] << endl; // display number of C grades
	cout << "D:       " << countGrades[3] << endl; // display number of D grades
	cout << "F:       " << countGrades[4] << endl; // display number of F grades
	cout << "Error:   " << countGrades[5] << endl;
    std::cout << std::fixed << std::setprecision(1);

	// display class average of all grades entered
    cout << "\nThe class average is " << calculateGrade() << endl << endl;

} // end function displayGradeReport

void GradeBook::displayInputs() 
{
    cout << "\n\nThe data entered is listed at the following:" << endl;

	// calculate total number of grades entered
    int numOfData = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] + countGrades[5];
    int columns = 4;
    int count = 0;
	// display all the inputs entered by user
	// display each grade in rows of four columns
    for (int i = 0; i < numOfData; ++i) {

        cout << "[" << i << "] -> " << (char)toupper(letterGrades[i]);
        ++count;
		// create a new line after every fourth grade
        if (count % columns == 0)
            cout << endl;
        else
			cout << "\t"; // tab space between columns
    }

} // end 

void GradeBook::initializeData()
{
	// initialize countGrades array to zero
	int nLetters = sizeof(countGrades) / sizeof(countGrades[0]); // number of elements in countGrades array

	// set each element of array countGrades to 0
    for (int i = 0; i < nLetters; ++i) {
        countGrades[i] = 0;
    }
	int numOfStudents = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4]; // total number of students
	int numOfData = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] + countGrades[5]; // total number of data entered

	cout << "The Grade Book, " << getCourseName() << ", contains" << endl;

	// display summary of results
	cout << "\n\nThe total number of data entered is "<< numOfData << endl;
    cout << "The total number of student receive grades is entered is " << numOfStudents << endl;
	cout << "The number of students who recieved each letter grade:" << endl;
	cout << "A:       " << countGrades[0] << endl; // display number of A grades
	cout << "B:       " << countGrades[1] << endl; // display number of B grades
	cout << "C:       " << countGrades[2] << endl; // display number of C grades
	cout << "D:       " << countGrades[3] << endl; // display number of D grades
	cout << "F:       " << countGrades[4] << endl; // display number of F grades
	cout << "Error:   " << countGrades[5] << endl;
    std::cout << std::fixed << std::setprecision(1);

	// display class average of all grades entered
    cout << "\nThe class average is " << calculateGrade() << endl << endl;
} // end function initializeData

double GradeBook::calculateGrade() const
{
	// calculate class average based on grades entered
	int numOfStudents = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4];
    int totalPoints = 0;
    double gpa;

	// avoid division by zero
    if (numOfStudents == 0) {
        gpa = 0.0;
	}
	// calculate GPA
    else {
		totalPoints += countGrades[0] * 4; // A = 4 points
		totalPoints += countGrades[1] * 3; // B = 3 points
		totalPoints += countGrades[2] * 2; // C = 2 points
		totalPoints += countGrades[3] * 1; // D = 1 point
		totalPoints += countGrades[4] * 0; // F = 0 points
		gpa = (double)totalPoints / numOfStudents; // GPA = total points / number of students
	}

    return gpa;
} // end function calculateGrade


