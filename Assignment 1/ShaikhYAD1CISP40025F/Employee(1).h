/*
  Name: Yunus Shaikh
  Course: CISP 400 – Object Oriented Programming in C++
  Assignment: AD1 – Employee Salary
  File: Employee.h
  Purpose: Purpose: Declaration of the Employee class for AD1. This file specifies the interface for Employee objects, 
  including data members for employee details and function prototypes for salary management and adjustments.
*/


// Employee.h
// Employee class definition. This file presents Employee's public 
// interface without revealing the implementations of Employee's member
// functions, which are defined in Employee.cpp.
#include <string> // class Employee uses C++ standard string class

// Employee class definition
class Employee
{
public:
    explicit Employee(std::string firstName, std::string lastName, int monthlySalary); // constructor initialize data members
    void setFirstName(std::string firstName); // sets the first name
    std::string getFirstName() const; // gets the first name
    void setLastName(std::string lastName);  // sets the last name
    std::string getLastName() const; // retrieves the last name
    void setMonthlySalary(int monthlySalary); // sets the monthly salary
    int getMonthlySalary() const; // gets the monthly salary
    void increaseMonthlySalary(int percent); // function to increase the monthly salary
private:
    std::string firstName;
    std::string lastName;
    int monthlySalary;
}; // end


